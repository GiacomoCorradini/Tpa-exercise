#ifndef CAPPED_STACK_H
#define CAPPED_STACK_H

#include <iostream>
#include <string>
#include <Stack.h>
#include <BasicStack.h>
#include <sstream>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

template<typename T>
class CappedStack : public BasicStack<T>{
    protected:

        int cap;

    public:

        /**
            * Creates a CappedStack capped at provided cap.
            - if cap <= 0, throws a std::invalid_argument
        */

        CappedStack(const int cap);

        /*
            * Return a string like CappedStack: cap=4 elements=ab
        */

        virtual string as_string() const;

        /*
            * Adds item to the top of the stack, if current size is within cap.
            - If stack size is already at cap value, new item is silently discarded
        */

        virtual void push(const T c);

        /*
            * RETURN the cap of the stack
        */

        virtual int get_cap() const;
        /*
            * MODIFIES the cap setting its value to the provided cap.
            If the cap is less then the stack size, all the elements above
            the cap are removed from the stack.
            If cap < 1, throws an std::invalid_argument exception
            Does *not* return anything!
            For example, with the following stack, and cap at
            position 7:
            cap ->  7
                    6
                    5 e
                    4 d
                    3 c
                    2 b
                    1 a
            calling method set_cap(3) will change the stack to this:
            cap ->  3 c
                    2 b
                    1 a
        */
        virtual void set_cap(const int cap);

};

template<typename T>
CappedStack<T>::CappedStack(const int cap){
    if(cap <= 0){
        throw std::invalid_argument(string("Cap must be positive, found instead: ") + std::to_string(cap));
    }
    this->cap = cap;
    this->elements = vector<T>();
}

template<typename T>
string CappedStack<T>::as_string() const{

    string s = string("CappedStack: cap=");
           s += std::to_string(this->cap);
           s += string("elements=");
    std::stringstream ss;
           for(int i = 0; i < this->elements.size(); i++){
               ss << this->elements[i];
           }
    s += ss.str(); 
    return s;
}

template<typename T>
void CappedStack<T>::push(const T c){
    if(this->elements.size() < this->cap){
        this->elements.push_back(c);
    }
}

template<typename T>
int CappedStack<T>::get_cap() const{
    return this->cap;
}

template<typename T>
void CappedStack<T>::set_cap(const int cap){
    if(this->cap < 1){
        throw std::invalid_argument(string("Invalid cap: ") + std::to_string(cap));
    }

    if(cap < this->size()){
        this->popn(this->size() - cap);
    }

    this->cap = cap;
}

#endif // CAPPED_STACK_H