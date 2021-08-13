#ifndef MULTISET_H
#define MULTISET_H

#include <iostream>
#include <unordered_map>
#include <sstream>

using std::endl;
using std::cout;

template<typename T>
class MultiSet{
    private:

        std::unordered_map<T, int> umap;

    public:

        MultiSet<T>(){
            // umap is already initialized
        }

    /** 
     * Adds one instance of element el to the multiset
     * MUST run in O(1)
    */

    void add(const T el){
        if(this->umap.count(el) == 1){
            umap[el] += 1;
        } else {
            umap[el] = 1;
        }
    }

    /**
     *  RETURN the multiplicity of element el in the multiset
     * If no instance of el is present, return 0.
     * MUST run in O(1)
    */

    int get(const T el) const {
        if(umap.count(el) == 1){
            return this->umap.at(el);
        } else {
            return 0;
        }
    }

    /** 
     * Removes n instances of element el from the multiset (that
     * is, reduces el multiplicity by n)
     * If n is negative, throws std::invalid_argument
     * If n represents a multiplicity bigger than el current
     * multiplicity, throws std::out_of_range
     * NOTE: multiset multiplicities are never negative
     * MUST run in O(1)
    */

    void removen(const T el, const int n){
        if(n < 0){
            std::invalid_argument("Negative n: " + std::to_string(n));
        }
        if(this->umap.count(el) == 1){
            int m = this->umap[el];
            if(n < m){
                this->umap[el] = m - n;
            } else if(n == m){
                this->umap.erase(el);
            } else {
                std::out_of_range("Tried to remove more than multiplicity");
            }
        }
        if(this->umap.count(el) == 0){
            if(n == 0){
                return;
            } else {
                std::out_of_range("Tried to remove more than multiplicity");
            }
        }
    }

    std::string as_string(){
        std::stringstream ss;
        ss << "{";
        for(std::pair<T, int> els : this->umap){
            ss << endl;
            ss << "{" << els.first << "," << els.second << "}";
        }

        ss << endl << "};" << endl;

        return ss.str();
    }

    /**
     * RETURN the number of elements within the multiset (sum of all
     * multiplicites)
     * MUST run in O(k) where k is the number of keys
    */

    int size() const{
        int s = 0;
        for(std::pair<T, int> element : this->umap){
            s += element.second;
        }
        return s;
    }

};

#endif // MULTISET_H