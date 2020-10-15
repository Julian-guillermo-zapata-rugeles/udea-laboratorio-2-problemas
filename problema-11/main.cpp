/*
Julian Guillermo Zapata Rugeles

Problema 11. Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).
Nota: un ejemplo de visualización de una sección de la sala es el siguiente:

Donde + representa los asientos reservados y - representa los asientos disponibles.

*/
#include <iostream>
#include <iomanip>
#include <cstdlib> // se usará system para limpiar la terminal
using namespace std;

struct salaCine{
  /*
    @salaCine:
        crear una matriz bidimensional de 15x20 con indices de acceso  y gestionar la
        reserva de asientos en una sala de cine
   */
  bool **asientos;
  salaCine();
  ~salaCine();
  void mostrarReservas(); // mostrar la matríz
  bool manejarReservas(bool , short int * ,short int *);
  /* @manjearReservas:
       ARGS 1 bool -> operación : true para reservas , false para cancelar reserva
       ARGS 2 bool *-> fila
       ARGS 3 bool *-> columna
  */
  };


int main()
{
    salaCine *cine = new salaCine(); // se crea cine
    bool salida=false , tmp_auxiliar=false;
    short int  fila = 0 , columna = 0 , *ptr_fila = &fila , *ptr_col = &columna , seleccion = 0 ;
    while (salida==false) {
        tmp_auxiliar=false;
        cine->mostrarReservas();
        cout <<"Seleccione la opcion de su interes "<<endl;
        cout <<"1) para reservar "<<endl;
        cout <<"2) para cancelar reserva "<<endl;
        cin >> seleccion;
        if(seleccion == 1 || seleccion == 2){
            if(seleccion==1){
                tmp_auxiliar=true;
            }
            cout <<"Ingrese la fila   : ";
            cin>> *ptr_fila;
            cout <<"Ingrese la columa : ";
            cin >> *ptr_col ;
            if(*ptr_fila>=1 && *ptr_fila<=15 && *ptr_col >=1 && *ptr_col <= 20){
                *ptr_col-=1;
                *ptr_fila-=1;
                system("clear");
                cine->manejarReservas(tmp_auxiliar,ptr_fila,ptr_col);
              }
            else{
                cout << "Entradas Invalidas (verifique nuevamente)"<<endl;
            }
        }
        else{
                cout << "Entradas Invalidas (verifique nuevamente)"<<endl;
        }

    }
    return 0;
}

bool salaCine::manejarReservas(bool operacion ,short int *filas,short int  *columnas){

    if(operacion==false){
    //----------------- CANCELACIÓN ----------------------//
        if(*(*(asientos+*filas)+*columnas) == false){
            cout << "Msg -> Este ya se encontraba libre antes de intentar cancelar Reserva "<<endl;
            return false;
        }
        else{
            // cancelación satisfactoria
            *(*(asientos+*filas)+*columnas)= false ;
            cout << "Msg -> Cancelacion exitosa  "<<endl;
            return true;
        }
    }
    //----------------- RESERVACIÓN----------------------//
    else{
        // reservación exitosa
        if(*(*(asientos+*filas)+*columnas)==false){
            *(*(asientos+*filas)+*columnas)= true ;
            return true;
        }
        else{
            // reserva ERRONEA
            cout << "Msg -> Asiento ocupado  (no se pudo reservar)"<<endl;
            return false;
        }
    }
    return false;
}



salaCine::salaCine(){
    // constructor de salaCine
    //
    asientos=new bool*[15];
    for(short int  filas=0 ; filas < 15 ; filas ++){
        asientos[filas]=new bool[20];
        for(short int columnas=0;columnas<20;columnas++){
            *(*(asientos+filas)+columnas)=false;  //ASIGNACION INICIAL DE LA MATRIZ CON BOOLEANOS //
        }
    }
}

void salaCine::mostrarReservas(){
    cout <<"            ***********  Reservas de cine **********\n" << endl;
    cout <<"        ";
    for(short int col=1;col<=20;col++){
       if(col>9){
           cout << col << " ";
       }
       else{
           cout << col << "  ";
       }

    }
    cout << endl;
    for(short int filas=0 ; filas < 15 ; filas ++){
        cout<< left <<setw(2) << 1+filas <<"--> | ";
        for(short int columnas=0;columnas<20;columnas++){
            if(*(*(asientos+filas)+columnas)==false){
                cout <<'-'<<"  " ;
            }
            else{
                cout <<'+'<<"  " ;
            }

        }
        cout<< endl;
    }
}
