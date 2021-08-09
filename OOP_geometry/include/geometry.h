#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>

using namespace std;

class Point {

    private:

        int x;
        int y;

    public:

        Point(int x = 0, int y = 0);
        int get_x();
        int get_y();
        void set_x(const int x);
        void set_y(const int y);
        string as_string();

};

class PointArray{

    private:

        int size;
        Point* point;

    protected:

        void resize(int n);

    public:

        PointArray();
        PointArray(const Point points[], const int size);
        PointArray(const PointArray& pv);
        ~PointArray();
        string as_string();
        void push_back(Point &p);
        void insert(int pos, Point &p);
        void remove(int pos);
        int get_size();
        void clear();
        Point *get(int position);
};

#endif  // GEOMETRY_H 