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

// Ejercicio 15. ¿Cuál es el valor de a luego de la invocación prueba(a,a)?
void prueba (int & x , int & y ) {
    x = x + y ;
    y = x - y ;
    x = 1/ y ;
}

// En los siguientes ejercicios, ingresar los valores por entrada est´andar,
// mostrar en la salida est´andar los valores ingresados y
// los resultados de las funciones.

// Ejercicio 16. Implementar la función swap: void swap(int& a, int& b), que cumpla con la siguiente especificación:
// proc swap (inout a:Z, inout b:Z) {
//      Pre {a = a_0 ∧ b = b_0}
//      Post {a = b_0 ∧ b = a_0}
// }

void swap(int& a, int& b) {
    int temp = b;
    b = a;
    a = temp;
}

void ej16() {
    int a = 0;
    int b = 0;

    std::cout << "Ingresar valores (a, b):" << std::endl;
    std::cin >> a;
    std::cin >> b;

    swap(a, b);

    std::cout << "Los valores cambiados son:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

int main() {
    ej16();
    return 0;
}