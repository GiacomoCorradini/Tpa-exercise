#ifndef BASIC_STACK_H
#define BASIC_STACK_H

#include <iostream>
#include <string>
#include <Stack.h>

using std::string;
 
class BasicStack : public Stack {

    protected:

        string elements;
 
    public:

        BasicStack();

        virtual int size() const;

        virtual string as_string() const;

        virtual bool is_empty() const;

        virtual void push(const char c);

        virtual char peek() const;

        virtual char pop();

        virtual string peekn(const int n) const;

        virtual string popn(const int n);
 
};

#endif // BASIC_STACK_H