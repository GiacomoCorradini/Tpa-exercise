#include <iostream>
#include <unordered_map>

#include <deliv.h>

#define MIN_DELAY = 10
#define RIPOSO = 8*60

// classe beni
class Beni {

    private:

        string nome_; // nome del bene
        int numero_; // quantita del bene o tempo dovuto a carico, scarico

    public:

        // costruttore classe bene
        Beni(const string& nome, const int& numero) : nome_(nome), numero_(numero) {}

        // distruttore classe bene
        ~Beni() {
            cout << "DEBUG: distruttore beni" << endl;
        }

        // funzione che ritorna il nome del bene
        const string& get_beni() const {
            return this->nome_;
        }

        // funzione che ritorna la quantità/ritardo di bene
        const int& get_numero() const {
            return this->numero_;
        }
};

class Warehouse {

    private:

        string nome_citta_; // nome della città
        unordered_map<string, Beni*> beni_W_; // database di beni: nome beni, beni

    public:

        // costruttore warehouse
        Warehouse(const string& nome, const unordered_map<string, int>& beni){
            this->nome_citta_ = nome;
            for(std::pair<const string, int> b : beni){
                Beni* ben = new Beni(b.first, b.second);
                this->beni_W_[b.first] = ben;
            }
        }

        // Distruttore warehouse
        ~Warehouse(){
            cout << "Distruttore warehouse" << endl;
            for(std::pair<const string, Beni*> b : this->beni_W_){
                delete b.second;
            }
        }

        // funzione che aggiunge beni a warehouse
        void set_beni(const unordered_map<string, int>& beni){
            for(std::pair<const string, int> b : beni){
                Beni* ben = new Beni(b.first, b.second);
                this->beni_W_[b.first] = ben;
            }
        }

        // funzione che ritorna i beni presenti nel magazzino
        const unordered_map<string, Beni*>& get_beni() const {
            return this->beni_W_;
        }
};

struct Customs {

    private:

        string nome_citta_; // nome della città
        unordered_map<string, Beni*> beni_C_; // database di beni: nome beni, beni

    public:

        // costruttore warehouse
        Customs(const string& nome, const unordered_map<string, int>& beni){
            this->nome_citta_ = nome;
            for(std::pair<const string, int> c : beni){
                Beni* ben = new Beni(c.first, c.second);
                this->beni_C_[c.first] = ben;
            }
        }

        // Distruttore warehouse
        ~Customs(){
            cout << "Distruttore customs" << endl;
            for(std::pair<const string, Beni*> c : this->beni_C_){
                delete c.second;
            }
        }

        // funzione che aggiunge beni a customs
        void set_beni(const unordered_map<string, int>& beni){
            for(std::pair<const string, int> c : beni){
                Beni* ben = new Beni(c.first, c.second);
                this->beni_C_[c.first] = ben;
            }
        }

        // funzione che ritorna i beni presenti nella dogana
        const unordered_map<string, Beni*>& get_beni() const {
            return this->beni_C_;
        }
};

struct Viaggio{
    int id_;
    unordered_map<string, Beni*> carico_;
    vector<int> permanenza_a, permanenza_e;
    vector<int> min_cumu_a, min_cumu_e;
};

class Company{

    private:

        vector<Viaggio*> trip_;
        unordered_map<string, Warehouse*> warehouse_; // database magazzini: nome città, Warehouse
        unordered_map<string, Customs*> customs_; // database dogane: nome, Customs
        int trip_id_; // id del viaggio
        unordered_map<string, Connection*> connection_; // database connection: nome città_partenza, connection

    public:

        // costruttore company
        Company(){
            this->trip_id_ = -1;
            cout << "DEBUG: Constructor company" << endl;
        }

        // distruttore company
        ~Company(){
            for(std::pair<const string, Warehouse*> w : this->warehouse_){
                delete w.second;
            }
            for(std::pair<const string, Customs*> a : this->customs_){
                delete a.second;
            }
        }

        // funzione cha aggiunge warehouse
        void add_warehouse(const string& citta, const unordered_map<string, int>& ware){
            Warehouse* war = new Warehouse(citta, ware);
            this->warehouse_[citta] = war;
            cout << "DEBUG: Adding warehouse " << citta << endl;
        }

        // funzione cha aggiunge customs
        void add_customs(const string& citta, const unordered_map<string, int>& ware){
            Customs* war = new Customs(citta, ware);
            this->customs_[citta] = war;
            cout << "DEBUG: Adding customs " << citta << endl;
        }

        // funzione che aggiunge connection
        void add_connection(string partenza, string arrivo, int lungh){
            Connection* co = new Connection{partenza, arrivo, lungh};
            this->connection_[partenza] = co;
            cout << "Adding connection from " << partenza << " to " << arrivo << endl;
        }

        const int create_trip(){
            Viaggio* via = new Viaggio;
            via->id_ = this->trip_.size();
            this->trip_.push_back(via);
            cout << "DEBUG: creating trip: " << this->trip_[via->id_]->id_ << endl;
            return via->id_;
        }

        void load(int trip_id, string citta, const unordered_map<string, int>& carico){
            cout << "DEBUG goods to load: {" << endl;
            for(std::pair<string, int> d : carico){
                cout << "\t" << d.first << " : " << d.second;
            }
            
            
        }
/*
        string trip_to_string(int id){

        }
        */
};

