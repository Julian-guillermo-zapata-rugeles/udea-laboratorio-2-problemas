/*
Problema 17. Dos números a y b (a != b) son amigables si la suma de los divisores de a (excluyéndose el mismo)
es igual a b, y viceversa. Ej: los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110; y suman 284. Los divisores
de 284 son 1, 2, 4, 71 y 142; y suman 220. Entonces 220 y 284 son amigables. Escribir un programa que reciba un
número y halle la suma de todos los números amigables menores al número ingresado.
Nota: la salida del programa debe ser:
El resultado de la suma es: 504.
*/

#include <iostream>
#include <iomanip>
using namespace std;

unsigned  int suma_divisores(unsigned int);

int main()
{
    unsigned int user_integer = 0 ;
    unsigned int tmp_sum_div = 0 ;
    cout << "Ingrese un numero mayor a 1 para hallar numeros amigos : ";
    cin >> user_integer;
    for (unsigned int i=user_integer; i>0 ; i--){
        for (unsigned int k=i ;k > 0 ; k --) {
            tmp_sum_div=suma_divisores(k);
            if(tmp_sum_div==i && i!=k){
                cout << k <<fixed <<setw(6) << " y " << left << i << " son numeros amigos "<<endl;
            }
        }
    }
    return 0;
 }






unsigned int suma_divisores(unsigned int numer_prueba ){
    unsigned int sum_divisor = 0;
    for(unsigned int i = 1 ; i < numer_prueba ; i++){
        if(numer_prueba%i==0){
            sum_divisor+=i;
        }
    }
    return sum_divisor;
}
