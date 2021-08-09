
#include "catch2/catch2.hpp"
#include "geometry2.h"

// CLASS POINT
TEST_CASE("La funzione get_x ritorna il valore di x", "[geometry_V2]") {
    Point p1 (11 , 3);
    REQUIRE(p1.get_x() == 11);
}

TEST_CASE("La funzione get_y ritorna il valore di y", "[geometry_V2]") {
    Point p1 (11 , 3);
    REQUIRE(p1.get_y() == 3);
}

TEST_CASE("La funzione set_x setta il valore di x", "[geometry_V2]") {
    Point p1 (11 , 3);
    p1.set_x(3);
    REQUIRE(p1.get_x() == 3);
}

TEST_CASE("La funzione set_y ritorna il valore di y", "[geometry_V2]") {
    Point p1 (11 , 3);
    p1.set_y(6);
    REQUIRE(p1.get_y() == 6);
}

TEST_CASE("La funzione as_string ritorna il punto p nel formato stringa", "[geometry_V2]") {
    Point p1 (11 , 3);
    std::string s = p1.as_string();
    REQUIRE(s == "11,3");
}

//CLASS POINTARRAY

TEST_CASE("La funzione push back aggiunge il punto p in cima all'array", "[geometry_V2]") {
    const Point p1 (11 , 3);
    const Point p2(12 , 7);
    PointArray pa;
    pa.push_back(p1);
    pa.push_back(p2);
    std::string s = pa.as_string();
    REQUIRE(s == "size: 2 points: 11,3 12,7");
}

TEST_CASE("La funzione insert aggiunge il punto p nella posizione indicata nell'array", "[geometry_V2]") {
    const Point p1 (11 , 3);
    const Point p2(12 , 7);
    PointArray pa;
    pa.push_back(p1);
    pa.push_back(p2);
    pa.insert(1, Point(15, 5));
    std::string s = pa.as_string();
    REQUIRE(s == "size: 3 points: 11,3 15,5 12,7");
}

TEST_CASE("La funzione clear elimina i punti nell'array", "[geometry_V2]") {
    const Point p1 (11 , 3);
    const Point p2(12 , 7);
    PointArray pa;
    pa.push_back(p1);
    pa.push_back(p2);
    pa.insert(1, Point(15, 5));
    pa.clear();
    REQUIRE(pa.get_size() == 0);
}

TEST_CASE("La funzione remove elimina il punto nella posizione indicata nell'array", "[geometry_V2]") {
    const Point p1 (11 , 3);
    const Point p2(12 , 7);
    PointArray pa;
    pa.push_back(p1);
    pa.push_back(p2);
    pa.insert(1, Point(15, 5));
    pa.remove(1);
    std::string s = pa.as_string();
    REQUIRE(s == "size: 2 points: 11,3 12,7");
}