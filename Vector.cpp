#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream> // std::stringstream, std::stringbuf

using namespace std;

/*
    *
    * Prints a vector
    * 
*/

    template<typename T>
    string vec2str(vector<T> v){
        std::stringstream ss;
        for (int i = 0; i < v.size(); i++){
            ss << v[i];
        }
        return ss.str();
}

/*
    *
    * Class Vector
    *
*/

int main(){

        cout << endl;

        cout << "------ VECTOR EXAMPLE" << endl;

        cout << endl;

    // for printing

        cout << "Example to convert any basic type to string" << endl;

        std::stringstream ss;

        ss << 'a';
        ss << 4;
        ss << "ciao";

        string s = ss.str(); // ar4ciao

        cout << s << endl;

    // our vector, we need to specify wihch type contains
    // here we chose char but could be any

        vector<char> vec;

        vec.push_back('a');
        vec.push_back('b');
        vec.push_back('c');
        vec.push_back('d');
        vec.push_back('e');
        vec.push_back('f');
        vec.push_back('g');
        vec.push_back('h');

    // Useful functions Vector class

        cout << "vec: " << vec2str(vec) << endl; // abcdefgh
        cout << "vec.size(): " << vec.size() << endl; // 8
        cout << "access element 0: " << vec[0] << endl; // a

        cout << "get a new subvector from index 3 (included) to 5 (excluded): " << endl;
        vector<char> subvec1 = {vec.begin() + 3, vec.begin() + 5};
        cout << "subvec1: " << vec2str(subvec1) << endl; // de
        cout << "get a new subvector from index 3 *included* to end:" << endl;

        vector<char> subvec2 = {vec.begin() + 3, vec.end()};
        cout << "subvec2: " << vec2str(subvec2) << endl; // defgh
        cout << "cut vec to 3 elements:" << endl;
        vec.resize(3);
        cout << "vec: " << vec2str(vec) << endl; // abc
        cout << "vec: vec.back(): " << vec.back() << endl;
        cout << "for each construct" << endl;

    // at each iteration, assigns variable c to a *copy* of element of vector
    
        vector<char> v = {'a','c','b','e'};

        for (char c : v){
            cout << c << endl;
        }

        cout << endl;

    // Print 

        // a
        // c
        // b
        // e

    cout << "for each construct: modifying without reference" << endl;

    for (char c : v){
        c = 'z'; // c is a copy, does *not* change characters inside v!
    }

    for (char c : v){
        cout << c << endl;
    }

    // Print 

        // a
        // c
        // b
        // e

    cout << "for each construct: modifying with reference" << endl;

    for (char& cr : v){ // note the &
        cr = 'z'; // Reference can change characters inside v
    }

    for (char c : v){
        cout << c << endl;
    }

        // z
        // z
        // z
        // z

    cout << "for each on regular arrays" << endl;

        // works also on regular arrays (ONLY IF compiler knows the dimension)

        char prova[3] = {'a','b','c'};

        for (char& c : prova){
            cout << c << endl;
        }

        cout << endl;

        // a
        // b
        // c
}