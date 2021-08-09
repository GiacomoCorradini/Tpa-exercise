#include <iostream>
#include <math.h>
using namespace std;

class ogg_geom {
    public:
        ogg_geom(float x = 0, float y = 0) : xC(x), yC(y) {}
        void stampacentro() const
        {
            cout << xC << " " << yC << endl;
        }
    protected:
        float xC, yC;
};

class cerchio : public ogg_geom {
    public:
        cerchio(float x_C, float y_C, float r) : ogg_geom(x_C, y_C){
            raggio = r;
        }
        float area() {
            return M_PI * raggio * raggio;
        }
    private:
        float raggio;
};

class quadrato : public ogg_geom {
    public:
        quadrato(float x_C, float y_C, float x, float y) : ogg_geom(x_C, y_C){
            x1 = x;
            y1 = y;
        }
        float area(){
            float a, b;
            a = x1 - xC;
            b = y1 - yC;
            return 2 * (a * a + b * b);
        }
    private:
        float x1, y1;
};

int main(){
    cerchio C(2, 2.5, 2);
    quadrato Q(3, 3.5, 4.37, 3.85);
    cout << "Centro del cerchio : ";
    C.stampacentro();
    cout << "Centro del quadrato : ";
    Q.stampacentro();
    cout << "Area del cerchio : " << C.area() << endl;
    cout << "Area del quadrato : " << Q.area() << endl;
    return 0;
}