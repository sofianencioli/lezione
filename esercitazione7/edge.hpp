#pragma once
#include <iostream>
#include <algorithm>
#include <concepts>
using namespace std;

template <typename T> requires integral<T>
class unidirected_edge {
    T u;
    T v;
public:
    //default 
    unidirected_edge(): u(0), v(0) {} 

    unidirected_edge(const T& n1, const T& n2){
        u=min(n1,n2);
        v=max(n1,n2);
    }
    T from() const {
        return u;
    }
    T to() const {
        return v;
    }
    //definisco operatore ==
    bool operator==(const unidirected_edge<T>& other ) const{
        return u == other.u && v == other.v;
    }
    //definisco operatore <
    bool operator<(const unidirected_edge<T>& other ) const {
        if (u != other.u) {
            return u<other.u;
        }
        return v<other.v;
    }
};

//definisco l'operazione stampa 
template<typename T>
ostream&
operator<<(ostream& os, const unidirected_edge<T>& nodo){
    os<< nodo.from() << "-" << nodo.to() << "\n";
    return os;
}
