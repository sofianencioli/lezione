#pragma once
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include "edge.hpp"
#include <concepts>
using namespace std;

template <typename T> requires integral<T>
class unidirected_graph {
    set<unidirected_edge<T>> archi;
    map<T, set<T>> lista_ad;
public:
    //default
    unidirected_graph() {};
    //copia
    unidirected_graph(const unidirected_graph& other){
        archi = other.archi;
        lista_ad= other.lista_ad;
    }
    // metodo che dato un nodo restituisce i suoi vicini
    set<T> neighbours(const T& n) const{
        //vado a cercare il nodo nella lista
        if (lista_ad.count(n)>0){
            return lista_ad.at(n);
        }
        //metto anche il caso che non abbianodi vicini(restituisce niente)
        return{};
    }
    //metodo che permetta di aggiungere un arco al grafo
    void add_edge(const T& u, const T& v){
        //faccio nuovo arco 
        unidirected_edge<T> arco_nuovo(u,v);
        archi.insert(arco_nuovo);
        //lo metto nella lista di adiacenza
        lista_ad[u].insert(v);
        lista_ad[v].insert(u);
    }
    // metodo che restituisce tutti gli archi
    set<unidirected_edge<T>> all_edges() const{
        return archi;
    }
    // metodo che restituisce tutti i nodi
    set<T> all_nodes() const{
        set<T> nodi;
        for (auto& [node, neighbours]: lista_ad){
            nodi.insert(node);
        }
        return nodi;
    }
    // metodo  che dato un arco restituisce la sua numerazione all’interno del grafo
    int edge_number(const unidirected_edge<T>& arco) const{
        int count = 0;
        for (const auto& edge : archi){
            if (edge == arco){
                return count; //restituisco la posizione se trovo l'arco
            }
            count = count+1;
        }
        return -1; //se l'arco non c'è esce -1
    }
    // metodo che dato un numero d’arco restituisce il corrispondente oggetto arco nel grafo
    unidirected_edge<T> edge_at(const int& num) const{
        int count = 0;
        for (const auto& edge : archi){
            if (count==num){
                return edge;
            }
            count=count+1;
        }
        return unidirected_edge<T>(); //esce un arco vuoto se num>posizione ultimo arco
    }
    // operazione che permette di calcolare la differenza tra due grafi
    //creo un grafo che abbia gli stessi nodi di G ma gli archi che G' NON ha
    unidirected_graph<T> operator-(const unidirected_graph<T>& other) const{
        unidirected_graph<T> diff_g;
        set<T> nodi=all_nodes(); //così salvo i nodi di G
        for(const auto& u:nodi){
            set<T> vicini=neighbours(u);//così salvo i vicini di u
            for (const auto& v:vicini){
                unidirected_edge<T> arco(u,v);
                if (other.edge_number(arco)==-1){//aggiungo l'arco solo se non lo trovo in G'
                    diff_g.add_edge(u,v);
                }
            }
        }
        return diff_g;
    }
};