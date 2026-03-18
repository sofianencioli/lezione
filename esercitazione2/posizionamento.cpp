#include <iostream>

int main()
{
    double ad[4] = {0.0, 1.1, 2.2, 3.3};
    float af[8] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    int ai[3] = {0, 1, 2};

    int x = 1;
    float y = 1.1;

    (&y)[1] = 0; 
    // con questo comando tratto y come un array e lo sposto di 4 byte e quindi vado a x 

    std::cout << &ad[0] << "\n";
    std::cout << &af[0] << "\n";
    std::cout << &ai[0] << "\n";
    std::cout << &x << "\n";
    std::cout << &y << "\n";

    //stampo gli adress dei primi elementi di ogni array (&elemento1) cosi vedo gli adresses e quanto distano (vedo che spostando y di 4 bytes va a x)
    
    std::cout << x << "\n";

    return 0;
}