#include <fstream> 
#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
    string filename = argv[1];
    ifstream ifs(filename);
    if (ifs.is_open() ) {
        cout << "Il file e' aperto correttamente\n";
        while( !ifs.eof() ) {
            string location;
            double temp1;
            double temp2;
            double temp3;
            double temp4;
            ifs >> location >> temp1 >> temp2 >> temp3 >> temp4;
            if (ifs.fail() ) {
                cerr << "errore nel file\n";
                break;
            }
            double media_temp=(temp1 + temp2 + temp3 + temp4)/4;
            cout << "Citta':" << location << "Temperatura media:" << media_temp << "\n";
        }
    }
    else {
        cout << "impossibile aprire il file";
    }
    return 0;
}