#include <iostream>

#include "geometry2.h"

using namespace std;

int main(){

   // p1 is now marked as const
   const Point p1 (11 , 3);
   cout << "p1: " << p1.as_string() << endl;
      
   // p2 is normal
   Point p2(12 , 7);
   cout << "p2: " << p2.as_string() << endl;
 
   // other variables are not used anymore, we create the corresponding Points on the fly
  
   PointArray pa;
 
   cout << pa.as_string() << endl;
 
   pa.push_back(p1);   
   cout << pa.as_string() << endl;
 
   pa.push_back(p2);   
   cout << pa.as_string() << endl;
 
   // now I can directly create a Point here:
   pa.push_back(Point(13 , 2)); 
   cout << pa.as_string() << endl;
 
   pa.insert(0, Point(14 , 5));
   cout << pa.as_string() << endl;
 
   pa.insert(4, Point(15 , 5));
   cout << pa.as_string() << endl;
 
   try {
       pa.insert(-1, Point(15 , 5));
   } catch (std::invalid_argument& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   try {
       pa.insert(6, Point(15 , 5));
   } catch (std::invalid_argument& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   pa.remove(0);
   cout << pa.as_string() << endl;
 
   pa.remove(3);
   cout << pa.as_string() << endl;
 
   try {
       pa.remove(3);
   } catch (std::invalid_argument& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
  
   PointArray pa2 = pa;
 
   pa2.push_back(Point(16 , 8));
 
   cout << "pa: " << pa.as_string() << endl;
   cout << "pa2: " << pa2.as_string() << endl;
 
   const PointArray cpa = pa;
   cout << "cpa: " << cpa.as_string() << endl;
  
   //Point* p_point = cpa.get(0);       // can't, need   const Point*
   const Point* cp_point = cpa.get(0);  // ok
   // cp_point->set_x(200);  // can't,  set_x method is not marked const
 
  
   Point* mp_point = pa.get(0);
   mp_point->set_x(100); 
   cout << "mutated point at index 0 of pa: " << mp_point->as_string() << endl;   
 
   cout << "pa: " << pa.as_string() << endl;
   cout << "pa2: " << pa2.as_string() << endl;
 
 
   return 0;
}