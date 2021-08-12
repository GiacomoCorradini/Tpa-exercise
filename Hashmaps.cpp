#include <iostream>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;

void unordered_map_example(){

    cout << endl;
    cout << "----- UNORDERED MAP" << endl;

    // empty init

    std::unordered_map<char, int> umap;
    cout << "---- Setting key to a value" << endl;

    // Setting associations doesn't depend on map size so it's very fast.
    // In technical terms we say it has O(1) computational complexity

    umap['a'] = 7;
    umap['b'] = 4;
    umap['c'] = 5;

    // initializer list

    std::unordered_map<char, int> umap2 = {
    {'a', 7},
    {'b', 4},
    {'c', 5}
    };

    // size

    cout << "number of keys: " << umap.size() << endl; // 3
    cout << "---- Getting values from keys" << endl;

    // Getting a value given a key is fast as well, retrieval is constant time O(1)
    // and doesn't depend on map size
    // WARNING: [] operator is *NOT* a const method!

    cout << "reading umap['a']: " << umap['a'] << endl; // 7
    cout << "size(): " << umap.size() << '\n'; // 3
    cout << "---- Getting non-present keys with [] doesn't give exception" << endl;

    // When you use square brackets and item is not found, inserts item associated to default constructor for value,
    // in this case 0 for int.

    cout << "Reading non present key umap['z']: " << umap['z'] << endl; // 0
    cout << "size(): " << umap.size() << endl; // 4
    cout << "---- Getting non-present keys with .at() gives exceptions" << endl;

    // If you don't what automatic insertion you can use .at() method, which raises an exception on missing key:
    // NOTE: at is a const method

    try {
        cout << umap.at('X') << '\n'; // not found, throws exception
    } catch (std::out_of_range& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };

    cout << "size(): " << umap.size() << endl; // 4
    cout << "reading umap['c']: " << umap['c'] << endl; // 5
    cout << "umap['c']++"<< endl;
    umap['c']++;
    cout << umap['c'] << endl; // 6
    cout << "---- Iterating" << endl;

    // There are many ways to iterate stl collections, in unordered_map case a handy one
    // is iterating through key/value pairs with a range based for loop like this:
    // **WARNING 1**: order of iteration is **NOT** guaranteed! Never make assumptions about it!

    for (std::pair<char, int> element : umap) {
        cout << element.first << " : " << element.second << endl;
    }

    cout << "---- Iterating and modifying without a reference" << endl;

    // **WARNING 2**: without a reference, element holds a *copy* of key/values taken from the map

    for (std::pair<char, int> element : umap) {
        element.second = 666; // doesn't actually change umap
    }

    for (std::pair<char, int> element : umap) {
        cout << element.first << " : " << element.second << endl;
    }

    // c : 6
    // b : 4
    // z : 0
    // a : 7

    cout << "---- Iterating and modifying with a reference" << endl;

    // WARNING: with a reference we can rewrite values *but not keys*, so we MUST put const in keys
    // otherwise compiler complains

    for (std::pair<const char, int>& element : umap) { // notice const and &
        // element.first = 'z'; // can't
        element.second = 123; // now ok
    }

    for (std::pair<char, int> element : umap) {
        cout << element.first << " : " << element.second << endl;
    }

    // c : 123
    // b : 123
    // z : 123
    // a : 123

    cout << "---- Finding an element" << endl;

    // There are many ways to check whether or not an element is present, we can use count which in this case takes constant time O(1)
    
    char ch = 'a';
    cout << "umap.count(" << ch << "): " << umap.count(ch) << endl;

    if (umap.count(ch) == 1) {
        std::cout << "Found key '" << ch << "' with value " << umap[ch]
    << endl;
    } else {
        std::cout << "Key '" << ch << "' not found\n";
    }

    ch = 'z';
    cout << "umap.count(" << ch << "): " << umap.count(ch) << endl;

    if (umap.count(ch) == 1) {
        std::cout << "Found key " << ch << " with associated value " <<
        umap[ch] << endl;
    } else {
        std::cout << "Key '" << ch << "' not found\n";
    }

    cout << "---- Erasing an association" << endl;
    cout << "umap.erase('a')" << endl;
    umap.erase('a');
    cout << "size: " << umap.size() << endl;
    int ret = umap.erase('W'); // if key is not present returns a zero
    cout << "'W' not present, umap.erase('W') returns " << ret << endl;

    if (ret == 0){
        cout << "Couldn't erase 'W'" << endl;
    }

    cout << " ---- MUTABLE KEYS test" << endl;
    std::string s = "ciao";

    //std::unordered_map<string&, int> umr;
    //umr[s] = 4; // doesn't like string &

    std::unordered_map<std::string, int> um;

    um[s] = 4;
    cout << um[s] << endl;
    s += "mondo";
    cout << um[s] << endl;
    //w += "borg";
    cout << um[s] << endl;
    cout << um["ciao"] << endl;

    //std::unordered_map<std::pair<int,int>, int> umpa; // pair not hashable
    //std::unordered_map<std::tuple<int,int>, int> umpa; // tuple not hashable

    cout << " ---- INSERT TEST" << endl;

    // WARNING: .insert METHOD ONLY INSERTS IF KEY DOES NOT ALREADY EXIST!!
    // PLEASE PREFER USING [] OPERATOR INSTEAD

    unordered_map<std::string , int > mymap;

    mymap.insert(std::pair<std::string, int>("a",3));
    mymap.insert(std::pair<std::string, int>("a",4));

    cout << mymap["a"] << endl; // 3
}