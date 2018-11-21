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

/** b **/
void getMinDim(vector<tripla> ps, int &c, int &f) {
    int maxF = get<0>(ps[0]);
    int maxC = get<1>(ps[0]);

    for(int i = 1; i < ps.size(); i++) {
        int valorF = get<0>(ps[i]);
        int valorC = get<1>(ps[i]);

        if(valorF > maxF) {
            maxF = valorF;
        }

        if(valorC > maxC) {
            maxC = valorC;
        }
    }

    // + 1 ya que los maximos son las posiciones maximas
    // de indexación, no los tamaños.
    f = maxF + 1;
    c = maxC + 1;
}

matriz aMatriz(vector<tripla> ps) {
    int cm;
    int fm;
    // Obtengo la minima dimensión,
    //  = minimos indices + 1;
    getMinDim(ps, cm, fm);

    // Creo una matriz con la minima dimensión posible
    // con todos los valores en 0.
    matriz m(fm, vector<int>(cm, 0));

    // Itero sobre los valores que no son 0
    // y los seteo en la matriz.
    for(int i = 0; i < ps.size(); i++) {
        int f = get<0>(ps[i]);
        int c = get<1>(ps[i]);
        int v = get<2>(ps[i]);

        m[f][c] = v;
    }

    return m;
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

    cout << "--------------- Ejercicio 7 ---------------" << endl;
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

    // a
    vector<tripla> ts = aTriplas(m);
    cout << "ts: " << endl;
    cout << tVToS(ts) << endl;

    // b
    cout << "ts a matriz: " << endl;
    cout << mToS(aMatriz(ts)) << endl;



}