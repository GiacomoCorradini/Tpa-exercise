#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;
using std::endl;

enum MESE {GEN, FEB, MAR, APR, MAG, GIU, LUG, AGO, SET, OTT, NOV, DIC};
enum GENERE {FANTASCIENZA, ROMANZI, SAGGI};

struct DATA {
    int giorno;
    MESE mese;
    int anno;
};

// la classe fondatore coincide con la classe persona

/**
 * CLASSE FONDATORE
 * Nome
 * Cognome
 * Data di nascita
*/

/**
 * CLASS PERSON
 * - Nome
 * - Cognome
 * - Data di nascita
*/

class Persona{
    private:

        string nome_;
        string cognome_;
        DATA data_;

    public:

        // costruttore persona
        Persona(const string &nome, const string &cognome, const DATA &data) : nome_(nome), cognome_(cognome), data_(data) {}

        // funzione per settare nome, cognome, data
        void setNome(const string &nome){
            this->nome_ = nome;
        }
        void setCognome(const string &cognome){
            this->cognome_ = cognome;
        }
        void setData(const DATA &data){
            this->data_ = data;
        }

        // funzioni per ritornare nome, cognome, data
        const string& getNome() const {
            return this->nome_;
        }
        const string& getCognome() const {
            return this->cognome_;
        }
        const DATA& getData() const {
            return this->data_;
        }
};

/**
 * CLASSE CASA_EDITRICE
 * Nome
 * Fondatore
*/

class CasaEditrice{
    private:

        string nomeCasa_;
        Persona* fondatore_;

    public:
        // costruttore casa editrice
        CasaEditrice() {
            this->nomeCasa_ = "";
            this->fondatore_ = NULL;
        };
        CasaEditrice(const string& nome, Persona* fondatore) : nomeCasa_(nome), fondatore_(fondatore) {}

        // funzione per settare nome, fondatore
        void setNomeCasa(const string &nome){
            this->nomeCasa_ = nome;
        }
        void setFondatore(Persona* persona){
            this->fondatore_ = persona;
        }

        // funzioni per ritornare nome, fondatore
        const string& getNomeCasa() const {
            return this->nomeCasa_;
        }
        const Persona* getFondatore() const {
            return this->fondatore_;
        }
};

/**
 * CLASSE AUTORE
 * Nome
 * Cognome
 * Data di nascita
 * Genere 
*/

class Autore : public Persona{
    private:

        GENERE genere_;

    public:

        // costruttore autore
        Autore(const GENERE& genere, const string &nome, const string &cognome, const DATA &data) : Persona(nome, cognome, data), genere_(genere){}

        // funzione per settare genere
        void setGenere(const GENERE& genere){
            this->genere_ = genere;
        }

        // funzioni per ritornare genere
        const GENERE& getGenere() const {
            return this->genere_;
        }
};

/**
 * CLASSE LIBRO
 * - titolo
 * - autori
 * - anno di pubblicazione
 * - casa editrice
 * - numero di copie disponibili in libreria
*/

class Libro{
    private:

        string titolo_;
        vector<Autore*> autori_;
        int anno_;
        CasaEditrice* casa_;
        int numero_copie_;

    public:

        // costruttore libro
        Libro(const string& titolo, CasaEditrice* casa, const int& anno, int numero = 0) : titolo_(titolo), 
                casa_(casa), anno_(anno), numero_copie_(numero) {}

        // funzioni per settare numero copie e autori
        void addAutore(Autore* autore){
            this->autori_.push_back(autore);
        }
        void setCopieDisponibili(const int numero){
            if(numero < 0){
                throw std::invalid_argument("Numero di copie non può essere negativo!");
            }
            this->numero_copie_ = numero;
        }

        // funzioni che ritornano titolo, autori, casa editrice, anno di pubblicazione, copie disponibili
        const string& getTitolo() const {
            return this->titolo_;
        }
        const CasaEditrice* getCasaEditrice() const {
            return this->casa_;
        }
        const int getAnnoDiPubblicazione() const {
            return this->anno_;
        }
        const int getCopieDisponibili() const {
            return this->numero_copie_;
        }
        const vector<Autore*>& getAutori() const {
            return autori_;
        }
};

/**
 * CLASSE LIBRERIA
 * - nome libreria
 * - libri
 * - autori
 * - case editrici
*/

class Libreria{
    private:

        string nome_;
        vector<Libro*> libri_;
        vector<Autore*> autori_;
        vector<CasaEditrice*> casa_;

    public:
        // costruttore libreria
        Libreria(const string &nome) : nome_(nome) {}

        // funzioni per aggiungere libri, autori, case editrici
        void agg_libro(Libro* l){
            this->libri_.push_back(l);
        }
        void agg_autore(Autore* a){
            this->autori_.push_back(a);
        }
        void agg_casaeditrice(CasaEditrice* c){
            this->casa_.push_back(c);
        }

        // funzioni per cercare libri, autori, case editrici
        vector<Libro*> cercaLibroTitolo(const string &titolo){
            vector<Libro*> res;
            for(auto b : this->libri_){
                if(b->getTitolo().find(titolo) != string::npos){
                    res.push_back(b);
                }
            }
            return res;
        }
        vector<Libro*> cercaLibroCognome(const string &cognome){
            vector<Libro*> res;
            for(auto r : this->libri_){
                vector<Autore*> autori = r->getAutori();
                for(auto a : this->autori_){
                    if(a->getCognome() == cognome){
                        res.push_back(r);
                    }
                }
            }
            return res;
        }
        vector<Libro*> cercaLibroRange(int anno_inizio, int anno_fine){
            vector<Libro*> res;
            for(auto b : this->libri_){
                if(b->getAnnoDiPubblicazione() >= anno_inizio && b->getAnnoDiPubblicazione() <= anno_fine){
                    res.push_back(b);
                }
            }
            return res;
        }

        const string& getNomeLibreria(){
            return this->nome_;
        }
        
        string as_string(const vector<Libro*> &al){
            stringstream ss = stringstream();
            for(auto b : al){
                int i = 0;
                ss << string("Titolo: ") << b->getTitolo() << endl;
                ss << string("Autori:");
                for(auto a : b->getAutori()){
                    if(i > 0){
                        ss << ", ";
                    }
                    ss << a->getNome() << " " << a->getCognome();
                    i++;
                }
                ss << endl << string("Anno di pubblicazione: ") << b->getAnnoDiPubblicazione() << endl;
            }
            return ss.str();
        }
};

#endif // LIBRERIA_H