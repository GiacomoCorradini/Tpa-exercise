# TPA 2020 - Simulatore Multi-Body

Questa repository contiene il testo dell'esame del corso "Tecniche di Programmazione Avanzata" del Dipartimento di Ingegneria Industriale, anno accademico 2019/2020.
Comunicazione per il professore
Inserisci qui eventuali comunicazioni (brevi!) per il professore, come ad esempio:
●	Non sono riuscito a finire l'implementazione per mancanza di tempo, quindi fornisco anche il progetto nel file progetto.pdf
●	Mi ritiro dall'esame

## Istruzioni

L'esercizio consiste nella progettazione e nell'implementazione di un software C++ per la simulazione di un sistema meccanico multi-body. Il software deve essere scritto mediante il paradigma di programmazione ad oggetti, quindi utilizzando ad esempio (ove possibile e sensato):
●	classi
●	incapsulamento
●	ereditarietà
●	polimorfismo
●	passaggio per riferimento
●	passaggio per riferimento costante
●	puntatori
●	metodi const
●	operatori
●	overload
●	valori di default
●	template
Nessun codice di partenza è fornito. Lo studente deve occuparsi sia della progettazione che dell'implementazione. Si consiglia di sottomettere anche il progetto del software, soprattutto se l'implementazione dovesse essere incompleta (ad esempio per mancanza di tempo). Il progetto sarà tenuto in conto nella valutazione finale. Formati accettabili per il progetto sono formati visuali (come pdf o jpeg) o formati testuali semplici (come txt o rtf). Idealmente l'implementazione dovrebbe includere anche una serie di test per verificare il corretto funzionamento del codice scritto.

## Descrizione

Scrivere un software ad oggetti per la simulazione di un sistema fisico composto da corpi puntiformi connessi tra loro tramite molle e smorzatori. Il sistema può essere sviluppato in 1d (ipotizzando quindi che tutte i corpi siano allineati su una retta) oppure in 3d. Lo sviluppo del software in 3d darà un punteggio maggiore, ma anche il caso 1d sarà sufficiente a passare l'esame con un buon voto.
Ogni corpo avrà una massa (costante), una posizione, ed una velocità. Posizione e velocità iniziali saranno specificate dall'utente. Posizione e velocità evolveranno nel tempo in base alle forze applicate ai corpi. Ogni corpo può essere connesso ad uno o più altri corpi tramite molle o smorzatori. Una molla/smorzatore connette due corpi, applicandogli forze uguali e opposte. Più in dettaglio, dato:
●	un corpo A con massa mA, posizione pA, velocità vA
●	un corpo B con massa mB, posizione pB, velocità vB
●	una molla S con rigidezza K, lunghezza (a riposo) p0, che connette A e B
La molla S applicherà ad A una forza fA = K * (pB - pA - p0). Al tempo stesso, la molla S applicherà anche a B una forza fB = - fA. Supponendo invece:
●	un corpo A con massa mA, posizione pA, velocità vA
●	un corpo B con massa mB, posizione pB, velocità vB
●	uno smorzatore R con coefficiente di smorzamento D che connette A e B
Lo smorzatore R applicherà ad A una forza fA = D * (vB - vA). Al tempo stesso, lo smorzatore R applicherà anche a B una forza fB = -fA. Se più molle/smorzatori sono connessi allo stesso corpo, la forze esercitate da ciascun componente si sommano, generando una forza risultante uguale alla somma delle singole forze.
Ad ogni passo di simulazione di durate dt, lo stato di ciascun corpo dovrà essere aggiornato secondo le seguenti equazioni (integrazione di Eulero):
acc = netForce / mass
vel = vel + dt * acc
pos = pos + dt*vel + 0.5*dt*dt*acc

dove netForce è la forza risultante dalla somma delle forze di tutte le molle e gli smorzatori collegati al corpo in questione.
If software deve permettere all'utente di
●	creare corpi specificando massa e posizione/velocità iniziale
●	creare molle specificando la rigidezza e la lunghezza a riposo
●	creare smorzatori specificando lo smorzamento
●	collegare a ciascuna molla/smorzatore due corpi
●	simulare il sistema specificando il tempo totale della simulazione ed il passo di integrazione
Il software dovrebbe essere progettato in modo da essere facilmente estendibile. Ad esempio, dovrebbe essere possibile aggiungere un nuovo tipo di smorzatore che applica una forza proporzionale al segno della velocità relativa tra i due corpi (corrispondente ad un attrito Coulombiano).

### Informazioni Extra

●	la gestione delle liste di elementi può essere implementate tramite array dinamici (quindi utilizzando gli operatori new e delete) oppure mediante std::vector. La prima soluzione sarà premiata in termini di punteggio data la sua maggiore difficoltà.
●	Qualsiasi aspetto non sia esplicitamente specificato nella descrizione dell'esercizio è lasciato alla libera interpretazione dello studente. Scelte più realistiche che portano a software più complesso saranno chiaramente premiata in fase di valutazione.
