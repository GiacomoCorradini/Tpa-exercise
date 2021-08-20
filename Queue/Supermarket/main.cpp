#include <iostream>
#include <Supermarket.h>

int main(){

    // Registrazioni clienti
    Cliente uno("UGOPINO", "UGO", "PINO");
    Cliente due("MARIOABETE", "MARIO", "ABETE");
    Cliente tre("LUCAROSSI", "LUCA", "ROSSI");
    Cliente quattro("ANDREAQUERCIA", "ANDREA", "QUERCIA");
    Cliente cinque("ENRICOLIMONE", "ENRICO", "LIMONE");
    Cliente sei("GIACOMOFRAGOLA", "GIACOMO", "FRAGOLA");
    Cliente sette("MATILDECOCA", "MATILDE", "COCA");
    Cliente otto("RICCARDOCOLA", "RICCARDO", "COLA");
    Cliente nove("STEFANOFANTA", "STEFANO", "FANTA");
    Cliente dieci("ELISASPRITZ", "ELISA", "SPRITZ");
    cout << endl;

    // Creazione supermercato, (tre casse aperte)
    SuperMarket Martinelli = SuperMarket(3);
    cout << endl;

    // entrata clienti nel supermercato
    Martinelli.add_cliente_supermarket(uno);
    Martinelli.add_cliente_supermarket(due);
    Martinelli.add_cliente_supermarket(tre);
    Martinelli.add_cliente_supermarket(quattro);
    Martinelli.add_cliente_supermarket(cinque);
    Martinelli.add_cliente_supermarket(sei);
    Martinelli.add_cliente_supermarket(sette);
    Martinelli.add_cliente_supermarket(otto);
    Martinelli.add_cliente_supermarket(nove);
    Martinelli.add_cliente_supermarket(dieci);
    cout << endl;

    // clienti presenti nel supermercato
    cout << "DEBUG: Clienti presenti al supermercato" << endl;
    cout << endl << Martinelli.as_supermercato() << endl;

    // Apertura casse
    Martinelli.add_queue();
    cout << endl << "DEBUG: Sono aperte: " << Martinelli.size_queue() << " casse" << endl;
    cout << endl;

    // Arrivo dei clienti alla cassa
    Martinelli.enqueue(uno);
    Martinelli.enqueue(due);
    Martinelli.enqueue(tre);
    Martinelli.enqueue(quattro);
    Martinelli.enqueue(cinque);
    Martinelli.enqueue(sei);
    Martinelli.enqueue(sette);
    Martinelli.enqueue(otto);
    Martinelli.enqueue(nove);
    Martinelli.enqueue(dieci);

    // Clienti presenti in coda
    cout << "DEBUG: Clienti presenti alle casse" << endl;
    cout << Martinelli.as_cassa();
    cout << endl;

    // Clienti usciti dal supermercato
    vector<Cliente*> v =  Martinelli.dequeue();
    cout << endl;
    for(Cliente* m : v){
        cout << m->get_nome() << endl;
    }
    cout << endl;

    // clienti presenti nel supermercato
    cout << "DEBUG: Clienti presenti al supermercato" << endl;
    cout << endl;
    cout << Martinelli.as_supermercato() << endl;

    // Clienti presenti in coda
    cout << "DEBUG: Clienti presenti alle casse" << endl;
    cout << Martinelli.as_cassa();
    cout << endl;

}