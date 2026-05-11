#include <iostream>
#include "edge.hpp"
#include "graph.hpp"
using namespace std;

int main(void) {
    cout << "test classe degli archi:"<<"\n";
    cout<< boolalpha; //per stampare ìTrue/False
    unidirected_edge<int> arco1(11,7); //vedo se l'ordine dei nodi è giusto
    unidirected_edge<int> arco2(6,18);
    unidirected_edge<int> arco3(7,11);

    cout << "verifica stampa: " << arco1 << "\n";
    cout << "L'arco (7-11) è minore dell'arco (6-18)? "<< (arco1<arco2) << "\n";
    cout << "L'arco (11-7) è uguale all'arco (7-11)? "<< (arco1==arco3) << "\n"<< "\n";

    //creo e stampo i grafi G e G1
    cout << "test classe dei grafi" << "\n";
    unidirected_graph<int> G;
    G.add_edge(2, 6);
    G.add_edge(5, 4);
    G.add_edge(3, 2);
    G.add_edge(6, 1);
    cout<< "grafo G:" << "\n";
    for (const auto& arco : G.all_edges()){
        cout << "arco:"<< arco <<"\n" ;
    }

    unidirected_graph<int> G1;
    G1.add_edge(2,6);
    G1.add_edge(5,4);
    cout<< "\n" << "grafo G1:"<< "\n";
    for (const auto& arco : G1.all_edges()) {
        cout << "arco: " << arco << "\n";
    }
    
    cout<< "\n" << "sottrazioni G-G1:" << "\n";
    cout<< "differenza:"<< "\n";
    unidirected_graph<int> G_diff = G - G1;
    // controllo che rimangano solo gli archi (3-2) e (6-1)
    for (const auto& arco : G_diff.all_edges()) {
        cout << "Arco: " << arco << endl;
    }

    cout<< "\n" << "Verifica vicini di 6 in G:" << "\n";
    set<int> vicini = G.neighbours(6);
    cout << "vicini di 6: ";
    for (int n : vicini) {
        cout << n << " ";   //Verifico che sono 2 e 1
    }

    cout<< "\n" << "aggiungo un arco a G:"<<"\n";
    G.add_edge(2, 1); //Verifico che se aggiungo un arco già presente, non cambia nulla nel mio grafo
    G.add_edge(4, 7);
    cout<< "Grafo G:"<< "\n";
    for (const auto& arco : G.all_edges()) {
        cout << "Arco: " << arco << endl;
    }
    //verifico che mi dia il giusto numero di archi in G (6)
    set<unidirected_edge<int>> set_archi = G.all_edges();
    cout << "\n" <<"In G ci sono " << set_archi.size() <<"archi"<< "\n"; 

    //verifico che mi dia il giusto numero di nodi
    set<int> set_nodi = G.all_nodes();
    cout << "In G ci sono " << set_nodi.size() << "nodi" <<"\n\n"; 

    cout << "verifica posizioni archi:"<< "\n";
    unidirected_edge<int> arco_posizione(3,2);
    int posizione = G.edge_number(arco_posizione);
    cout << "L'arco (3-2) si trova alla posizione: " << posizione << "\n";
    cout << "Verifico che edge_at mi dia lo stesso arco e funzioni:"<<"\n";
    cout << "L'arco alla posizione " << posizione << " è: " << G.edge_at(posizione) << "\n";
}
