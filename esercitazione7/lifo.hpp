#pragma once
#include <iostream>
#include <algorithm>
#include <concepts>
#include <list>
#include <optional>
using namespace std;

template<typename T> 
class lifo {
    list<T> pila;
public:
    //costruttore di default
    lifo() : pila(0){}
    //metodo put
    void put(const T& new_el){
        pila.push_front(new_el);
    }
    //metodo get
    T get() {
        T x = pila.front();
        pila.pop_front();
        return x;
    }
    //metodo empty
    bool empty() const{
        if (pila.size()==0){
            return 1;
        }
        return 0;
    }
};