//
// Created by Manuel Panichelli on 8/26/18.
//

#include <iostream>

int f(int x){
    return x+1;
}

// Ejercicio 2. Modificar el programa anterior para que f
//              tome dos parámetros de tipo int y los sume.
int f2(int x, int y) {
    return x+y;
}

// Ejercicio 3. Modificar el programa anterior para que f tome dos
//              parámetros x e y de tipo int y los sume sólo si x > y,
//              en caso contrario el resultado será el producto.
int f3(int x, int y) {
    int result = 0;

    if (x > y) {
        // los sumo
        result = x + y;
    } else {
        // los multiplico
        result = x * y;
    }

    return result;
}

// Ejercicio 5. Escribir la función que dado n ∈ N devuelve si es primo.
//              Recuerden que un número es primo si los únicos
//              divisores que tiene son 1 y el mismo.
bool esPrimo(int n) {
    bool primo = true;

    // Veo todos los numeros de [2, n / 2].
    // Si alguno lo divide, no es primo.
    // Y si ninguno lo divide, es primo
    for (int i = 2; i <= n / 2 && primo; i++) {
        if (n % i == 0) primo = false;
    }

    return primo;
}

int main() {
    int input [] = {1, 2, 3, 4, 5, 6, 41, 126, 1957, 19, 23, 89};

    for (int i = 0; i < 12; i++) {
        int n = input[i];
        std::cout << n << " es Primo? " << esPrimo(n) << std::endl;
    }
    return 0;
}
