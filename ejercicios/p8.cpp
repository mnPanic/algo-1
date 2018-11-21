#include "iostream"
#include "vector"
#include "tuple"
#include "string"
#include "utilidades.h"

using namespace std;


typedef vector<vector<int>> matriz;
typedef tuple<int, int, int> tripla;

/******************************** GENERALES ********************************/

int rows(matriz m) {
    return m.size();
}

int cols(matriz m) {
    return (rows(m) > 0) ? m[0].size() : 0;
}

string tToS(tripla t) {
    string repr = "(";
    repr += to_string(get<0>(t)) + ", ";
    repr += to_string(get<1>(t)) + ", ";
    repr += to_string(get<2>(t));
    repr += ")";

    return repr;
}

// vector de triplas a string
string tVToS(vector<tripla> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        repr += tToS(s[i]);

        if (i != s.size() - 1) {
            repr += ", ";
        }
    }

    repr += "}";

    return repr;
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


/******************************** EJ 6 ********************************/
vector<int> aplanar(matriz m) {
    vector<int> mA;

    for(int i = 0; i < rows(m); i++) {
        for(int j = 0; j < cols(m); j++) {
            mA.push_back(m[i][j]);
        }
    }

    return mA;
}

matriz redimensionar(matriz m, int n2, int m2) {
    matriz r(m2, vector<int>(n2, 0));

    vector<int> mA = aplanar(m);
    int k = 0;

    for(int i = 0; i < rows(r); i++) {
        for(int j = 0; j < cols(r); j++) {
            r[i][j] = mA[k];
            k++;
        }
    }

    return r;
}

/******************************** EJ 7 ********************************/
/** a **/
vector<tripla> aTriplas(matriz m) {
    vector<tripla> triplas;

    for(int i = 0; i < rows(m); i++) {
        for(int j = 0; j < cols(m); j++) {
            int valor = m[i][j];

            if (valor != 0) {
                triplas.push_back(tripla(i, j, valor));
            }
        }
    }

    return triplas;
}

void mainP8(){
    /*
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

    cout << "--------------- Ejercicio 6 ---------------" << endl;
    matriz m1 = {
            {1, 2, 3},
            {4, 5, 6}
    };

    matriz A = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
    };
    cout << mToS(redimensionar(m1, 2, 3)) << endl;
    cout << mToS(redimensionar(A, 6, 2)) << endl;
    */

    cout << "--------------- Ejercicio 7a ---------------" << endl;
    matriz m = {
            {1, 0, 0, 0, 0, 0},
            {0, 2, 0, 0, 0, 0},
            {0, 0, 3, 0, 0, 0},
            {0, 0, 0, 4, 0, 0},
            {0, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 0, 6},
            {0, 0, 0, 0, 0, 0},
            {123, 0, 0, 0, 0, 0},
    };

    cout << "m: " << endl;
    cout << mToS(m) << endl;
    cout << tVToS(aTriplas(m)) << endl;



}