#pragma once
#include <iostream>
#include <algorithm>
#include <concepts>
#include<list>
#include <vector>
#include "lifo.hpp"
#include "fifo.hpp"
#include "graph.hpp"
#include "edge.hpp"
using namespace std;

template<typename T, typename Container>
unidirected_graph<T> graph_visit(unidirected_graph<T>& G, int sorgente, Container& contenitore){
    unidirected_graph<T> albero_ris;
    int n=G.all_nodes().size();
    vector<bool> nodi_vis(n+1,false); //tengo conto dei nodi da cui sono passata(reached)

    contenitore.put(sorgente);

    while(!contenitore.empty()){
        T nodo=contenitore.get();
        nodi_vis[nodo]=true;
        for(const auto& vicino: G.neighbours(nodo)){
            if(!nodi_vis[vicino]){
                contenitore.put(vicino);
                nodi_vis[vicino]=true;
                albero_ris.add_edge(nodo,vicino);
            }
        }
    }
    return albero_ris;
}

template<typename T>
void ricors_helper(const unidirected_graph<T>& G, T nodo, vector<bool>& nodi_vis,unidirected_graph<T>& albero_ris){
    for(const T& vicino : G.neighbours(nodo)){
        if(!nodi_vis[vicino]){
            nodi_vis[vicino] = true;
            albero_ris.add_edge(nodo,vicino);
            ricors_helper(G, vicino,nodi_vis,albero_ris);
        }
    }
}


template<typename T>
unidirected_graph<T> recursive_dfs(unidirected_graph<T>& G,const T& sorgente){
    unidirected_graph<T> albero_ris;
    int n=G.all_nodes().size();
    vector<bool> nodi_vis(n+1,false);
    nodi_vis[sorgente]=true;
    ricors_helper(G,sorgente,nodi_vis,albero_ris);
    return albero_ris;
}




