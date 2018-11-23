#include "iostream"
#include "vector"
#include "tuple"
#include "string"
#include "utilidades.h"

using namespace std;


typedef vector<vector<int>> matriz;
typedef tuple<int, int> posicion;
typedef tuple<int, int, int> tripla;
typedef tuple<int, int> tupla;

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
string tupleToS(tupla t) {
    string repr = "(";
    repr += to_string(get<0>(t)) + ", ";
    repr += to_string(get<1>(t));
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

string tupleVToS(vector<posicion> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        repr += tupleToS(s[i]);

        if (i != s.size() - 1) {
            repr += ", ";
        }
    }

    repr += "}";

    return repr;
}

string posMToS(vector<vector<posicion>> m) {
    string repr = "{";

    for (int i = 0; i < m.size(); i++) {
        if (i != 0) {
            repr += " ";
        }

        repr += tupleVToS(m[i]);

        if (i != m.size() - 1) {
            repr += ",\n";
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

/******************************** EJ 9 ********************************/

tupla indexOf(matriz m, int x) {
    tupla ini(-1, -1);
    tupla pos = ini;

    for(int i = 0; i < rows(m) && pos == ini; i++) {
        for(int j = 0; j < cols(m) && pos == ini; j++) {
            if (m[i][j] == x) {
                pos = tupla(i, j);
            }
        }
    }

    return pos;
}

/******************************** EJ 13 ********************************/
/** a **/
int valorEn(matriz m, posicion p) {
    return m[get<0>(p)][get<1>(p)];
}

bool enRango(matriz m, posicion p) {
    return (get<0>(p) < rows(m)) &&
           (get<1>(p) < cols(m)) &&
           (get<0>(p) > 0)       &&
           (get<1>(p) > 0);
}

vector<posicion> posMenoresAdy(matriz m, posicion p) {
    vector<posicion> ps;

    int f = get<0>(p);
    int c = get<1>(p);
    int valor = valorEn(m, p);

    for (int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            posicion actual(f + i, c + j);
            if (enRango(m, actual) && valorEn(m, actual) < valor) {
                ps.push_back(actual);
            }
        }
    }

    return ps;
}

bool esValle(matriz m, posicion p){
    return posMenoresAdy(m, p).size() == 0;
}

posicion valle(matriz m, posicion from) {
    posicion actual = from;
    while(!esValle(m, actual)) {
        actual = posMenoresAdy(m, actual)[0];
    }

    return actual;
}

/** b **/

posicion menorValleDesde(matriz m, posicion from) {
    if (esValle(m, from)) {
        return from;
    } else {
        vector<posicion> posMenores = posMenoresAdy(m, from);
        posicion minValle = menorValleDesde(m, posMenores[0]);

        for (int i = 1; i < posMenores.size(); i++) {
            posicion valle = menorValleDesde(m, posMenores[i]);

            if (valorEn(m, valle) < valorEn(m, minValle)) {
                minValle = valle;
            }
        }

        return minValle;
    }
}

/** c **/
typedef vector<posicion> camino;


vector<posicion> addFirst(vector<posicion> ps, posicion p) {
    vector<posicion> res(ps.size() + 1, posicion(0, 0));

    res[0] = p;
    for (int i = 1; i < res.size(); i++) {
        res[i] = ps[i - 1];
    }

    return res;
}

void agregarATodos(vector<camino> &caminos, vector<camino> &caminosSiguientes, posicion from) {
    for (int i = 0; i < caminosSiguientes.size(); i++) {
        caminos.push_back(addFirst(caminosSiguientes[i], from));
    }
}

vector<camino> caminosAVallesDesde(matriz m, posicion from) {
    if(esValle(m, from)) {
        return {{from}};
    } else {
        vector<camino> caminos;
        vector<posicion> posMenores = posMenoresAdy(m, from);
        for (int i = 0; i < posMenores.size(); i++) {
            vector<camino> caminosSiguientes = caminosAVallesDesde(m, posMenores[i]);

            agregarATodos(caminos, caminosSiguientes, from);
        }

        return caminos;
    }
}

void mainP8(){
    cout << "--------------- Ejercicio 13 ---------------" << endl;
    matriz m = {
            {10, 8, 1, 2, 13},
            {11, 7, -1, 3, 14},
            {12, 6, 5, 4, 15},
            {24, 16, 17, 18, 27},
            {25, 23, 0, 19, 28},
            {26, 22, 21, 20, 29}
    };

    cout << "un valle esta en la pos: " << tupleToS(valle(m, posicion(0,0))) << endl;
    cout << "el mínimo valle esta en la pos: " << tupleToS(menorValleDesde(m, posicion(3,0))) << endl;
    cout << "todos los caminos que llevan a valles desde el (3,0) son ->" << endl;
    cout << posMToS(caminosAVallesDesde(m, posicion(3, 0))) << endl;


}