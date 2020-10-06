/*
Julian Guillermo Zapat Rugeles

Problema 2. Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
y luego imprima cuantas veces se repite cada letra en el arreglo.
Ejemplo: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir: ABAR-
SECAAB
A: 4
B: 2
C: 1
Y así sucesivamente.
*/

#include <iostream>
#include <time.h>

#define LONGITUD_ARRAY_CHAR 200

using namespace std;
void generarArreglo(char * , const int &); // rellenar el arreglo char con letras aleatorias


void contarRepeticiones(const char * , const int &); /*
@contarRepeticiones :
    iterar desde A -> Z y sobre el array que contiene los chars
    el p

*/

int main()
{
    int tamanioArray = 0;
    cout << "Ingrese el tamaño del arreglo chars que se desea generar : ";
    cin >> tamanioArray;
    srand(time(NULL));
    char *ptr_group_letter = new char[tamanioArray];
    generarArreglo(ptr_group_letter,tamanioArray);
    contarRepeticiones(ptr_group_letter,tamanioArray);
    delete [] ptr_group_letter;
    return 0;
}

void generarArreglo(char *ptr_position , const int &tamanio_array){
    int tmp_numero = 0 ;
    for(short int iterator=0 ; iterator< tamanio_array ; iterator++){
        tmp_numero =int('A')+rand()% (int('Z')-int('A'-1)); // numero aleatorio generado
        //cout <<iterator<<") "<<char(tmp_numero) << " -> " <<tmp_numero<< endl ;
        ptr_position[iterator] = tmp_numero ;
    }
}

void contarRepeticiones(const char *ptr_position , const int &tamanio_array){
    int tmp_numero ;
    int acumulador = 0;
    for(short int iterator=int('A'); iterator<= int('Z') ; iterator++){
        tmp_numero=0 ;
        for(short int internalIterator = 0 ; internalIterator < tamanio_array ; internalIterator ++){
            if(char(iterator)==ptr_position[internalIterator]){
                tmp_numero++;
            }
        }
        acumulador+=tmp_numero;
        cout << char(iterator) << " : " << tmp_numero << endl ;
    }
    cout << "Sumatoria total  :"<<acumulador << endl;
};
