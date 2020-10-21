/*
Julián Guillermo Zapata Rugeles
Problema 9. Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.
Nota: la salida del programa debe ser:
Original: 87512395.
Suma: 994.
*/

#include <iostream>
#include <math.h>
using namespace std;

void longitudCadena(char * , unsigned short int *);
void factorMultiplicacion(int ,  unsigned int *);

int main()
{
    unsigned short int n ;
    unsigned short int longitud = 0 ;
    unsigned int sumatoria = 0 ;
    unsigned int auxliar_factor = 0 ;
    char cadena[100]="";
    cout << "Ingrese una cadena cadena numerica : "; cin >> cadena;
    cout << "Ingrese un numero n > 0 : "; cin >> n ;

    longitudCadena(cadena,&longitud);
    cout << longitud << "longitud " << endl;
    if(longitud<=n){
        cout << "la suma es el mismo numero : "<< cadena ;
    }

    else{
        while (longitud>=0){
              cout << "cadena -> "<<cadena[longitud] << endl;
              longitud--;
            }
        }

    return 0;
}




void factorMultiplicacion(int factor , unsigned int *auxiliar_factor){
    unsigned int value = 1;
    for(unsigned short int a=0 ; a < factor ; a ++){
        value*=10;
    }
    *auxiliar_factor=value;
}

void longitudCadena(char *ptr_to_cadena , unsigned short int *ptr_to_longitud){
    unsigned short int longitud = 0 ;
    unsigned short int iterator = 0 ;
    while (true) {
        if(ptr_to_cadena[iterator]=='\0'){
            break;
        }
        else{
            longitud++;
            iterator++;
        }
    }
    *ptr_to_longitud=longitud;

}
