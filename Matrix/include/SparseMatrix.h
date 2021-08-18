#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

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

/**   
 * A SparseMatrix is a matrix which contains very few non-zero elements.
 * In this implementation, storage is modelled as a dictionary of keys (DOK in short),
 * where each key is a pair of cell coordinates which maps to a non-zero cell value.
 * NOTE: *NEVER* store zero-valued cells.
*/

template <typename T>
class SparseMatrix : public Matrix<T>{
    private:

        std::unordered_map<string, T> cells_;
        std::pair<int, int> shape_;

    public:

        /**
         * Initializes the Matrix with a vector of vector of cells
         * Provided data must allow the creation of a matrix with
         * at least one row and a column, otherwise throw
         * std::invalid_argument
         * if vector rows have different length, throws
         * std::invalid_argument
        */

        SparseMatrix(const vector<vector<T>>& values) : Matrix<T>(values) {
            int prev = -1;
            for(const vector<T>& v : values){
                if(prev == -1){
                    prev = v.size();
                } else {
                    if(prev != v.size()){
                        throw std::invalid_argument("Founf rows of different length!");
                    }
                }
            }

            int n = values.size();
            if(n == 0){
                throw std::invalid_argument("Must have at least one row!");
            }

            int m = values[0].size();
            if(n == 0){
                throw std::invalid_argument("Must have at least one column!");
            }

            this->shape_ = {n, m};

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(values[i][j] != T()){
                        this->cells_[pair2str({i, j})] = values[i][j];
                    }
                }
            }
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

        SparseMatrix( const int n, const int m, const Triplet<T> triplets[], const int triplets_size) :
                                                            Matrix<T>(n, m, triplets, triplets_size) {
            if(triplets_size <= 0){
                throw std::invalid_argument("Expected a non-empty list of triplets!");
            }
            if(n < 1){
                throw std:: invalid_argument(string("Expected a strictly positive n! Found") + std::to_string(n));
            }
            if(m < 1){
                throw std:: invalid_argument(string("Expected a strictly positive m! Found") + std::to_string(m));
            }

            for(int k = 0; k < triplets_size; k++){
                const Triplet<T>& t = triplets[k];
                if(t.row >= n){
                    throw std::invalid_argument("Found triplets with row index exceeding the declared one!");
                }
                if(t.col >= m){
                    throw std::invalid_argument("Found triplets with column index exceeding the declared one!");
                }
                if(t.value != T()){
                    this->cells_[pair2str({t.row, t.col})] = t.value;
                }
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
            ss << "SparseMatrix " << this->shape().first << "," << this->shape().second << " {" << endl;

            for(std::pair<string, T> els : this->cells_){
                ss << " " << els.first << " : " << els.second << endl;
            }
            ss << "}";

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
                throw std::out_of_range(string("Invalid row ") + std::to_string(row));
            }
            if(col < 0 || col >= this->shape().second){
                throw std::out_of_range(string("Invalid col ") + std::to_string(col));
            }
            string s = pair2str({row, col});

            if(this->cells_.count(s) == 1){
                return this->cells_.at(s);
            } else {
                return T();
            }
        }

        /**
         * Overrides default round parenthesis access behaviour when
         * *writing*
         * my_mat(2,5) = 3 to access element at row 2 and column 5
         * - on wrong indeces, throw std::out_of_bounds exception
        */

        virtual T& operator()(const int row, const int col) {
            if(row < 0 || row >= this->shape().first){
                throw std::out_of_range(string("Invalid row ") + std::to_string(row));
            }
            if(col < 0 || col >= this->shape().second){
                throw std::out_of_range(string("Invalid col ") + std::to_string(col));
            }

            string s = pair2str({row, col});

            return this->cells_[s];
        }

        /**
         * RETURN a vector of triplets {row index, column index, value}
         * of non-zero cells,
         * in *no particular order*.
         * - NOTE: DO *NOT* write 0, use T() instead
        */

        virtual vector<Triplet<T>> nonzero() const {
            vector<Triplet<T>> ret;

            for(std::pair<string, T> els : this->cells_){
                std::pair<int, int> coords = str2pair(els.first);
                ret.push_back({coords.first, coords.second, els.second});
            }

            return ret;
        }

        virtual SparseMatrix<T> operator+(const Matrix<T>& other) const {
            if(this->shape() != other.shape()){
                throw std::invalid_argument(string("Mismatch in dimensions! this: ") + pair2str(this->shape()) + string("other") + pair2str(other.shape()));
            }

            SparseMatrix<T> ret = SparseMatrix(*this);

            for(Triplet<T>& t : other.nonzero()){
                
                string coords = pair2str({t.row, t.col});

                if(ret.cells_.count(coords) == 1){
                    if(ret.cells_[coords] + t.value == T()){
                        ret.cells_.erase(coords);
                    } else {
                        ret.cells_[coords] += t.value;
                    }
                } else {
                    ret.cells_[coords] += t.value;
                }
            }
            return ret;
        }

        virtual SparseMatrix<T>& operator+=(const Matrix<T>& other) {
            if (this->shape() != other.shape()){
                throw std::invalid_argument(string("Mismatch in dimensions! this: ") + pair2str(this->shape()) 
                                                                                     + " other: " + pair2str(other.shape()) );
            }
            for (Triplet<T>& t : other.nonzero()){
                string coords = pair2str({t.row, t.col});
                if (this->cells_.count(coords) == 1){
                    if (this->cells_[coords] + t.value == T()){
                        this->cells_.erase(coords);  // don't want zero
                    } else {
                        this->cells_[coords] += t.value;
                    }
                    
                } else {
                    this->cells_[coords] = t.value;
                }
            }
            
            return *this;
        }
};

#endif // SPARSE_MATRIX_H