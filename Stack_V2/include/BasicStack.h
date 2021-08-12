#ifndef BASIC_STACK_H
#define BASIC_STACK_H

#include <iostream>
#include <string>
#include <Stack.h>
#include <sstream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

template<typename T>
class BasicStack : public Stack<T> {

    protected:

        vector<T> elements;
 
    public:

        BasicStack();

        virtual int size() const;

        virtual string as_string() const;

        virtual bool is_empty() const;

        virtual void push(const T c);

        virtual T peek() const;

        virtual T pop();

        virtual vector<T> peekn(const int n) const;

        virtual vector<T> popn(const int n);
 
};

template<typename T>
BasicStack<T>::BasicStack(){
    this->elements = vector<T>();
}

template<typename T>
int BasicStack<T>::size() const {
    return this->elements.size();
}

template<typename T>
string BasicStack<T>::as_string() const{
    std::stringstream ss; 
    ss << string("BasicStack: elements: ");
    for(int i = 0; i < this->elements.size(); i ++){
        ss << this->elements[i];
    }
    return ss.str();
}

template<typename T>
bool BasicStack<T>::is_empty() const {
    return this->elements.size() == 0;
}

template<typename T>
void BasicStack<T>::push(const T c){
    this->elements.push_back(c);
}

template<typename T>
T BasicStack<T>::peek() const {
    if(this->elements.size() == 0){
        throw std::runtime_error("Empty stack !");
    } else {
    return this->elements.back();
    }
}

template<typename T>
T BasicStack<T>::pop(){
    if(this->elements.size() == 0){
        throw std::runtime_error("Empty stack !");
    } else {
        T ret = this->elements.back();
        this->elements.pop_back();
        return ret;
    }
}

template<typename T>
vector<T> BasicStack<T>::peekn(const int n) const {
    if(n < 0){
        throw std::invalid_argument("Negative n!" + std::to_string(n)); 
    }

    if(this->elements.size() >= n){
        int i = this->size() - n;
        vector<T> ret = {this->elements.begin() + i, this->elements.end()};
        return ret;
    }

    throw std::invalid_argument(string("Requested to peak ")
                    + std::to_string(n) 
                    + string(" elements, but there are only ")
                    + std::to_string(this->elements.size())
                    + string(" in the stack!"));
}

template<typename T>
vector<T> BasicStack<T>::popn(const int n){
    if(n < 0){
        throw std::invalid_argument("Negative n!" + std::to_string(n)); 
    }

    if(this->size() >= n){
        int i = this->size() - n;
        vector<T> ret = {this->elements.begin() + i, this->elements.end()};
        this->elements.resize(i);
        return ret;
    }

    throw std::invalid_argument(string("Requested to pop ")
                    + std::to_string(n) 
                    + string(" elements, but there are only ")
                    + std::to_string(this->elements.size())
                    + string(" in the stack!"));
}

#endif // BASIC_STACK_H