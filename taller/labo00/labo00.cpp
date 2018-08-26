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


// Los siguientes ejercicios deben ser implementados primero en su versión recursiva,
// luego iterativa utilizando while y por último iterativa utilizando for.

// Ejercicio 6. Escribir la función de Fibonacci que dado un entero n
//              devuelve el n-ésimo número de Fibonacci. Los números
//              de Fibonacci empiezan con F0 = 0 y F1 = 1. Fn = Fn−1 + Fn−2

int fibRecursiva(int n) {
    if (n <= 1) {
        return n;
    }

    return fibRecursiva(n - 1) + fibRecursiva(n - 2);
}

int fibWhile(int n) {
    if (n <= 1) {
        return n;
    }

    int fib = 1;
    int prevFib = 0;

    // comienzo de 2 porque los otros dos casos los tengo hardcodeados.
    int i = 2;
    while (i <= n) {
        int temp = fib;

        fib += prevFib;
        prevFib = temp;

        i++;
    }

    return fib;
}

int fibFor(int n) {
    if (n <= 1) {
        return n;
    }

    int fib = 1;
    int prevFib = 0;

    // comienzo de 2 porque los otros dos casos los tengo hardcodeados.
    for (int i = 2; i <= n; i++) {
        int temp = fib;

        fib += prevFib;
        prevFib = temp;
    }

    return fib;
}

// Ejercicio 7. Escribir la función que dado n ∈ N devuelve la suma
//              de todos los números impares menores que n.
bool esImpar(int n) {
    return n % 2 == 1;
}

int sumaImparesRecursiva(int n) {
    if (n == 0) {
        return 0;
    }

    if (esImpar(n)) {
        return n + sumaImparesRecursiva(n - 1);
    } else {
        return sumaImparesRecursiva(n - 1);
    }
}

int sumaImparesWhile(int n) {
    int suma = 0;
    while (n > 0) {
        if (esImpar(n)) {
            suma += n;
        }
        n--;
    }
    return suma;
}

int sumaImparesFor(int n) {
    int suma = 0;
    for(int i = 1; i <= n; i++) {
        if(esImpar(i)) {
            suma += i;
        }
    }
    return suma;
}

// Ejercicio 8. Escribir la función sumaDivisores que dado n ∈ N,
//              devuelve la suma de todos sus divisores entre [1, n].
// Hint: Recordar que para la versión recursiva es necesario implementar divisoresHasta

// Dice si k es divisor de n
bool esDivisorDe(int k, int n) {
    return n % k == 0;
}

int sumaDivisoresRecursiva(int n) {
    // no lo pienso hacer
    return 0;
}

int sumaDivisoresWhile(int n) {
    int suma = 0;
    int i = 1;

    while (i <= n) {
        if (esDivisorDe(i, n)) {
            suma += i;
        }

        i++;
    }

    return suma;
}

int sumaDivisoresFor(int n) {
    int suma = 0;

    for (int i = 1; i <= n; i++) {
        if (esDivisorDe(i, n)) {
            suma += i;
        }
    }

    return suma;
}

int main() {
    int input [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (int i = 0; i < 13; i++) {
        int n = input[i];
        std::cout << "suma de divisores hasta " << n << " es = " << sumaDivisoresWhile(n) << std::endl;
    }
    return 0;
}
