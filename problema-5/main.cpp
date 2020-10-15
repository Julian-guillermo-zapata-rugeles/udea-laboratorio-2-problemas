/*
Julian Guillermo Zapata Rugeles

Problema 5. Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use
parámetros por referencia para retornar la cadena. Escriba un programa de prueba.
Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.

Solución :
            conocer la longitud del numero ingresado para crear un array en donde guardarlo
            una vez conocida su longitud se guardará en un array en orden contrario ya que al separarlo usando modulo se obtiene de atrás <---
            una vez guardado se convierte a cadena
*/
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

signed short int longitud_numero = 0 ;
long long int numero_usuario = 0;
char *ptr_to_char_array;

void obtenerLongitudNumero(long long intnumeroPrueba , signed short int *longitud);
void convertir_numero_cadena(long long int numeroPrueba, signed short int *longitud , char* array_char );

int main()
{
    cout << "Ingrese un numero para convertir a char : ";
    cin >> numero_usuario;

    obtenerLongitudNumero(numero_usuario,&longitud_numero);
    ptr_to_char_array = new char[longitud_numero]; // reservamos memoria en base a la longitud del numero ingresado
    convertir_numero_cadena(numero_usuario,&longitud_numero,ptr_to_char_array);
    cout << "\"";
    for(unsigned short int a=0;a<longitud_numero;a++){
        //cout <<a<<" -> "<< typeid(ptr_to_char_array[a]).name() << endl;
        cout << ptr_to_char_array[a];
    }
    cout <<"\""<< endl;
    cout <<"typeid() = "<<typeid(ptr_to_char_array[0]).name() << endl;
    return 0;
}


void obtenerLongitudNumero(long long  int numeroPrueba ,signed short int *longitud){
    unsigned short int tmp_module ;
    while (numeroPrueba>=1) {
        tmp_module = numeroPrueba % 10 ;
        //cout << "start : " << numeroPrueba <<" end : ";
        numeroPrueba=numeroPrueba/10;
        //cout << numeroPrueba << " --> "<<tmp_module<<endl;
        *longitud=*longitud+1;
    }
}

void convertir_numero_cadena(long long int numeroPrueba , signed short int *longitud , char *array_char){
    signed short int tmp_module;
    short int tmp = *longitud;
    while (numeroPrueba>=1) {
        tmp_module = numeroPrueba % 10 ;
        //cout << "start : " << numeroPrueba <<" end : ";
        numeroPrueba=numeroPrueba/10;
        //cout << numeroPrueba << " --> "<<tmp_module<<endl;
      tmp=tmp-1;
      //cout << "char ["<<tmp<<"]"<< " --> char "<< typeid(char('0'+tmp)).name() << " decimal "<<tmp << endl;
      array_char[tmp]='0'+tmp_module;
    }
}
