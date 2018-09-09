#include <iostream>
#include <fstream>
#include <math.h>       /* sqrt */

// Ejercicio 11. Escribir un programa en el que se ingrese un número por teclado (entrada estándar), calcule si es primo y
//               muestre por pantalla (salida estándar) “El número ingresado es primo”si es primo. En caso contrario: “El número ingresado
//               no es primo”

bool esPrimo(int n) {
    bool primo = true;

    // Veo todos los numeros de [2, sqrt n].
    // Si alguno lo divide, no es primo.
    // Y si ninguno lo divide, es primo
    for (int i = 2; i <= sqrt(n) && primo; i++) {
        if (n % i == 0) primo = false;
    }

    return primo;
}

void ej11() {
    int numero = 0;
    std::cout << "Ingrese un numero entero" << std::endl;
    std::cin >> numero;

    bool primo = esPrimo(numero);
    if (primo) {
        std::cout << "El número ingresado es primo" << std::endl;
    } else {
        std::cout << "El número ingresado no es primo" << std::endl;
    }
}

int main() {
    ej11();
    return 0;
}