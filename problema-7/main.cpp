/*
Julian Guillermo Zapata Rugeles
Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
Ejemplo: se recibe bananas debe mostrar bans.
Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.
*/
#include <iostream>

using namespace std;

int main()
{
    char cadena[] = "";
    cout << "Ingrese la cadena : ";
    cin >> cadena ;
    cout <<  sizeof(cadena) << endl;
    for(unsigned short int i = 0 ; i < sizeof(cadena) ; i ++){
        cout << " - " << cadena[i] ;
    }
    cout << endl;
    return 0;
}
