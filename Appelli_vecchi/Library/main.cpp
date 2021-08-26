#include <iostream>
#include <string>
#include <vector>

#include <Libreria.h>

using std::cout;
using std::endl;
using std::vector;

int main(){

    // LIBRERIA
    cout << "LIBRERIA: ";
    Libreria Werehause("Giacomo");
    cout << Werehause.getNomeLibreria() << endl;

    // AUTORI
    Autore* primo_autore = new Autore(GENERE{SAGGI}, "Giacomo", "Corradini", DATA{21, LUG, 1998});
    Werehause.agg_autore(primo_autore);
    Autore* secondo_autore = new Autore(GENERE{FANTASCIENZA}, "Riccardo", "Corradini", DATA{25, SET, 1996});
    Werehause.agg_autore(secondo_autore);
    Autore* terzo_autore = new Autore(GENERE{ROMANZI}, "Matilde", "Corradini", DATA{27, GEN, 1993});
    Werehause.agg_autore(terzo_autore);
    
    // FONDATORI
    Persona* primo_fondatore = new Persona ("Luigi", "Feltrinelli", DATA{18, GEN, 1973});
    Persona* secondo_fondatore = new Persona ("Carlo", "Bompiani", DATA{6, GEN, 1965});

    // CASA EDITRICE
    CasaEditrice* Feltrinelli = new CasaEditrice("Feltrinelli", primo_fondatore);
    Werehause.agg_casaeditrice(Feltrinelli);
    CasaEditrice* Bompiani = new CasaEditrice("Bompiani", secondo_fondatore);
    Werehause.agg_casaeditrice(Bompiani);

    // LIBRI
    Libro* primo_libro = new Libro("primo_libro", Feltrinelli, 2014, 120);
    primo_libro->addAutore(primo_autore);
    primo_libro->addAutore(secondo_autore);
    Libro* secondo_libro = new Libro("secondo_libro", Bompiani, 1998, 129);
    secondo_libro->addAutore(primo_autore);
    secondo_libro->addAutore(terzo_autore);
    Libro* terzo_libro = new Libro("terzo_libro", Feltrinelli, 1978, 15);
    terzo_libro->addAutore(secondo_autore);
    terzo_libro->addAutore(terzo_autore);

    Werehause.agg_libro(primo_libro);
    Werehause.agg_libro(secondo_libro);
    Werehause.agg_libro(terzo_libro);

    cout << endl;
    cout << "Cerco libro per titolo" << endl;
    vector<Libro*> CPT = Werehause.cercaLibroTitolo("primo_libro");
    cout << Werehause.as_string(CPT) << endl;

    cout << endl;
    cout << "Cerco Libro per cognome" << endl;
    vector<Libro*> CPC = Werehause.cercaLibroCognome("Corradini");
    cout << Werehause.as_string(CPC);

    cout << endl;
    cout << "Cerco Libro per intervallo di date di pubblicazione" << endl;
    vector<Libro*> CPDP = Werehause.cercaLibroRange(1960, 2000);
    cout << Werehause.as_string(CPDP);

}