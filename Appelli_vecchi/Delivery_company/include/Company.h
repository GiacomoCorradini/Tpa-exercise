#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <deque>
#include <vector>

#include <deliv.h>

#define MIN_DELAY 10
#define RIPOSO 8*60

using std::deque;

class Warehouse {

    private:

        string nome_citta_; // nome della città
        unordered_map<string, int> beni_W_; // database di beni: nome beni, beni

    public:

        // costruttore warehouse
        Warehouse(const string& nome, const unordered_map<string, int>& beni){
            this->nome_citta_ = nome;
            for(std::pair<const string, int> b : beni){
                this->beni_W_[b.first] = b.second;
            }
            cout << "Magazzino: " << this->nome_citta_ << endl;
            cout << "Beni presenti nel magazzino: " << endl;
            for(std::pair<const string, int> b : this->beni_W_){
                cout << "\t" << b.first << " " << b.second << endl;
            }
        }

        // Distruttore warehouse
        ~Warehouse(){}

        // funzione che aggiunge beni a warehouse
        void set_beni(const unordered_map<string, int>& beni){
            for(std::pair<const string, int> b : beni){
                this->beni_W_[b.first] = b.second;
            }
        }

        // funzione che ritorna i beni presenti nel magazzino
        unordered_map<string, int>& get_beni() {
            return this->beni_W_;
        }

        // funzione che ritorna il nome del magazzino
        const string& get_citta() const {
            return this->nome_citta_;
        }
};

class Customs {

    private:

        string nome_citta_; // nome della città
        unordered_map<string, int> beni_C_; // database di beni: nome beni, beni

    public:

        // costruttore warehouse
        Customs(const string& nome, const unordered_map<string, int>& beni){
            this->nome_citta_ = nome;
            for(std::pair<const string, int> c : beni){
                this->beni_C_[c.first] = c.second;
            }
            cout << "Dogana: " << this->nome_citta_ << endl;
            cout << "Minuti necessari per check beni alla dogana: " << endl;
            for(std::pair<const string, int> b : this->beni_C_){
                cout << "\t" << b.first << " " << b.second << endl;
            }
        }

        // Distruttore warehouse
        ~Customs(){}

        // funzione che aggiunge beni a customs
        void set_beni(const unordered_map<string, int>& beni){
            for(std::pair<const string, int> c : beni){
                this->beni_C_[c.first] = c.second;
            }
        }

        // funzione che ritorna i beni presenti nella dogana
        const unordered_map<string, int>& get_beni() const {
            return this->beni_C_;
        }

        // funzione che ritorna il nome della dogana
        const string& get_citta() const {
            return this->nome_citta_;
        }
};

class Viaggio{
    
    private:

        int id_; // codice identificativo viaggio
        unordered_map<string, int> carico_; // carico presente nel camion
        vector<int> permanenza_a_, permanenza_e_; // vettori di tempi di permanenza attesi ed effettivi
        vector<int> min_cumu_a_, min_cumu_e_; // vettori di tempi cumulativi attesi ed effettivi
        vector<string> mappa_; // vettore che tiene conto del tragitto

    public:

        // costruttore viaggio
        Viaggio(int id) : id_(id) {
            cout << "DEBUG: costruttore viaggio" << endl;
        }

        // Distruttore viaggio
        ~Viaggio(){
            cout << "DEBUG: distruttore viaggio" << endl;
        }

        // funzione che registra carico
        void set_carico(unordered_map<string, int> carico){
            for(std::pair<const string, int> b : carico){
                this->carico_[b.first] = b.second;
            }
            cout << "Carico presente nel camion:" << endl;
            for(std::pair<const string, int> b : this->carico_){
                cout << b.first << " " << b.second << endl;
            }
        }

        // funzione che aggiorna la mappa
        void set_mappa(string nome){
            this->mappa_.push_back(nome);
        }

        // funzione che registra permanenza
        void set_permanenza(int min){
            this->permanenza_a_.push_back(min);
        }

        // funzione che registra minuti cumulativi
        void set_cumulativi(int min){
            this->min_cumu_a_.push_back(min);
        }

        // funzione che ritorna id
        const int& get_id() const {
            return this->id_;
        }

        // funzione che ritorna vettore di tempi di permanenza
        const vector<int>& get_permanenza() const {
            return this->permanenza_a_;
        }

        // funzione che ritorna vettore di tempi cumulativi
        const vector<int>& get_cumulativi() const {
            return this->min_cumu_a_;
        }

        // funzione che ritorna il carico 
        unordered_map<string, int>& get_beni(){
            return this->carico_;
        }

        // funzione che ritorna la mappa del tragitto
        const vector<string>& get_mappa(){
            return this->mappa_;
        }
};

class Company{

    private:

        unordered_map<int, Viaggio*> trip_; // database viaggi: id, viaggio
        unordered_map<string, Warehouse*> warehouse_; // database magazzini: nome città, Warehouse
        unordered_map<string, Customs*> customs_; // database dogane: nome, Customs
        unordered_map<string, Connection*> connection_; // database connection: nome città_partenza, connection

    public:

        // costruttore company
        Company(){}

        // distruttore company
        ~Company(){
            cout << "DEBUG: Distruttore company" << endl;
            for(std::pair<const string, Warehouse*> w : this->warehouse_){
                delete w.second;
            }
            for(std::pair<const string, Customs*> a : this->customs_){
                delete a.second;
            }
            for(std::pair<const int, Viaggio*> v : this->trip_){
                delete v.second;
            }
            for(std::pair<const string, Connection*> c : this->connection_){
                delete c.second;
            }
        }

        // funzione cha aggiunge warehouse
        void add_warehouse(const string& citta, const unordered_map<string, int>& ware){
            Warehouse* war = new Warehouse(citta, ware);
            this->warehouse_[citta] = war;
            cout << "DEBUG: Adding warehouse " << this->warehouse_[citta]->get_citta() << endl;
        }

        // funzione cha aggiunge customs
        void add_customs(const string& citta, const unordered_map<string, int>& ware){
            Customs* war = new Customs(citta, ware);
            this->customs_[citta] = war;
            cout << "DEBUG: Adding customs " << this->customs_[citta]->get_citta() << endl;
        }

        // funzione che aggiunge connection
        void add_connection(string partenza, string arrivo, int lungh){
            Connection* co = new Connection{partenza, arrivo, lungh};
            this->connection_[partenza] = co;
            cout << "Adding connection from " << this->connection_[partenza]->citta_partenza << " to " << this->connection_[partenza]->citta_arrivo << endl;
        }

        // funzione che crea un id viaggio
        const int create_trip(){
            Viaggio* via = new Viaggio(this->trip_.size());
            this->trip_[via->get_id()] = via;
            cout << "DEBUG: creating trip: " << via->get_id() << endl;
            return via->get_id();
        }

        void load(int trip_id, string citta, const unordered_map<string, int>& carico){
            
            int min = 0;
            int min_a = 0;

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
                cout << "\t" << d.first << " : " << d.second << endl;
            }
            cout << "}" << endl;

            // aggiorna mappa
            this->trip_[trip_id]->set_mappa(citta);

            // aggiorna carico
            this->trip_[trip_id]->set_carico(carico);

            // calcolo tempo di permanenza
            for(std::pair<const string, int> c : carico){
                min += MIN_DELAY * c.second;
            }

            // aggiorna tempo di permanenza
            this->trip_[trip_id]->set_permanenza(min);

            // calcolo tempo cumulativo
            for(int v : this->trip_[trip_id]->get_permanenza()){
                min_a += v;
            }

            // aggiorna tempo cumulativo
            this->trip_[trip_id]->set_cumulativi(min_a);

            // aggiornamento magazzino
            for(std::pair<const string, int> c : carico){
                if(this->warehouse_[citta]->get_beni().count(c.first) == 1){
                    this->warehouse_[citta]->get_beni()[c.first] -= c.second;
                }
            }
            cout << "DEBUG: Dopo carico, beni presenti in magazzino:" << endl;
            for(std::pair<const string, int> g : this->warehouse_[citta]->get_beni()){
                cout << g.first << " " << g.second << endl;
            }
        }

        void check_in(int id, string nome){
            
            cout << "DEBUG: plan check_in for trip " << id << " at location " << nome << endl;

            int min = 0;
            int min_a = 0;

            // aggiorna mappa
            this->trip_[id]->set_mappa(nome);

            // calcolo tempo di permanenza
            if(this->customs_.count(nome) == 1){
                for(std::pair<const string, int> c : this->trip_[id]->get_beni()){
                    
                        if(this->customs_.at(nome)->get_beni().count(c.first) == 1){
                            min += (c.second * this->customs_.at(nome)->get_beni().at(c.first));
                        } else {
                            min += (c.second * MIN_DELAY);
                        }
                    
                }
            } else {
                throw std::invalid_argument("Dogana non registrata");
            }

            // aggiorna tempo di permanenza
            this->trip_[id]->set_permanenza(min);

            // calcolo tempo cumulativo
            for(int v : this->trip_[id]->get_permanenza()){
                min_a += v;
            }

            // aggiorna tempo cumulativo
            this->trip_[id]->set_cumulativi(min_a);

        }

        void rest(int id, string nome){
            
            cout << "DEBUG: plan rest for trip " << id << " at location " << nome;

            // aggiorna mappa
            this->trip_[id]->set_mappa(nome);

            int min = RIPOSO;
            int min_a = 0;

            // aggiorna tempo di permanenza
            this->trip_[id]->set_permanenza(min);

            // calcolo tempo cumulativo
            for(int v : this->trip_[id]->get_permanenza()){
                min_a += v;
            }

            // aggiorna tempo cumulativo
            this->trip_[id]->set_cumulativi(min_a);

            cout << " tempo di permanenza: " << min << endl;
        }

        void ship(const int trip_id, const string citta, const unordered_map<string, int>& carico){

            // aggiorna mappa
            this->trip_[trip_id]->set_mappa(citta);

            // check carico sul camion
            for(std::pair<const string, int> c : carico){
                if(this->trip_.at(trip_id)->get_beni().count(c.first) != 1){
                    throw std::invalid_argument(string("Carico non presente sul camion: ") + c.first);
                }
            }

            // aggiornamento magazzino
            for(std::pair<const string, int> c : carico){
                if(this->warehouse_[citta]->get_beni().count(c.first) == 1){
                    this->warehouse_[citta]->get_beni()[c.first] += c.second;
                }
            }
            for(std::pair<const string, int> g : this->warehouse_[citta]->get_beni()){
                cout << g.first << " " << g.second << endl;
            }

            // aggiornamento carico sul camion
            for(std::pair<const string, int> c : carico){
                if(this->trip_.at(trip_id)->get_beni().count(c.first) != 1){
                    this->trip_[trip_id]->get_beni()[c.first] -= c.second;
                }
            }
            for(std::pair<const string, int> c : this->trip_.at(trip_id)->get_beni()){
                cout << "DEBUG: Dopo scarico, beni presenti in magazzino:" << endl;
                cout << c.first << " " << c.second << endl;
            }

            // aggiornamento magazzino
            for(std::pair<const string, int> c : carico){
                if(this->warehouse_[citta]->get_beni().count(c.first) == 1){
                    this->warehouse_[citta]->get_beni()[c.first] -= c.second;
                }
            }
            for(std::pair<const string, int> g : this->warehouse_[citta]->get_beni()){
                cout << g.first << " " << g.second << endl;
            }
        }
///
        string trip_to_string(int id){
            stringstream ss;
            ss << "Stop:\t\t";
            for(string s : this->trip_[id]->get_mappa()){
                ss << s << "\t\t";
            }
            ss << endl;
            ss << "permanenza" << endl;
            ss << "attesa:\t\t";
            for(int i : this->trip_[id]->get_permanenza()){
                ss << i << "\t\t";
            }
            ss << endl;
            ss << "effettiva:\t\t";
            ss << endl;
            ss << "min cumulativi" << endl;
            ss << "attesi:\t\t";
            ss << endl;
            ss << "effettivi:\t\t";
            for(int j : this->trip_[id]->get_cumulativi()){
                ss << j << "\t\t";
            }
            return ss.str();
        }

};

#endif // COMPANY_H