#include <iostream>
#include <vector>
#include <cstdlib> //per usare rand()
#include "randfiller.hpp"
#include "sorting.hpp"
using namespace std;

int main(void) {
    randfiller rf;
    for (int i=0 ; i<100; i = i+1){
        vector<int> vi;
        int dimensione=rand() %500; //dimensione casuale fino a 9999
        vi.resize(dimensione);
        rf.fill(vi,-500,500);
        selection_sort(vi);
        if (!is_sorted(vi)){
            return EXIT_FAILURE;
        }
    }
    vector<string> vstring= {"ciao","sofia","io","calcolo","programmazione","luca","fisica","delia","pasqua","buona","auguri"};
    selection_sort(vstring);
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
