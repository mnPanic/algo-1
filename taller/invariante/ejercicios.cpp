#include <vector>

using namespace std;

// Ej. 26
int sumaTotal(vector<int> s) {
    int i = 1;
    int mitad = s.size() / 2;

    int suma = s[mitad];

    while (i <= mitad) {
        suma += s[mitad - i];
        if (mitad + i < s.size()) {
            suma += s[mitad + i];
        }
        i++;
    }

    return suma;
}


/* Ejercicio 27. Máximo Común Divisor
    Encontrar el máximo común divisor entre dos enteros positivos m y n. La post condición del ciclo es
        Qc ≡ a = b = mcd(a, b).

    I ≡ 0 ≤ a ≤ m ∧ 0 ≤ b ≤ n ∧ mcd(a, b) = mcd(m, n)
*/

int mcd(int m, int n){
    int a = m;
    int b = n;
    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else if (b > a) {
            b -= a;
        }
    }

    return a;
}