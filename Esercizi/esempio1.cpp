#include <iostream>
using namespace std;

class demoOgg {
    private:
        int undato; // dati della classe
    public:
        void fissaredati(int d) // stabilisce i dati
        { undato = d; }
        void mostradati()
        { cout << "Il dato è: " << undato << endl; }
};

int main(){
    demoOgg d1, d2;
    d1.fissaredati(2005);
    d2.fissaredati(2010);

    d1.mostradati();
    d2.mostradati();

    return 0;
}