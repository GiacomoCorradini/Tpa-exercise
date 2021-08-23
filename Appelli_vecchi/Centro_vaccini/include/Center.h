#ifndef CENTER_H
#define CENTER_H

#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>
#include <vector>

#include <vaxlib.h>

using std::string;
using std::pair;
using std::deque;
using std::unordered_map;
using std::vector;

// classe paziente
class Pazienti{
    
    private:
    
        string cf_; // codice fiscale 
        string nome_; // nome paziente
        string cognome_; // cognome paziente
        Date data_nascita_; // data di nascita
        vector<string> allergie_; // allergie del paziente
        pair<string, int> vaccino_; // nome vaccino, numero di iniezioni 
    
    public:
        
        // costruttore per registrare paziente
        Pazienti(const string& cf, const string& nome, const string& cognome, const Date& data_nascita, const vector<string>& allergie) : 
        cf_{cf}, nome_{nome}, cognome_{cognome}, data_nascita_{data_nascita}, allergie_{allergie}, vaccino_{"", 0} {}

        const string& get_cf() const { // funzione che ritorna il codice fiscale
            return this->cf_;
        }
        const string& get_nome() const { // funzione che ritorna il nome
            return this->nome_;
        }
        const string& get_cognome() const { // funzione che ritorna il cognome
            return this->cognome_;
        }
        const Date& get_data_nascita() const { // funzione che ritorna la data di nascita
            return this->data_nascita_;
        }
        const vector<string>& get_allergie() const { // funzione che ritorna le allergie del paziente
            return this->allergie_;
        }

        const pair<string, int>& get_vax() const { // funzione che ritorna il nome vaccino (first) e il numero di iniezioni
            return this->vaccino_;
        }

        void set_vaccino(const string vax){ // funzione che registra il nome del vaccino
            if(vax == ""){
                throw std::invalid_argument("Vaccino non registrato");
            }
            this->vaccino_.first = vax;
        }
        void set_n_iniezione(){ // funzione che registra l'avvenuta vaccinazione
            this->vaccino_.second +=1;
        }

        // Funzione che calcola l'età del paziente
        int eta(const Date oggi){
            int eta = oggi.year - this->data_nascita_.year - 1;
            if(oggi.month <= data_nascita_.month && oggi.day <= data_nascita_.day){
                eta++;
            }
            if(eta < 0){
                throw std::invalid_argument(string("Età non valida"));
            }
            return eta;
        }
};

// classe checkin
class Checkin{
    private:

        int numero_; // numero checkin
        deque<Pazienti*> check_; // coda di pazienti
    
    public:

        // costruttore di checkin
        Checkin(const int& code): numero_(code) {}

        const int get_size() const { // funzione che ritorna la lunghezza della coda
            return this->check_.size();
        }

        void push_back(Pazienti* q){ // funzione che aggiunge un paziente alla fine della coda
        if(q == NULL){
            throw std::invalid_argument("Paziente non registrato");
        }
            this->check_.push_back(q);
        }

        void pop_front(){ // funzione che toglie un paziente all'inizio della coda
            this->check_.pop_front();
        }

        const int& get_numero_() const { // funzione che ritorna il numero della coda
            return this->numero_;
        }

        deque<Pazienti*>& get_deque(){ // funzione che ritorna la coda
            return this->check_;
        }
};

// classe injection points
class Injection_points : public Checkin {
    
    private:

        Vaccine vax_; // dose di vaccino somministrato nell'injection point
        int dosi_; // numero di dosi

    public:
        
        // costruttore di injection points
        Injection_points(const int& code, const int& dose, const Vaccine& vax) : Checkin(code), dosi_(dose), vax_(vax) {}

        void set_vax(const Vaccine& vaz){ // funzione set vax
        if(vaz.name == ""){
            throw std::invalid_argument("Vaccino non registrato");
        }
            this->vax_ = vaz;
        }

        void set_dose(const int dose){ // funzione set dose
        if(dose == 0){
            throw std::invalid_argument("Nessuna dose di vaccino presente");
        }
            this->dosi_ = dose;
        }

        const Vaccine& get_vax() const { // funzione ritorna vax
            return this->vax_;
        }

        const int& get_dose() const { // funzione che ritorna dose
            return this->dosi_;
        }
};

// classe center, classe disponibile all'utente
class Center{
    
    private:
        
        bool on_off; // apertura, chiusura centro vaccinale
        unordered_map<string, Appointment*> app_; // database di appuntamenti (cf, appointment)
        unordered_map<string, Injection_points*> vax_; // database di injection points (vax_name, vaccine)
        unordered_map<string, Pazienti*> pazienti_; // database di pazienti (cf, pazienti)
        vector<Checkin*> check_; // vettore di checkin
        vector<Injection_points*> inj_; // vettore di injection points
        Date data_; // data
        Time tempo_; // tempo

    public:

        // costruttore centro vaccinale
        Center() {
            this->on_off = false;
            cout << "DEBUG: constructor, center" << endl;
        }

        void add_checkin(){ // funzione che aggiunge checkin
            Checkin* c = new Checkin(check_.size());
            this->check_.push_back(c);
            cout << "Adding checkin " << c->get_numero_() << endl;
        }

        void add_injection_point(Vaccine vax, int i){ // funzione che aggiunge un Injection_points
            Injection_points* in = new Injection_points(inj_.size(), i, vax);
            this->inj_.push_back(in);
            cout << "Opening injection point for " << vax << endl;
            this->vax_[vax.name] = in;
        }

        // funzione che registra paziente al database
        void add_patient(string cf, string name, string surname, Date date, vector<string> allergie){
            if(this->pazienti_.count(cf) == 1){
                throw std::invalid_argument("Paziente già presente");
            }
            Pazienti* paz = new Pazienti(cf, name, surname, date, allergie);
            this->pazienti_[paz->get_cf()] = paz;
            cout << "Adding patient " << paz->get_cf() << endl;
        }

        Appointment book(string cf, Date data, Time time, string vax){
            cout << " booking " << cf << " at " << data << " " << time << " for vaccine " << vax << endl;
            Appointment* ret = new Appointment{cf,
                 this->vax_[vax]->get_vax().code,
                 this->vax_[vax]->get_vax().name,
                 data, 
                 time, 
                 this->vax_[vax]->get_vax().injections,
                 false};
            this->app_[cf] = ret;
            this->pazienti_[cf]->set_vaccino(vax);
            return *ret;
        }

        void open(Date data, Time time){
            this->on_off = true;
            this->data_ = data;
            this->tempo_ = time;
            cout << "**** Opening at " << data_ << ", " << tempo_ << " ****" << endl;
        }

        void close(){
            this->on_off = false;
            cout << "**** Closing, everybody leaves ****" << endl;
        }

        void enqueue(Appointment app){
            cout << "enqueing " << app << " at checkin " << app.vaccine_code << endl;
            Pazienti* paz = this->pazienti_[app.fiscal_code];
            int siz = this->check_[0]->get_size();
            int i = 0;
            int min = 0;
            for(Checkin* v : this->check_){
                if(v->get_size() <= siz){
                    siz = v->get_size();
                    min = i;
                }
                i++;
            }
            this->check_[min]->push_back(paz);
        }

        vector<string> dequeue(){
            
            vector<string> ret;

            cout << "dequeuing injections" << endl;
            for(Injection_points* in : this->inj_){
                if(in->get_size() == 0) continue;
                Pazienti* ex_paz = in->get_deque().front();
                in->pop_front();
                ret.push_back(ex_paz->get_nome());
                cout << "Injected " << ex_paz->get_cf() << " with " << ex_paz->get_vax().first << endl;
            }

            cout << "dequeuing checkin" << endl;
            for(Checkin* che : this->check_){
                if(che->get_size() == 0) continue;
                Pazienti* ex_pa = che->get_deque().front();
                che->pop_front();
                this->vax_[ex_pa->get_vax().first]->push_back(ex_pa);
            }

            return ret;
        }

        friend ostream& operator<<(ostream& os, const Center& center);
};

inline ostream& operator<<(ostream& os, const Center& center){
    os << "Center:" << endl;
    os << "\t" << "Check-in" << endl;
    for(Checkin* c : center.check_){
        os << c->get_numero_() << ":";
        for(Pazienti* p : c->get_deque()){
            os << "\t" << p->get_cf() << "\t";
        }
        os << endl;
        for(Pazienti* pp : c->get_deque()){
            os << "  \t" << pp->get_vax().first << "\t";
        }
        os << endl;
        for(Pazienti* ppp : c->get_deque()){
            os << "  \t" << center.vax_.at(ppp->get_vax().first)->get_vax().injections << "\t";
        }      
        os << endl;
    }
    os << "\t" << "Injection points" << endl;
    for(Injection_points* d : center.inj_){
        os << d->get_numero_() << ": ";
        for(Pazienti* i : d->get_deque()){
            os << "\t" << i->get_cf() << "\t";
        }
        os << endl;
        for(Pazienti* ii : d->get_deque()){
            os << "  \t" << ii->get_vax().first << "\t";
        }
        os << endl;
    }
    return os;
}


#endif // CENTER_H