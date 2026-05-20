#include <iostream>
#include <algorithm>
#include <concepts>
#include <list>
#include <vector>
#include "lifo.hpp"
#include "fifo.hpp"
#include "graph.hpp"
#include "edge.hpp"
#include "dijkstra.hpp"
#include "graph_visit.hpp"
using namespace std;

int main(void) {
    unidirected_graph<int> G;
    G.add_edge(2,6);
    G.add_edge(3,5);
    G.add_edge(4,3);
    G.add_edge(7,2);
    G.add_edge(6,7);
    G.add_edge(5,1);
    G.add_edge(1,4);
    G.add_edge(4,7);
    G.add_edge(6,3);

    //faccio i test DFS e BFS
    lifo<int> p;
    auto dfs_G=graph_visit(G,1,p);
    cout<<"Albero della DFS:"<<"\n";
    for(const auto& edge: dfs_G.all_edges()){
        cout<< edge<< "\n";
    }
    fifo<int> c;
    auto bfs_G=graph_visit(G,1,c);
    cout<<"Albero della BFS:"<<"\n";
    for(const auto& edge: bfs_G.all_edges()){
        cout<< edge<< "\n";
    }
    //faccio anche il test della DFS ricorsiva
    auto albero_ricorsiva=recursive_dfs(G,1);
    cout<<"Albero della DFS ricorsiva:"<<"\n";
    for(const auto& edge: albero_ricorsiva.all_edges()){
        cout<< edge<< "\n";
    }
    //testo l'algoritmo Dijkstra
    map<pair<int, int>,int> pesi;
    for (const auto& nodo: G.all_nodes()){
        for(const auto& vicino: G.neighbours(nodo)){
            pesi[{nodo,vicino}]=1;
        }
    }
    map<int, int> dist;
    map<int,int> pred;
    dijkstra(G,1, pesi,dist, pred);
    for(int i=1; i<9; i=i+1){
        cout << "Nodo: " << i << "\n"<<"Distanza minima da 1(sorgente): "<<dist[i]<<"\n"<<"Nodo precedente: "<<pred[i]<<"\n\n";

    }

}