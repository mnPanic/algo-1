#include "ejercicios.h"

bool divideA (int n, int x){
    return (x%n == 0);
}

bool divide(vector<int> v, int n) {
    bool divide = true;
    for (int i = 0; i < v.size(); i++) {
        if (!divideA(n, v[i])) divide = false;
    }
    return divide;
}

bool divideRec(vector<int> v, int n){
    if (v.size() == 0) {
        return true;
    } else {
        if (!divideA(n, v[v.size() - 1])) return false;
        v.pop_back();
        return divideRec(v, n);
    }
}

int maximo(vector<int> v){
    cout << "Implementame!" << endl;

    return 0;
}

int maximoRec(vector<int> v){
    cout << "Implementame!" << endl;

    return 0;
}

bool pertenece(int elem, vector<int> v){
    cout << "Implementame!" << endl;

    return false;
}

bool perteneceRec(int elem, vector<int> v){
    cout << "Implementame!" << endl;

    return false;
}

void mostrarVector(vector<int> v){
    cout << "Implementame!" << endl;

}

vector<int> limpiarDuplicados(vector<int> v){
    cout << "Implementame!" << endl;

    vector<int> res;
    return res;
}

vector<int> rotar(vector<int> v, int k){
    cout << "Implementame!" << endl;

    vector<int> res;
    return res;
}

vector<int> reverso(vector<int> v){
    cout << "Implementame!" << endl;

    vector<int> res;
    return res;
}


vector<int> reversoRec(vector<int> v){
    cout << "Implementame!" << endl;

    vector<int> res;
    return res;
}


vector<int> factoresPrimos(int n){
    cout << "Implementame!" << endl;

    vector<int> res;
    return res;
}


bool estaOrdenado(vector<int> v){
    cout << "Implementame!" << endl;

    return false;
}

void negadorDeBooleanos(vector<bool> &booleanos){
    cout << "Implementame!" << endl;
}

void sinImpares(vector<int>& v){
    cout << "Implementame!" << endl;
}

vector<pair<int, int> > cantidadApariciones(vector<int> v){
    cout << "Implementame!" << endl;

    vector<pair<int, int> > res;
    return res;
}



