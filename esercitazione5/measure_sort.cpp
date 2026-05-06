#include "timecounter.hpp"
#include "sorting.hpp"
#include "randfiller.hpp"
#include <iostream>
#include <thread>
#include <algorithm> 
#include <chrono>
using namespace std;

int main(void)
{
    timecounter tc;
    randfiller rf;

    for (int i=2; i<=8192 ;i=i*2){ //per avere il vettore di vettori per ognuna delle dimensioni
        vector<vector<int>> vt(100,vector<int>(i));
        
        for (int j=0; j<100; j=j+1){ //per riempire ogni vettore 
            rf.fill(vt[j],-500,500);
        }
        
        vector<vector<int>> vt_bubble = vt;
        vector<vector<int>> vt_insertion = vt;
        vector<vector<int>> vt_selection = vt;
        vector<vector<int>> vt_quick = vt;
        vector<vector<int>> vt_merge = vt;
        vector<vector<int>> vt_sort = vt;
        //misuro ora i tempi di bubble, insertion, selection, quick, merge e sort
        tc.tic();
        for (int k=0; k<100; k = k+1){
            bubble_sort(vt_bubble[k]);

        }
        double time_bubble=tc.toc()/100;

        tc.tic();
         for (int k=0; k<100; k = k+1){
            insertion_sort(vt_insertion[k]);

        }
        double time_insertion=tc.toc()/100;

        tc.tic();
         for (int k=0; k<100; k = k+1){
            selection_sort(vt_selection[k]);

        }
        double time_selection=tc.toc()/100;

        tc.tic();
         for (int k=0; k<100; k = k+1){
            quick_sort(vt_quick[k],0, i-1);

        }
        double time_quick=tc.toc()/100;

        tc.tic();
        for (int k=0; k<100; k = k+1){
            merge_sort(vt_merge[k],0, i-1);

        }
        double time_merge=tc.toc()/100;

        tc.tic();
        for (int k=0; k<100; k = k+1){
            sort(vt_sort.begin(),vt_sort.end());

        }
        double time_sort=tc.toc()/100;

        cout << "dimensione vettore: " << i << "\n"<< "tempo bubble: " << time_bubble <<"\n"<< "tempo insertion: " << time_insertion << "\n"<<"tempo selection: " << time_selection <<"\n" <<"tempo quick: "<< time_quick << "\n" << "tempo merge: " << time_merge << "\n" << "tempo sort: " <<time_sort<<"\n";
        
        

    }


}