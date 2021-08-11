#include <iostream>
#include <string>
#include <Stack.h>
#include <CappedStack.h>

CappedStack::CappedStack(const int cap){
    if(cap <= 0){
        throw std::invalid_argument(string("Cap must be positive, found instead: ") + std::to_string(cap));
    }
    this->cap = cap;
    this->elements = string();
}

string CappedStack::as_string() const{
    string s = string("CappedStack: cap=");
           s += std::to_string(this->cap);
           s += string("elements=");
           s += this->elements;
    return s; 
}

void CappedStack::push(const char c){
    if(this->elements.size() < this->cap){
        this->elements.push_back(c);
    }
}

int CappedStack::get_cap() const{
    return this->cap;
}

void CappedStack::set_cap(const int cap){
    if(this->cap < 1){
        throw std::invalid_argument(string("Invalid cap: ") + std::to_string(cap));
    }

    if(cap < this->size()){
        this->popn(this->size() - cap);
    }

    this->cap = cap;
}