#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_map>

using std::vector;
using std::deque;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::endl;
using std::cout;

class Cliente{

    private:

        string cf_;
        string nome_;
        string cognome_;

    public:

        Cliente() {}
        Cliente(const string cf, const string nome, const string cognome) : cf_{cf}, nome_{nome}, cognome_{cognome} {
            cout << "DEBUG: cliente registrato" << endl;
        }

        ~Cliente(){
            cout << "DEBUG: Distruttore cliente" << endl;
        }

        void set_cf(const string& cf){
            this->cf_ = cf;
        }
        void set_nome(const string& nome){
            this->nome_ = nome;
        }
        void set_cognome(const string& cognome){
            this->cognome_ = cognome;
        }

        const string& get_cf() const {
            return this->cf_;
        }
        const string& get_nome() const {
            return this->nome_;
        }
        const string& get_cognome() const {
            return this->cognome_;
        }

        string as_string(){
            stringstream ss;
            ss << "Cliente:" << endl;
            ss << "\tNome: " << this->get_nome() << endl;
            ss << "\tCognome: " << this->get_cognome() << endl;
            ss << "\tCodice fiscale: " << this->get_cf() << endl;
            return ss.str();
        }

};

class SuperMarket{
    
    private:

        unordered_map<string, Cliente*> clienti;
        vector<deque<Cliente*>> casse;

    public:
        SuperMarket(int n = 1){
            cout << "DEBUG: Apertura supermercato, ci sono: " << n << " casse aperte" << endl;
            for(int i = 0; i < n; i++){
                this->casse.push_back({});
            }
            this->clienti = {};
        }

        SuperMarket(const vector<deque<Cliente* >>& icasse){
            if(icasse.size() == 0){
                throw std::invalid_argument(string("Ho bisogno di almeno una cassa, casse aperte: ") + std::to_string(icasse.size()));
            }
            cout << "DEBUG: Apertura supermercato, ci sono: " << icasse.size() << " casse aperte" << endl;
            this->casse = icasse;
            this->clienti = {};
        }

        ~SuperMarket() {
            cout << "DEBUG: Distruttore supermercato" << endl;
            for(std::pair<const string, Cliente*>& cli : this->clienti){
                delete cli.second;
            }
        };

        void add_cliente_supermarket(const Cliente& client){
            if(this->clienti.count(client.get_nome()) == 1){
                throw std::invalid_argument(string("Cliente: ") + client.get_nome() + string(" già presente in supermarket"));
            } else {
                cout << "DEBUG: Cliente aggiunto al supermercato" << endl;
                this->clienti[client.get_nome()] = new Cliente(client);
            }
        }

        void add_queue(deque<Cliente*>& cassa){
            cout << "DEBUG: Apertura di: " << cassa.size() << "casse" << endl;
            this->casse.push_back(cassa);
        }

        void add_queue(){
            cout << "DEBUG: Apertura di un'altra cassa" << endl;
            this->casse.push_back({});
        }

        int size_queue(){
            return this->casse.size();
        }

        void enqueue(Cliente& client){
            if(this->clienti.count(client.get_nome()) == 0){
                throw std::invalid_argument("Cliente non presente nel supermercato");
            } else {
            cout << "DEBUG: Cliente: " << client.get_nome() << " alla cassa" << endl;
            Cliente* pc = this->clienti[client.get_nome()];

            int siz = this->casse[0].size();
            int i = 0;
            int min = 0;
            for(deque<Cliente*> cassa : this->casse){
                if(cassa.size() <= siz){
                    siz = cassa.size();
                    min = i;
                }
                i++;
            }

            this->casse[min].push_back(pc);
            }
        }

        void dequeue_super(vector<Cliente*> deq){
            for(Cliente* cli : deq){
                this->clienti.erase(cli->get_nome());
            }
        }

        vector<Cliente*> dequeue(){
            cout << "DEBUG: clienti usciti dal supermercato" << endl;;
            vector<Cliente*> deq;
            for(deque<Cliente*>& cassa : this->casse){
                deq.push_back(cassa.front());
                cassa.pop_front();
            }
            dequeue_super(deq);
            return deq;
        }

        string as_cassa(){
            stringstream ss;
            int i = 0;
            for(deque<Cliente*> cassa : this->casse){
                ss << endl; 
                ss << i << " Cash queue: [";
                for(Cliente* c : cassa){
                    ss << "'" << c->get_nome() << "'" << ",";
                }
                ss << "]";
                i++;
            }
            ss << endl;
            return ss.str();
        }

        string as_supermercato(){
            stringstream ss;
            for(std::pair<const string, Cliente*>& su : this->clienti){
                ss << su.first << " , " << su.second->get_cognome() << endl;
            }
            return ss.str();
        }
        
};