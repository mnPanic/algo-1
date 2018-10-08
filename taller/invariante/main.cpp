#include <iostream>
#include "ejercicios.cpp"

using namespace std;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);c

    vector<int> v2 = v;
    v2.push_back(4);

    cout << "Ej. 26: sumaTotal" << endl;
    cout << "sumaTotal(v) = " << sumaTotal(v) << endl;
    cout << "sumaTotal(v2) = " << sumaTotal(v2) << endl;
}

