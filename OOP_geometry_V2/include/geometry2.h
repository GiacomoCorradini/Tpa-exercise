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
        int get_x() const;
        int get_y() const;
        void set_x(const int x);
        void set_y(const int y);
        string as_string() const;

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
        string as_string() const;
        void push_back(const Point &p);
        void insert(const int pos, const Point &p);
        void remove(const int pos);
        int get_size() const;
        void clear();
        Point *get(const int position) const;
};

#endif  // GEOMETRY_H 