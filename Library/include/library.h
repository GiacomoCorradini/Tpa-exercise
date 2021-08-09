#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
using namespace std;

class Fondatore
{
    private:
        string nome;
        string cognome;
        int giorno;
        int mese;
        int anno;
    public:
        string 
        
};

class CasaEditrice
{
    private:
        string nome;
        string cognome;
    public:

};

class Autore
{
    private:
        string nome;
        string cognome;
        int giorno;
        int mese;
        int anno;
        string genere;
    public:
    
};

class Libro
{
    private:
        string titolo;
        class Autore;
        int anno;
        class CasaEditrice;
        int numero_copie;
    public:
    
};


#endif // LIBRARY_H