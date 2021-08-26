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