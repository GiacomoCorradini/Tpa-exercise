#include "geometry2.h"

// CLASS POINT
Point::Point(int x, int y){
    this->x = x;
    this->y = y;
}

int Point::get_x () const {
    return x;
}

int Point::get_y() const {
    return y;
}

void Point::set_x(const int x){
    this->x = x;
}

void Point::set_y(const int y){
    this->y = y;
}

string Point::as_string() const {
    return std:: to_string(this->x) + string(",") + to_string(this->y);
}

// CLASS POINTARRAY

PointArray::PointArray(){
    this->point = NULL;
    this->size = 0;
}

PointArray::PointArray(const Point points[], const int size){
    if(size < 0){
        throw std::invalid_argument("Negative size!");
    } else if (size == 0){
        this->point == NULL;
    } else {
        this->point = new Point[size];
        this->size = size;
        for(int i = 0; i < size; i++){
            this->point[i] = point[i];
        }
    }
}

PointArray::PointArray(const PointArray& pv) : PointArray(pv.point, pv.size){
    cout << "DEBUG: copy constructor" << endl;
}

PointArray::~PointArray(){
    cout << "DEBUG: PointArray destructor" << endl;
    delete[] point;
}

void PointArray::resize(int n){
    cout << "DEBUG: resizing from " << this->size << " to " << n << endl;
    if (n < 0){
        throw std::invalid_argument("Negative size!");
    } else if (n == 0){
        delete[] this->point;
        this->point = NULL;
        this->size = n;
    } else if(n < this->size || n > this->size){
        Point* old_point = this->point;
        this->point = new Point[n];
        for(int i = 0; i < std::min(n, this->size); i++){
            this->point[i] = old_point[i];
        }
        this->size = n;
        delete[] old_point;
    }
}

string PointArray::as_string() const {
    string s = string("size: ") + std::to_string(this->size) + string(" points:");
    for(int i = 0; i < this->size; i++){
        s += string(" ") + this->point[i].as_string(); 
    }
    return s;
}

void PointArray::push_back(const Point& p){
    cout << "DEBUG: pushing back " << p.as_string() << endl;
    resize(this->size + 1);
    this->point[this->size-1] = p;
}

void PointArray::insert(const int pos, const Point &p){
    cout << "DEBUG: inserting " << p.as_string() << " into pos " << pos << endl;
    if(pos < 0){
        throw std::invalid_argument(string("pos is negative!") + std::to_string(pos));
    }
    if (pos > this->size){
        throw std::invalid_argument(string("pos exceeds array limits: ") + std::to_string(pos));
    }
    resize(this->size+1);
    for(int i = this->size-1; i > pos; i--){
        this->point[i] = this->point[i-1];
    }
    this->point[pos] = p;
}

void PointArray::remove(const int pos){
    cout << "DEBUG: removing pos " << pos << endl;
    if(pos < 0){
        throw std::invalid_argument(string("pos is negative!") + std::to_string(pos));
    }
    if (pos > this->size){
        throw std::invalid_argument(string("pos exceeds array limits: ") + std::to_string(pos));
    }
    for(int i = pos; i < this->size; i++){
        this->point[i] = this->point[i+1];
    }
    resize(this->size-1);
}

int PointArray::get_size() const {
    return this->size;
}

void PointArray::clear(){
    resize(0);
}

Point* PointArray::get(const int position) const {
    if(position < 0){
        throw std::invalid_argument(string("pos is negative!") + std::to_string(position));
    }
    if (position > this->size){
        throw std::invalid_argument(string("pos exceeds array limits: ") + std::to_string(position));
    }
    return &(this->point[position]);
}