#include <iostream>
using namespace std;

class Contatore {
    private:
        unsigned int conto;
    public:
        Contatore(){conto = 0;} // costruttore
        ~Contatore(){cout << "Chiamato il distruttore Contatore" << endl; } // distruttore
        void inc_conto(){conto++;} // contare
        int leggere_conto(){return conto;} // restituisce il conto
};

int main(){
    Contatore c1, c2; // definisce e inizializza

    cout << "c1 = " << c1.leggere_conto(); // legge conto c1
    cout << "\nc2 = " << c2.leggere_conto(); // legge conto c2

    c1.inc_conto(); // incrementa conto c1
    c2.inc_conto(); // incrementa conto c2
    c2.inc_conto(); // incrementa conto c2

    cout << "\nc1 = " << c1.leggere_conto(); // legge conto c1
    cout << "\nc2 = " << c2.leggere_conto() << endl; // legge conto c2

    return 0;
}