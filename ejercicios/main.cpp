#include <iostream>
#include "vector"
#include <string>


using namespace std;

/******************************** UTILIDAD ********************************/

string vToS(vector<int> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        repr += to_string(s[i]);

        if (i != s.size() - 1) {
            repr += ", ";
        }
    }

    repr += "}";

    return repr;
}

string sVToS(vector<string> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        repr += s[i];

        if (i != s.size() - 1) {
            repr += ", ";
        }
    }

    repr += "}";

    return repr;
}

string mToS(vector<vector<int>> s) {
    string repr = "{";

    for (int i = 0; i < s.size(); i++) {
        if (i != 0) {
            repr += " ";
        }

        repr += vToS(s[i]);

        if (i != s.size() - 1) {
            repr += ",\n";
        }
    }

    repr += "}";

    return repr;
}


/******************************** EJ 5 ********************************/

void addLengthSeq(vector<vector<int>> &to, int e) {
    to.push_back({e, 1});
}

vector<vector<int>> comprimir(vector<int> s) {
    vector<vector<int>> res;
    addLengthSeq(res, s[0]);

    int actual = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1] + 1) {
            res[actual][1]++;
        } else {
            addLengthSeq(res, s[i]);
            actual++;
        }
    }

    return res;
}

/******************************** EJ 6 ********************************/

vector<int> meseta(vector<int> s) {
    vector<int> max = {};
    vector<int> actual = {s[0]};

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            if (actual.size() > max.size()) {
                max = actual;
            }
            actual = {};
        }

        actual.push_back(s[i]);
    }

    if (actual.size() > max.size()) {
        max = actual;
    }

    return max;
}

/******************************** EJ 9 ********************************/

int mod(int n, int m) {
    while (n >= m || n < 0) {
        n = (n < 0) ? n + m : n - m;
    }
    return n;
}

vector<int> obtenerCantEspacios(int palabras, int espacios) {
    vector<int> cant(palabras, 0);
    int i = -1;
    while (espacios > 0) {
        cant[mod(i, palabras - 1)]++;
        espacios--;
        i--;
    }
    return cant;
}

string generarOracion(vector<string> palabras, int espacios) {
    string res = "";
    vector<int> cantEspacios = obtenerCantEspacios(palabras.size(), espacios);

    for (int i = 0; i < palabras.size(); i ++) {
        res += palabras[i];
        int e = cantEspacios[i];
        for (int j = 0; j < e; j++) {
            res += "#";
        }
    }

    return res;
}

int cantApariciones(string s, char c) {
    int ap = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            ap ++;
        }
    }

    return ap;
}


vector<string> split(string s, char delim) {
    vector<string> res;
    string word;
    int i = 0;
    while (i <= s.size()) {
        if(i != s.size() && s[i] != delim) {
            word += s[i];
        } else if (word != ""){
            res.push_back(word);
            word = "";
        }
        i++;
    }

    return res;
}

void justificarOracion(string &s) {
    char space = '#';
    vector<string> palabras = split(s, space);
    int espacios = cantApariciones(s, space);
    s = generarOracion(palabras, espacios);
}

void justificar(vector<string> &ss) {
    for(int i = 0; i < ss.size(); i++) {
        justificarOracion(ss[i]);
    }
}

int main() {

    cout << "--------------- Ejercicio 5 ---------------" << endl;
    cout << "<1, 2, 3, 4, 5>"       << endl << mToS(comprimir({1,2,3,4,5}))     << endl;
    cout << "<1, 2, 3, 10, 11>"     << endl << mToS(comprimir({1,2,3,10,11}))   << endl;
    cout << "<1, 2, 3, 100, 102>"   << endl << mToS(comprimir({1,2,3,100,102})) << endl;
    cout << "<5, 4, 3, 2, 1>"       << endl << mToS(comprimir({5,4,3,2,1}))     << endl;


    cout << "--------------- Ejercicio 6 ---------------" << endl;
    cout << "<1, 2, 3, 4> -> "          << vToS(meseta({1,2,3,4})) << endl;
    cout << "<1, 1, 2, 3, 4> -> "       << vToS(meseta({1,1,2,3,4})) << endl;
    cout << "<1, 1, 2, 2, 3, 3, 3> -> " << vToS(meseta({1, 1, 2, 2, 3, 3, 3})) << endl;


    cout << "--------------- Ejercicio 9 ---------------" << endl;
    vector<string> ss = {
            "justifying#lines#by########",
            "inserting#extra#blanks#is##",
            "one#task#of#a#text#editor.#",
    };

    justificar(ss);
    cout << sVToS(ss) << endl;

    return 0;
}


