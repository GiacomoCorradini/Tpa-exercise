
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

