#ifndef DENSE_MATRIX_H
#define DENSE_MATRIX_H

#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <cmath>

#include <Matrix.h>

using std::vector;
using std::string;
using std::endl;
using std::cout;

template <typename T>
class DenseMatrix : public Matrix<T>{
    private:

        vector<vector<T>> cells_;
        std::pair<int, int> shape_;

    public:

        /**
         * Initializes the Matrix with a vector of vector of cells
         * -Provided data must allow the creation of a matrix with
         * at least one row and a column, otherwise throw
         * std::invalid_argument
         * -if vector rows have different length, throws
         * std::invalid_argument
        */

        DenseMatrix(const vector<vector<T>>& values) : Matrix<T>(values){
            
            if(values.size() == 0){
                throw std::invalid_argument("Must have at least one row!");
            }

            if(values[0].size() == 0){
                throw std::invalid_argument("Must have at least one column!");
            }

            int prev = -1;
            for(const vector<T>& v: values){
                if(prev == -1){
                    prev = v.size();
                } else {
                    if(prev != v.size()){
                        throw std::invalid_argument("Found rows of different lenght!");
                    }
                }
            }
            
            this->cells_ = values;
            this->shape_ = std::pair<int, int>(values.size(), values[0].size());
        }

        /**
         * Initializes the Matrix with four arguments:
         * - number of rows
         * - number of columns
         * - an array of cell triplets (row_index,col_index,value)
         * - size of the trplets
         * If number of rows or columns is less than indeces found
         * in triplets, throw std::invalid_argument
         * Provided data must allow the creation of a matrix with
         * at least one row and a column, otherwise throw
         * std::invalid_argument
        */

        DenseMatrix( const int n, const int m, const Triplet<T> triplets[], const int triplets_size) : 
                                                            Matrix<T>(n, m, triplets, triplets_size) {
            if(triplets_size <= 0){
                throw std::invalid_argument("Expected a non empty list of triplets!");
            }
            if(n < 1){
                throw std::invalid_argument(string("Expected a strictly positive n! Found") + std::to_string(n));
            }
            if(m < 1){
                throw std::invalid_argument(string("Expected a strictly positive m! Found") + std::to_string(m));
            }

            this->cells_.resize(n);
            for(int i = 0; i < n; i++){
                this->cells_[i].resize(m);
            }

            for(int k = 0; k < triplets_size; k++){
                const Triplet<T>& t = triplets[k];
                if(t.row >= n){
                    throw std::invalid_argument("Found triplets with row index exceeding the declared one!");
                }
                if(t.col >= n){
                    throw std::invalid_argument("Found triplets with column index exceeding the declared one!");
                }
                this->cells_[t.row][t.col] = t.value;
            }
            this->shape_ = std::pair<int, int>(n, m);
        }

        /** 
         * RETURN a nice human-readable formatted string, when POSSIBLE
         * like this:
         * Matrix { {5,2,6,3},
         * {8,4,7,4},
         * {2,1,9,8} }
         * - substitute Matrix with the descendant class name
         * - NOTE: sometimes this representation is impractical
         * (i.e. sparse matrices
         * with large n/m), in that case use another format
         * of your choice
        */

        virtual string as_string() const {
            std::stringstream ss = std::stringstream();
            ss << "DenseMatrix {";

            for(int i = 0; i < this->shape().first; i++){
                if(i > 0){
                    ss << ",";
                }
                ss << endl << " {";
                for(int j = 0; j < this->shape().second; j++){
                    if(i > 0){
                        ss << ",";
                    }
                    ss << this->cells_[i][j];
                }
                ss << "}";
            }
            ss << endl << "}";
            return ss.str();
        }

        /**
         * RETURN the number of rows and columns as a std::pair
        */

        virtual std::pair<int,int> shape() const {
            return this->shape_;
        }

        /**
         * Overrides default round parenthesis access behaviour when
         * *reading*
         * my_mat(2,5) to access element at row 2 and column 5
         * - on wrong indeces, throw std::out_of_bounds exception
        */

        virtual T operator()(const int row, const int col) const {
            if(row < 0 || row >= this->shape().first){
                throw std::out_of_range(string("Invalid row: ") + std::to_string(row));
            }
            if(col < 0 || col >= this->shape().second){
                throw std::out_of_range(string("Invalid col: ") + std::to_string(col));
            }
            return this->cells_[row][col];
        }

        /**
         * Overrides default round parenthesis access behaviour when
         * *writing*
         * my_mat(2,5) = 3 to access element at row 2 and column 5
         * - on wrong indeces, throw std::out_of_bounds exception
        */

        virtual T& operator()(const int row, const int col) {
            if(row < 0 || row >= this->shape().first){
                throw std::out_of_range(string("Invalid row: ") + std::to_string(row));
            }
            if(col < 0 || col >= this->shape().second){
                throw std::out_of_range(string("Invalid col: ") + std::to_string(col));
            }
            return this->cells_[row][col];
        }

        /**
         * RETURN a vector of triplets {row index, column index, value}
         * of non-zero cells,
         * in *no particular order*.
         * - NOTE: DO *NOT* write 0, use T() instead
        */

        virtual vector<Triplet<T>> nonzero() const {
            vector<Triplet<T>> ret;

            for(int i = 0; i < this->shape().first; i++){
                for(int j = 0; j < this->shape().second; j++){
                    T v = this->cells_[i][j];
                    if(v != T()){
                        ret.push_back(Triplet<T>{i, j, v});
                    }
                }
            }
            return ret;
        }

        virtual DenseMatrix<T> operator+(const Matrix<T>& other) const {
            if(this->shape() != other.shape()){
                throw std::invalid_argument(string("Mismatch in dimensions! this: ")
                        + pair2str(this->shape()) + string(" other: ") + pair2str(other.shape()));
            }
            DenseMatrix<T> ret = DenseMatrix(this->cells_);
            for(int i = 0; i < this->shape().first; i++){
                for(int j = 0; j < this->shape().second; j++){
                    ret.cells_[i][j] += other(i, j);
                }
            }
            return ret;
        }

        virtual DenseMatrix<T>& operator+=(const Matrix<T>& other) {
            if(this->shape() != other.shape()){
                throw std::invalid_argument(string("Mismatch in dimensions! this: ")
                        + pair2str(this->shape()) + string(" other: ") + pair2str(other.shape()));
            }
            for(int i = 0; i < this->shape().first; i++){
                for(int j = 0; j < this->shape().second; j++){
                    this->cells_[i][j] += other(i, j);
                }
            }
            return *this;
        }

};
#endif // DENSE_MATRIX_H