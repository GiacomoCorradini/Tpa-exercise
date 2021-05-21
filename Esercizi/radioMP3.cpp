#include <iostream>
using namespace std;

class radioMP3 {
    private:
        int frequenza;
        int volume;
    public:
        radioMP3(int frequenza, int volume)
        {
            this->frequenza = frequenza;
            this->volume = volume;
        }
        void iniziare();
        void AumentareFrequenza();
        void DiminuireFrequenza();
        void AbbassareVolume();
        void AlzareVolume();
        void StampaFrequenza();
        void StampaVolume();
};

void radioMP3::iniziare()
{
    // inizializzare attributi di frequenza e volume
    frequenza = 99.99;
    volume = 45;
}

void radioMP3::AlzareVolume()
{
    // incrementare di un'unità il volume
    volume++;
}

void radioMP3::AbbassareVolume()
{
    // diminuire di un'unità il volume
    volume--;
}

void radioMP3::DiminuireFrequenza()
{
    // diminuire frequenza 1 Mhz
    frequenza--;
}

void radioMP3::AumentareFrequenza()
{
    // aumentare frequenza 1 Mhz
    frequenza++;
}

void radioMP3::StampaFrequenza()
{
    // stampa il valore della frequenza
    cout << frequenza << endl;
}

void radioMP3::StampaVolume()
{
    // stampa il valore del volume
    cout << volume << endl;
}

int main(){
    radioMP3 miaStazione(99.9, 45);

    //miaStazione.iniziare();
    miaStazione.AlzareVolume();
    miaStazione.AbbassareVolume();
    miaStazione.AumentareFrequenza();
    miaStazione.DiminuireFrequenza();
    miaStazione.StampaFrequenza();
    miaStazione.StampaVolume();

    return 0;
}