#include <iostream>
using namespace std;

class GiornoAnno
{
    public:
        void visualizzare();
        int mese;
        int giorno;
};

void GiornoAnno::visualizzare(){
    cout << "mese = " << mese << ", ";
    cout << "giorno = " << giorno << endl;
}

int main(){
    GiornoAnno oggi, compleanno;
    cout << "Introduca data del giorno di oggi\n";
    cout << "Numero del mese: ";
    cin >> oggi.mese;
    cout << "Giorno del mese: ";
    cin >> oggi.giorno;
    cout << "Introduca la sua data di nascita\n";
    cout << "Numero del mese: ";
    cin >> compleanno.mese;
    cout << "Giorno del mese: ";
    cin >> compleanno.giorno;

    cout << "La data di oggi è: ";
    oggi.visualizzare();
    cout << "La sua data di nascita è: ";
    compleanno.visualizzare();

    if(oggi.mese == compleanno.mese && oggi.giorno == compleanno.giorno){
        cout << "Buon compleanno" << endl;
    } else {
        cout << "Buon giorno" << endl; 
    }

    return 0;
}

