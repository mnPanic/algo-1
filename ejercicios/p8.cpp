#include "iostream"
#include "vector"
#include "utilidades.h"

using namespace std;


typedef vector<vector<int>> matriz;

/******************************** GENERALES ********************************/

int rows(matriz m) {
    return m.size();
}

int cols(matriz m) {
    return (rows(m) > 0) ? m[0].size() : 0;
}


/******************************** EJ 1 ********************************/
int valorMult(matriz m1, matriz m2, int f, int c) {
    int res = 0;

    for (int k = 0; k < cols(m1); k++) {
        res += m1[f][k] * m2[k][c];
    }

    return res;
}

matriz mult(matriz m1, matriz m2) {
    matriz res(rows(m1), vector<int>(cols(m2), 0));

    for(int i = 0; i < rows(res); i++) {
        for(int j = 0; j < cols(res); j++) {
            res[i][j] = valorMult(m1, m2, i, j);
        }
    }

    return res;
}

/******************************** EJ 4 ********************************/
/** a **/
vector<int> multFila(matriz m, int i) {
    matriz fila = {m[i]};
    vector<int> filaMultiplicada = mult(fila, m)[0];
    return filaMultiplicada;
}


/** b **/
matriz trasponer(matriz m) {
    // defino la matriz traspuesta con las dimensiones opuestas
    matriz t(cols(m), vector<int>(rows(m), 0));

    for (int i = 0; i < rows(t); i++) {
        for(int j = 0; j < cols(t); j++) {
            t[i][j] = m[j][i];
        }
    }

    return t;
}

matriz multTras(matriz m) {
    return mult(m ,trasponer(m));
}


void mainP8(){
    cout << "--------------- Ejercicio 4a ---------------" << endl;
    matriz m = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    cout << vToS(multFila(m, 1)) << endl;

    cout << "--------------- Ejercicio 4b ---------------" << endl;
    matriz m2 = {
            {1, 2},
            {3, 4},
            {5, 6}
    };
    cout << mToS(m2) << endl;
    cout << mToS(trasponer(m2)) << endl;
    cout << mToS(trasponer(trasponer(m2))) << endl;
    cout << mToS(multTras(m2)) << endl;

}