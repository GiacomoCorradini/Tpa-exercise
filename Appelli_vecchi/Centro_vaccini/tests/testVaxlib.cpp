
#include "vaxlib.h"
#include "catch2/catch2.hpp"




TEST_CASE("test 1 ", "[vaxlib]") {
    

    // expects std::invalid_argument exception, if it is not thrown test fails        
    //REQUIRE_THROWS_AS( square_root(-1.0), std::invalid_argument);

    //REQUIRE(square_root(0.0) == Approx(0.0));
}


TEST_CASE("test 2", "[vaxlib]") {
                
    //REQUIRE(square_root(4.0) == Approx(2.0));
}


TEST_CASE("test 3", "[vaxlib]") {
    
    //REQUIRE( cxx_examples::say_hello("peppo") == std::string("hello peppo"));        
}





