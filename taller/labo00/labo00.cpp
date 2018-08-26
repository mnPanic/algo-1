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


int main() {
    std::cout << "El resultado con suma es: " << f3(11,10) << std::endl;
    std::cout << "El resultado con producto es: " << f3(2,3) << std::endl;
    return 0;
}
