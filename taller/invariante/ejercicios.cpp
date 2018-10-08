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