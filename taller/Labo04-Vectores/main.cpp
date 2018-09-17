#include <iostream>
#include "ejercicios.h"

using namespace std;

int main() {

    cout << "A probar se ha dicho!" << endl;
    cout << "DIVIDE" << endl;

    vector<int> v;
    v.push_back(-20);
    v.push_back(30);
    v.push_back(40);
    vector<int> v2;
    v2.push_back(3);

    cout << divide(v, 10) << endl;
    cout << divide(v2, 10) << endl;
    cout << divideRec(v, 10) << endl;
    cout << divideRec(v2, 10) << endl;

    cout << "MAXIMO" << endl;
    cout << maximo(v) << endl;
    cout << maximo(v2) << endl;
    cout << maximoRec(v) << endl;
    cout << maximoRec(v2) << endl;

    cout << "PERTENECE" << endl;
    cout << pertenece(30, v) << endl;
    cout << pertenece(3, v) << endl;
    cout << perteneceRec(30, v) << endl;
    cout << perteneceRec(3, v) << endl;

    cout << "MOSTRAR" << endl;
    mostrarVector(v);

    cout << "LIMPIAR" << endl;
    vector<int> v3;
    v3.push_back(30);
    v3.push_back(30);
    v3.push_back(30);
    v3.push_back(2);
    mostrarVector(limpiarDuplicados(v3));

    cout << "ROTAR" << endl;
    vector<int> v4;
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(3);
    v4.push_back(4);
    v4.push_back(5);
    v4.push_back(6);
    mostrarVector(rotar(v4, 2));
    //deberia dar [3, 4, 5, 6, 1, 2].
    return 0;
}