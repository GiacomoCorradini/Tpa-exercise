#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <ostream>

using std::vector;
using std::deque;
using std::string;
using std::stringstream;
using std::unordered_map;
using std::endl;
using std::cout;
using std::ostream;

class Task{

    private:

        char uno_;
        int due_;

    public:

        Task(const char& c, const int& i) : uno_(c), due_(i) {
            cout << "DEBUG: Constructor, add task" << endl;
        }

        ~Task() {
            cout << "DEBUG: Destructor, delete task" << endl;
        }

        const char& first() const {
            return this->uno_;
        }

        const int& second() const {
            return this->due_;
        }
};

class Impiegato{
    
    private:

        char name_;
        int rank_;
        deque<Task*> tasks_;

    public:

        Impiegato(const char& name, const int& rank, deque<Task*> tasks = {}) : name_(name), rank_(rank), tasks_(tasks) {
            cout << "DEBUG: Constructor, add impiegato" << endl;
        }

        ~Impiegato() {
            cout << "DEBUG: delete Impiegato" << endl;
            for(Task* a : this->tasks_){
                delete a;
            }
        }

        const char& get_name() const {
            return this->name_;
        }

        const int& get_rank() const {
            return this->rank_;
        }

        deque<Task*>& get_tasks(){
            return this->tasks_;
        }

};

class Company{

    private:

        vector<Impiegato*> impiegati_;

    public:

        Company() {
            cout << "DEBUG: constructor company" << endl;
            this->impiegati_ = {};
        }

        ~Company() {
            cout << "DEBUG: delete Company" << endl;
            for(Impiegato* f : this->impiegati_){
                delete f;
            }
        }

        void add_employee(char c, int i){
            for(Impiegato* im : this->impiegati_){
                if(c == im->get_name()){
                    throw std::runtime_error(string("Employ named: ") + im->get_name() + string(" already exist"));
                }
                if(i == im->get_rank()){
                    throw std::runtime_error(string("Employ with rank: ") + std::to_string(im->get_rank()) + string(" already exist"));
                }
            }
            Impiegato* ret = new Impiegato(c, i);
            
            this->impiegati_.push_back(ret);
        }

        string printmap(const deque<Task*> map) const {
            stringstream os;
            int i = 0;
            for(Task* n : map){
                if(i > 0){
                    os << ", ";
                }
                os << "('" << n->first() << "' , " << n->second() << ")";
                i++;
            }
            return os.str();
        }

        friend ostream& operator<<(ostream& os, const Company& c){
            os << "Company: " << endl;
            os << "name\t" << "rank\t" << "tasks" << endl;
            for(Impiegato* a : c.impiegati_){
                os << a->get_name() << "\t" << a->get_rank() << "\t";
                os << "[" << c.printmap(a->get_tasks()) << "]" << endl;
            }
            return os;
        }

        void add_task(char task_name, int task_rank, char employee_name){
            Task* cc = new Task(task_name, task_rank);
            int i = 0;
            for(Impiegato* im : this->impiegati_){
                if(im->get_name() == employee_name){
                    im->get_tasks().push_back(cc);
                    i = 1;
                }
            }
            if(i == 0){
                throw std::invalid_argument("Employee doesn't exist");
            }
        }

};