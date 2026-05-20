#pragma once
#include <iostream>
#include <algorithm>
#include <concepts>
#include <list>
#include <vector>
#include <limits>
#include "lifo.hpp"
#include "fifo.hpp"
#include "graph.hpp"
#include "edge.hpp"
using namespace std;

template<typename T>
void dijkstra(const unidirected_graph<T>& G, const T& sorgente,const map<pair<T,T>, int>& pesi, map<T,int>& dist,
    map<T,T>& pred){
    
    //inizializzo le distanze a infinito e i predecessori a -1
    for(const auto& nodo:G.all_nodes()){
        dist[nodo]=numeric_limits<int>::max();
    }
    //per il nodo sorgente è invece 0

    dist[sorgente]= 0;
    pred[sorgente] = sorgente;

    //coda con priorità (gli elementi della coda sono i nodi e la priorità è la distanza), la uso per scegliere i cammini minimi
    //'simulo' una coda con priorità come un set che associa nodo a peso
    set<pair<int,T>> priority_queue;
    priority_queue.insert({0,sorgente});

    for (const auto& nodo:G.all_nodes()){
        priority_queue.insert({dist[nodo], nodo});
    }
    while (!priority_queue.empty()){
        auto [d,n]= *priority_queue.begin();
        priority_queue.erase(priority_queue.begin());
        if(d==numeric_limits<int>::max()) break;
        //esamino i vicini
        for (const auto& vicino:G.neighbours(n)){
            int peso_arco=pesi.at({n,vicino});
            if (dist[vicino]> dist[n]+peso_arco){
                //tolgo l'associazione distanza-nodo e la sostituisco con quella piu corta
                priority_queue.erase({dist[vicino],vicino});
                dist[vicino]= dist[n]+peso_arco;
                pred[vicino]=n;
                priority_queue.insert({dist[vicino],vicino});
            }
        }
    }
}