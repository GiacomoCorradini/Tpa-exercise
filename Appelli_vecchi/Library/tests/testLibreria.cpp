#include "Libreria.h"
#include "catch2/catch2.hpp"

TEST_CASE("classe Persona", "[Libreria]") {
    
    DATA data = {21, LUG, 1998};
    Persona* persona = new Persona ("Giacomo", "Corradini", data);
    
    REQUIRE(persona->getCognome() == "Corradini");
    REQUIRE(persona->getNome() == "Giacomo");
    REQUIRE(persona->getData().anno == 1998);

    DATA data1 = {27, GEN, 1993};

    persona->setNome("Riccardo");
    persona->setCognome("Gottoli");
    persona->setData(data1);

    REQUIRE(persona->getCognome() == "Gottoli");
    REQUIRE(persona->getNome() == "Riccardo");
    REQUIRE(persona->getData().giorno == 27);
}

TEST_CASE("classe Casa editrice", "[Libreria]") {
    
    DATA data = {21, LUG, 1998};
    Persona* persona = new Persona ("Giacomo", "Corradini", data);
    CasaEditrice* Feltrinelli = new CasaEditrice("Feltrinelli", persona);

    REQUIRE(Feltrinelli->getNomeCasa() == "Feltrinelli");
    REQUIRE(Feltrinelli->getFondatore()->getCognome() == "Corradini");
    REQUIRE(Feltrinelli->getFondatore()->getNome() == "Giacomo");
    REQUIRE(Feltrinelli->getFondatore()->getData().anno == 1998);

    DATA data1 = {27, GEN, 1993};
    Feltrinelli->setNomeCasa("Bompianti");
    persona->setNome("Riccardo");
    persona->setCognome("Gottoli");
    persona->setData(data1);
    Feltrinelli->setFondatore(persona);

    REQUIRE(Feltrinelli->getNomeCasa() == "Bompianti");
    REQUIRE(Feltrinelli->getFondatore()->getCognome() == "Gottoli");
    REQUIRE(Feltrinelli->getFondatore()->getNome() == "Riccardo");
    REQUIRE(Feltrinelli->getFondatore()->getData().anno == 1993);
}

TEST_CASE("classe Autore", "[Libreria]") {
    
    DATA data = {21, LUG, 1998};
    GENERE gen = {SAGGI};
    Autore* Hello = new Autore(gen, "Giacomo", "Corradini", data);

    REQUIRE(Hello->getNome() == "Giacomo");
    REQUIRE(Hello->getCognome() == "Corradini");
    REQUIRE(Hello->getData().anno == 1998);
    REQUIRE(Hello->getGenere() == SAGGI);

    Hello->setGenere(GENERE{FANTASCIENZA});
    REQUIRE(Hello->getGenere() == FANTASCIENZA);
}

TEST_CASE("classe Libro", "[Libreria]") {

    Autore* Giacomo = new Autore(GENERE{SAGGI}, "Giacomo", "Corradini", DATA{21, LUG, 1998});
    Autore* Riccardo = new Autore(GENERE{FANTASCIENZA}, "Giacomo", "Corradini", DATA{27, GEN, 1993});
    Autore* Matilde = new Autore(GENERE{ROMANZI}, "Giacomo", "Corradini", DATA{25, SET, 1996});
    Persona* persona = new Persona ("Alessio", "Feltrinelli", DATA{26, FEB, 1946});
    CasaEditrice* Feltrinelli = new CasaEditrice("Feltrinelli", persona);

    Libro* primo = new Libro("I leoni morti", Feltrinelli, 2001);
    
    primo->addAutore(Giacomo);
    primo->addAutore(Riccardo);
    primo->addAutore(Matilde);
    primo->setCopieDisponibili(145);

    REQUIRE(primo->getCopieDisponibili() == 145);
    REQUIRE(primo->getTitolo() == "I leoni morti");
}

TEST_CASE("classe Libreria", "[Libreria]") {


}