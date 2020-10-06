/*
Julián Guillermo Zapat Rugeles

Problema 3. Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.
*/
#include <iostream>

using namespace std;

bool compararCadenas(const char *palabra_1 , const char *palabra_2 ); /*
@compararCadenas :
    recibe los dos arreglos de chars, se reciben y se tratan como constantes para evitar cambios del array */

int main()
{

    char palabra1[100]={};
    char palabra2[100]={};

    cout <<"Este programa solicita dos cadenas y compara si ambas son iguales" <<endl;
    cout << "Ingrese una cadena 1 : " ;
    cin.getline(palabra1,100); // se tomará en cuenta los espacios y máximo 100 caracteres
    cout << "Ingrese una cadena 2 : " ;
    cin.getline(palabra2,100);

    if(compararCadenas(palabra1,palabra2)){
        // llamado a la función , se espera false o true
        // si cumple entonces:
        cout << "Las palabras Ingresadas son Iguales " << endl;
    }
    else{
        // las palbras no son iguales entonces //
        cout << "Las palabras NO son iguales  " << endl;
    }
    return 0;
}


bool compararCadenas(const char *ptr_cadena1 , const char *ptr_cadena2){
    bool same_word = true ; // variable de control //

    for(short int iterator=0 ; iterator < 100 ; iterator ++){
        // se iterará por cada elemento independiente del array 1 y 2
        if(ptr_cadena1[iterator] != ptr_cadena2[iterator]){
            // si por alguna razón una letra no cumple con ser igual //
            // la variable de control , que inicialmente era verdadera --> falsa //
            // se descartan los demás pasos y termina la función //
            return false;
        }

        if(ptr_cadena1[iterator] =='\0' || ptr_cadena2[iterator]=='\0'){
            // mientras se cumpla que los caracteres son iguales se procederá a verificar //
            // si la busqueda coincide con ser un fin de línea se procederá a retornar lo que contenga //
            // la varible de control está condición tienes 3 posibles salidas.
            // cadena1 = \0     cadena2 = \0  ---> sameword  será true
            // cadena1 = \0     cadena2 = ?   ---> sameword  será false por condición anterior
            // cadena1 =  ?     cadena2 = \0  ---> sameword  será false por condición anterior
            return same_word;
        }
    }
    return true;
}
