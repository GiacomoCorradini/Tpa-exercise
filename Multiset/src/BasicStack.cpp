#include <BasicStack.h>

BasicStack::BasicStack(){
    this->elements = std::string();
}

int BasicStack::size() const {
    return this->elements.size();
}

string BasicStack::as_string() const{
    string s = "BasicStack: elements: " + this->elements;
    return s;
}

bool BasicStack::is_empty() const {
    return this->elements.size() == 0;
}

void BasicStack::push(const char c){
    this->elements.push_back(c);
}

char BasicStack::peek() const {
    if(this->elements.size() == 0){
        throw std::runtime_error("Empty stack !");
    } else {
    return this->elements.back();
    }
}

char BasicStack::pop(){
    if(this->elements.size() == 0){
        throw std::runtime_error("Empty stack !");
    } else {
        char ret = this->elements.back();
        this->elements.pop_back();
        return ret;
    }
}

string BasicStack::peekn(const int n) const {
    if(n < 0){
        throw std::invalid_argument("Negative n!" + std::to_string(n)); 
    }

    if(this->size() >= n){
        int i = this->size() - n;
        string ret = this->elements.substr(i);
        return ret;
    }

    throw std::invalid_argument(string("Requested to peak ")
                    + std::to_string(n) 
                    + string(" elements, but there are only ")
                    + std::to_string(this->elements.size())
                    + string(" in the stack!"));
}

string BasicStack::popn(const int n){
    if(n < 0){
        throw std::invalid_argument("Negative n!" + std::to_string(n)); 
    }

    if(this->size() >= n){
        int i = this->size() - n;
        string ret = this->elements.substr(i);
        this->elements = this->elements.substr(0,i);
        return ret;
    }

    throw std::invalid_argument(string("Requested to pop ")
                    + std::to_string(n) 
                    + string(" elements, but there are only ")
                    + std::to_string(this->elements.size())
                    + string(" in the stack!"));
}