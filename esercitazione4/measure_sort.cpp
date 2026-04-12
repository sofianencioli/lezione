#include "timecounter.hpp"
#include "sorting.hpp"
#include "randfiller.hpp"
#include <iostream>
#include <thread>
#include <algorithm> //
#include <chrono>
using namespace std;

int main(void)
{
    timecounter tc;
    randfiller rf;
    for (int i=4; i<=8192 ;i=2*i){
        vector<int> vt(i);
        rf.fill(vt,-500,500);
        //qua avevo sbagliato perchè non avendo inizializzato i vari vettori, dopo aver ordinato con bubblesort gli altri ordinavano il vettore già ordinato, quindi i tempi non erano veritieri
        vector<int> vt_bubble = vt;
        vector<int> vt_insertion = vt;
        vector<int> vt_selection = vt;
        vector<int> vt_sort = vt;
        //misuro ora i tempi di bubble, insertion, selection e sort
        tc.tic();
        bubble_sort(vt_bubble);
        double time_bubble=tc.toc();

        tc.tic();
        insertion_sort(vt_insertion);
        double time_insertion=tc.toc();

        tc.tic();
        selection_sort(vt_selection);
        double time_selection=tc.toc();

        tc.tic();
        sort(vt_sort.begin(),vt_sort.end());
        double time_sort=tc.toc();

        cout << "dimensione vettore: " << i << "\n"<< "tempo bubble: " << time_bubble <<"\n"<< "tempo insertion: " << time_insertion << "\n"<<"tempo selection: " << time_selection <<"\n"<< "tempo sort: " << time_sort<<"\n \n";
        

    }


}