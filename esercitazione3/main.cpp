#include "razionali.hpp"
int main(void)
{
    rational<int> a(2,4);
    rational<int> b(8,6);
    rational<int> c(5,0);
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";

    rational<int> s = a+b;
    rational<int> d = b-c ;
    rational<int> p = b*c ;
    rational<int> q = a/c ;
    cout << s<< "\n";
    cout << d<< "\n";
    cout << p<< "\n";
    cout << q<< "\n";
    return 0;
}