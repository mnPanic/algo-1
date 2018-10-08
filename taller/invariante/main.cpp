#include <iostream>
#include "ejercicios.cpp"

using namespace std;

int main() {
    cout << "Ej. 26: sumaTotal" << endl;
    cout << "sumaTotal({1, 2, 3}) = " << sumaTotal({1, 2, 3}) << endl;
    cout << "sumaTotal({1, 2, 3, 4}) = " << sumaTotal({1, 2, 3, 4}) << endl;

    cout << "Ej. 27: mcd" << endl;
    cout << "mcd(7, 2) = " << mcd(7, 2) << " (debería ser 1)" << endl;
    cout << "mcd(8, 2) = " << mcd(8, 2) << " (debería ser 2)" << endl;
    cout << "mcd(2, 8) = " << mcd(2, 8) << " (debería ser 2)" << endl;
    cout << "mcd(1, 1) = " << mcd(1, 1) << " (debería ser 1)" << endl;
}

