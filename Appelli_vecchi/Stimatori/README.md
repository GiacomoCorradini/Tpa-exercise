# Libreria Algoritmi di Stima

Scrivere una libreria di algoritmi di stima dello stato di un sistema. Il problema della stima consiste nel cercare di ricostruire lo stato di un sistema (x) a partire dalle misure dei sensori (y). Alcuni algoritmi di stima sfruttano un modello della dinamica del sistema per predire come lo stato dovrebbe evolvere (es: filtro di Kalman). Altri algoritmi di stima più semplici invece non conoscono la dinamica del sistema (es: filtri passa-basso o differenziatori). Indipendentemente da questo, tutti gli algoritmi di stima svolgono lo stesso compito. Ad ogni iterazione del loop di controllo, un algoritmo di stima legge le misure dei sensori (y) e le utilizza per calcolare una stima dello stato attuale del sistema (x). La libreria deve essere progettata in previsione dell'implementazione di un elevato numero di algoritmi di stima, che devono poter essere utilizzati per una serie di test di confronto (deve quindi essere semplice passare dall'utilizzo di un algoritmo ad un altro). 

Come caso particolare di algoritmo di stima, è richiesto di implementare un algoritmo per contare il numero di regioni all'interno di un'immagine data. Ad esempio, nell'immagine sottostante sono presenti 5 regioni.



L'immagine in questo caso funge da misura dei sensori, e deve essere memorizzata nel vettore y, contenente solo valori 0 ed 1. I valori 0 corrispondono ai pixel di sfondo, mentre i valori 1 corrispondono ai pixel delle regioni di interesse. Il vettore y contiene la concatenazione delle righe della matrice dei pixel, partendo dall'angolo in alto a sinistra dell'immagine e procedendo fino all'angolo in basso a destra. Data l'immagine, l'algoritmo deve contare quante regioni sono presenti in essa. Una regione è definita come un insieme di pixel confinanti, tutti di valore 1. Due pixel A e B sono confinanti se A si trova alla destra di B, o alla sinistra di B, o sopra B, o sotto B.

## Esempio

Prendiamo come esempio questa immagine, definita come un vettore di interi:

vector<int> img{0, 1, 0, 0, 0, 0,
                          1, 1, 0, 1, 0, 1,
                	  0, 0, 0, 1, 0, 1,
                	  1, 0, 0, 1, 1, 1,
                	  1, 0, 0, 1, 0, 1};

 In questa immagine sono presenti 3 regioni, e possiamo evidenziarle associando a ciascuna di esse un valore intero differente:

0 2 0 0 0 0
2 2 0 3 0 3
0 0 0 3 0 3
4 0 0 3 3 3
4 0 0 3 0 3
