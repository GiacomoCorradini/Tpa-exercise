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

class Polygon{
    protected:

        const PointArray* arr;
        static int npolygon;
        static Point constructorPoints[4];
        static Point* updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0));

    public:

        Polygon(const Point points[],const int size);
        Polygon(const PointArray* iarr);
        Polygon(const Polygon& pol);
        ~Polygon();

        virtual double area() const = 0;
        static int getNumPolygons();
        int getNumSides() const;
        const PointArray* getPoints() const;
};

class Rectangle : public Polygon {
    
    public:

        Rectangle(const Point lower_left, const Point upper_right);
        Rectangle(const int x1, const int y1, const int x2, const int y2);
        virtual double area() const;
};

class Triangle : public Polygon {

    public:
        Triangle(const Point p1, const Point p2, const Point p3);
        virtual double area() const;
};

#endif  // GEOMETRY_H 