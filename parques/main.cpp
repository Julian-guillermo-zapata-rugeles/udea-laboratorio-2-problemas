// Julian Guillermo Zapata Rugeles
#include <iostream>

using namespace std;

char tablero[24]={};
void llenarTablero(char *tmp_tablero);
void imprimirTablero(char *tmp_tablero);
void mover(int , char *tmp_tablero , char);


int jugador1=0;
int jugador2=0;
int numero=1;
int main()
{
    cout << "######## JUEGO DEL PARQUES PANDITA ###########" << endl;
    llenarTablero(tablero);
    tablero[0]='X';
    tablero[6]='O';
    imprimirTablero(tablero);
    while (true) {
        if(numero%2==0){
            cout <<"Turno Jugador 2 : ";
            cin >> jugador2;
            mover(jugador2,tablero,'O');
        }
        else{
            cout <<"Turno Jugador 1 : ";
            cin >> jugador1;
            mover(jugador1,tablero,'X');
        }
        imprimirTablero(tablero);
        numero++;
    }
    return 0;
}


void mover(int suma  ,char *tmp_tablero , char jugador){
    int pos=0;
    for(int x =0 ;x<24;x++){
        if(tmp_tablero[x]==jugador){
            pos=x;
            break;
        }
    }
    if(pos+suma>23 && jugador =='X'){
        cout <<"------- JUEGO FINALIZADO ------" << endl;
        cout <<"X  Fue el ganador de la partida  "<< endl;
    }
    //cout << pos << " position "<<endl;
    tmp_tablero[pos]=' ';
    if(tmp_tablero[pos+suma]!=' '){
     cout << "------ CAPTURADO -------";
     if(tmp_tablero[pos+suma]=='X'){
         tmp_tablero[0]='X';
     }
     if( tmp_tablero[pos+suma]=='O'){
         tmp_tablero[6]='O';
     }
    }
    tmp_tablero[pos+suma]=jugador;
}

void llenarTablero(char *tmp_tablero){
    for(int x=0;x<24;x++){
        tablero[x]=' ';
    }
}

void imprimirTablero(char *tmp_tablero){
    cout <<"\n---------------------------"<<endl;
    for(int x=18;x>=12;x--){
         cout << tablero[x] <<" | " ;
    }
    cout <<"\n---------------------------"<<endl;
    int izquierda=19;
    int derecha=11;
    for(int x=0;x<5;x++){
        cout  <<"|"<< tmp_tablero[izquierda]<<" |                   | "<< tmp_tablero[derecha] <<"|"<< endl;
        izquierda++;
        derecha--;
    }

    cout <<"\n---------------------------"<<endl;

    for(int x=0;x<7;x++){
         cout << tablero[x] <<" | " ;
    }
    cout <<"\n---------------------------"<<endl;
}
