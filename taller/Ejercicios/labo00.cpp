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


int main() {
    std::cout << "El resultado es: " << f2(10,11) << std::endl;
    return 0;
}
