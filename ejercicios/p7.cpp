#include <iostream>
#include "vector"
#include <string>

#include "utilidades.h"

using namespace std;

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


/******************************** EJ 10 ********************************/
void agregarDigitosASecuencia(vector<int> s, vector<vector<int>>& to) {
    // itero sobre todos los dígitos posibles
    for(int n = 0; n <= 9; n++) {
        vector<int> s_copy = s;
        s_copy.push_back(n);
        to.push_back(s_copy);
    }
}

vector<vector<int>> agregarDigitosATodas(vector<vector<int>> ss) {
    vector<vector<int>> res;
    for (int i = 0; i < ss.size(); i++) {
        agregarDigitosASecuencia(ss[i], res);
    }

    return res;
}

vector<vector<int>> generarSecuencias(int n) {
    if (n == 0){
        return {{}};
    } else {
        return agregarDigitosATodas(generarSecuencias(n - 1));
    }
}

/******************************** EJ 12 ********************************/
/** a **/
bool isSubseq(string s1, string s2) {
    int i = 0;
    int j = 0;
    bool isSub = false;
    while (i < s2.size() && !isSub) {
        j = 0;
        while (j < s1.size() && s1[j] == s2[i]) {
            i++;
            j++;
        }
        i++;
        isSub = (j == s1.size());
    }

    return isSub;
}

/** b **/
string subseq(string s, int from, int to) {
    string res = "";

    for (int i = from; i < to; i++) {
        res += s[i];
    }

    return res;
}

string subseqCompartidaMasLargaDesde(string s1, int i, string s2) {
    string ss = "";

    int j = i;
    while (j <= s1.size() && isSubseq(subseq(s1, i, j), s2)) {
        ss = subseq(s1, i, j);
        j++;
    }

    return ss;
}

string subseqMasLarga(string s1, string s2) {
    string max = "";
    string s;
    for (int i = 0; i < s1.size(); i++) {
        s = subseqCompartidaMasLargaDesde(s1, i, s2);
        if (s.size() > max.size()) {
            max = s;
        }
    }

    return max;
}

/******************************** EJ 20 ********************************/

void agregarElementos(vector<int>& to, int elem, int cant) {
    for(int i = 0; i < cant; i++) {
        to.push_back(elem);
    }
}

vector<int> generateSeq(vector<int> s) {
    vector<int> b;
    for (int i = 0; i < s.size(); i++){
        agregarElementos(b, i, s[i]);
    }

    return b;
}


void mainP7() {

    /*
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


    cout << "--------------- Ejercicio 10 ---------------" << endl;
    cout << "n = 2" << endl;
    cout << mToS(generarSecuencias(2)) << endl;
    cout << "n = 3" << endl;
    cout << mToS(generarSecuencias(3)) << endl;


    cout << "--------------- Ejercicio 12 ---------------" << endl;
    cout << "s1 = 'hola' s2 = 'chau' -->" << isSubseq("hola", "chau") << endl;
    cout << "s1 = 'a' s2 = 'chau' -->"    << isSubseq("a", "chau")    << endl;
    cout << "s1 = 'hau' s2 = 'chau' -->"  << isSubseq("hau", "chau")  << endl;
    cout << "s1 = 'hauu' s2 = 'chau' -->"  << isSubseq("hauu", "chau")  << endl;
    cout << subseqMasLarga("hola", "chau") << endl;
    cout << subseqMasLarga("holaa", "chaaau") << endl;
    string s1 = "hola esto es un texto largo para probar la eficiencia del algoritmo";
    string s2 = "hola, esto NO es texto que comparta, pero si la palabra mas larga algoritmo";
    cout << subseqMasLarga(s1, s2) << endl;

    string s3 = "hola, esto es un texto largo que comparte mucho con el primero";
    cout << subseqMasLarga(s1, s3) << endl;
    cout << subseqMasLarga(s3, s2) << endl;
     */

    cout << "--------------- Ejercicio 20 ---------------" << endl;
    vector<int> a = {1, 2, 3, 1, 1, 1, 0, 0, 0};
    cout << vToS(a) << " --> " << vToS(generateSeq(a)) << endl;
}