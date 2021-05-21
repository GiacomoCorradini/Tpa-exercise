#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
using namespace std;

class Point
{
    private :
        int x;
        int y;
    public :
        Point(){x = 0; y = 0;}
        Point(int x, int y){this->x = x; this->y = y;}
        int get_x();
        int get_y();
        void set_x(const int x);
        void set_y(const int y);
        string as_string();
};

class PointArray
{
    private:
        int size;
        Point* points;
    protected:

    public:
        PointArray(){size = 0;}
        PointArray(const Point points[], const int size);
        PointArray(const PointArray& pv);

        ~PointArray();

};


#endif // GEOMETRY_H