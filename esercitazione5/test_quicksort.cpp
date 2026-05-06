#include <iostream>
#include <vector>
#include <cstdlib> //per usare rand()
#include "randfiller.hpp"
#include "sorting.hpp"
using namespace std;

int main(void) {
    randfiller rf;
    for (int i=1 ; i<=100; i = i+1){
        vector<int> vi;
        int dimensione=rand() %10000; //dimensione casuale fino a 9999
        vi.resize(dimensione);
        rf.fill(vi,-500,500);
        quick_sort(vi,0,dimensione-1);
        if (!is_sorted(vi)){
            return EXIT_FAILURE;
        }
    }
    vector<string> vstring= {"ciao","sofia","io","calcolo","programmazione","luca","fisica","delia","pasqua","buona","auguri"};
    quick_sort(vstring,0, 10);
    for (int j = 0; j<10;j = j+1){
        cout<< vstring[j] << " , ";
    }
    cout<< "\n";
    if (!is_sorted(vstring)){
        cout<<"sbagliato"<<"\n";
            return EXIT_FAILURE;
        }
        cout <<"giusto"<<"\n";
    return EXIT_SUCCESS;
}
