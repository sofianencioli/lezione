#pragma once
#include <iostream>
#include <algorithm>
#include <concepts>
#include <vector>
#include <list>
#include <optional>
using namespace std;

template<typename T> 

class fifo {
    list<T> coda;
public:
    //costruttore di default
    fifo() {};
    //metodo put
    void put(const T& new_el){
        coda.push_back(new_el);
    }
    //metodo get
    int get() {
        T x = coda.front();
        coda.pop_front();
        return x;
    }
    //metodo empty
    bool empty() {
        if (coda.size()==0){
            return 1;
        }
        return 0;
    }
};