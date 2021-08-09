#include "circular_queue.h"
#include <cmath>
#include "iostream"

my::CircularQueue::CircularQueue(int capacity){                          
    if (capacity <= 0){
        throw std::invalid_argument(std::string("Expected positive capacity, found instead: ") + std::to_string( capacity));
    }

    this->arr = new char[capacity];  // Creates array of capacity objects, fills it with zeroes TODO
    this->head = 0;
    this->size = 0;
    this->capacity = capacity;
}

my::CircularQueue::~CircularQueue(){
    std::cout << "Destructor is being called ..." << std::endl;
    delete this->arr;
    std::cout << "End of destructor ..." << std::endl;
}
                                     
 
int my::CircularQueue::get_size(){
    return this->size;
}

int my::CircularQueue::get_capacity(){
    return this->capacity;
}

bool my::CircularQueue::isEmpty(){
    return this->size == 0;
}

char my::CircularQueue::top(){
    if (this->size > 0){
        return this->arr[this->head];
    } else {
        throw std::runtime_error("Queue is empty !");    
    }
}

void my::CircularQueue::enqueue(char v){                                
    std::cout << "DEBUG: enqueing " << v << std::endl;              
    if (this->size < this->capacity){
        this->arr[(this->head + this->size) % this->capacity ] = v;
        this->size += 1;
    } else {
        throw std::runtime_error("Queue is full !");
    }            
}

char my::CircularQueue::dequeue(){
    std::cout << "DEBUG: dequeuing ";
    if (this->size > 0){
        char temp = this->arr[this->head];
        this->head = (this->head + 1) % this->capacity;
        this->size -= 1;
        std::cout << temp << std::endl;
        return temp;
    } else {
        std::cout << std::endl;
        throw std::runtime_error("Queue is empty !");
    }
}