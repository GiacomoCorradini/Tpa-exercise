#include <iostream>
#include <unordered_map>

#include <deliv.h>

#define MIN_DELAY 10
#define RIPOSO 8*60
/*
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
*/
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

class Viaggio{

    private:

        int id_;
        unordered_map<string, Beni*> carico_;
        vector<int> permanenza_a, permanenza_e;
        vector<int> min_cumu_a, min_cumu_e;

    public:

        Viaggio(int id) : id_(id) {
            cout << "Costruttore viaggio: " << this->id_ << endl;
        }

        ~Viaggio(){
            cout << "Distruttore viaggio" << endl;
            for(std::pair<const string, Beni*>& b : this->carico_){
                delete b.second;
            }
        }
};

class Company{

    private:

        vector<Viaggio*> trip_;
        unordered_map<string, Warehouse*> warehouse_; // database magazzini: nome città, Warehouse
        unordered_map<string, Customs*> customs_; // database dogane: nome, Customs
        unordered_map<string, Connection*> connection_; // database connection: nome città_partenza, connection

    public:

        // costruttore company
        Company(){
            cout << "DEBUG: Constructor company" << endl;
        }

        // distruttore company
        ~Company(){
            cout << "DEBUG: Distruttore company" << endl;
            for(std::pair<const string, Warehouse*> w : this->warehouse_){
                delete w.second;
            }
            for(std::pair<const string, Customs*> a : this->customs_){
                delete a.second;
            }
            for(Viaggio* v : this->trip_){
                delete v;
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
            // check magazzino
            if(this->warehouse_.count(citta) != 1){
                throw std::invalid_argument(string("Magazzino non presente a: ") + citta);
            }
            // check carico in magazzino
            for(std::pair<const string, int> c : carico){
                if(this->warehouse_.at(citta)->get_beni().count(c.first) != 1){
                    throw std::invalid_argument(string("Carico in magazzino non presente: ") + c.first);
                }
            }
            // stampa
            cout << "DEBUG goods to load: {" << endl;
            for(std::pair<string, int> d : carico){
                cout << "\t" << d.first << " : " << d.second;
            }
            // registrazione carico
            for(std::pair<const string, int> c : carico){
                Beni* ben = new Beni(c.first, c.second);
                this->trip_[trip_id]->carico_[c.first] = ben;
            }
            // aggiotnamento tempistica
            int min = 0;
            for(std::pair<const string, int> c : carico){
                min += MIN_DELAY * c.second;
            }
            this->trip_[trip_id]->permanenza_a.push_back(min);
            int min_a = min + this->trip_[trip_id]->min_cumu_a[trip_id];
            this->trip_[trip_id]->min_cumu_a.push_back(min_a);
            // aggiornamento magazzino
            for(std::pair<const string, int> c : carico){
                
            }
        }
/*
        string trip_to_string(int id){
            stringstream ss;
            
        }
*/
};