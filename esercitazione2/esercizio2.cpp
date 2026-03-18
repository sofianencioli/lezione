#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    static const int N=10;
    double a[N]={4.0, 5.0, 9.0, 6.8, 8.0, 1.9, 7.4, 9.2, 1.0, 3.7};
    double massimo=a[0];
    double minimo=a[0];
    double somma=0;
    double scarti_quad=0;
    double somma_scarti=0;
    double media=0; 
    double std=0;
    //inizializzazione delle variabili
    for (int i=0; i<N; i=i+1) {
        minimo = min(minimo, a[i]);
        massimo=max(massimo,a[i]);
        somma=somma + a[i];
    }
    //ad ogni iterazione confronto il primo numero con fli altri per trovare il min/max tra i due
    
    media=somma / N;
    for(int i=0; i<N; i=i+1) {
        scarti_quad=(media-a[i])*(media-a[i]);
        somma_scarti= somma_scarti +scarti_quad;

    }
    std = sqrt(somma_scarti/N);

    cout << "il minimo è " << minimo << "\n";
    cout << "il massimo è " << massimo << "\n";
    cout << "la media è " << media << "\n";
    cout << "la deviazione standard è " << std << "\n";
}
