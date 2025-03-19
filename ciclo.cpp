#include <iostream>
using namespace std;

int main() {
    int num1, num2, suma;

    // Solicitar al usuario los dos números
    cout << "Introduce el primer número: ";
    cin >> num1;
    
    cout << "Introduce el segundo número: ";
    cin >> num2;

    // Usando un ciclo 'for' para sumar los dos números
    suma = 0;  // Empezamos la suma en 0
    for (int i = 0; i < num2; i++) {
        suma += num1;
    }

    cout << "La suma de " << num1 << " y " << num2 << " es: " << suma << endl;

    return 0;
}
