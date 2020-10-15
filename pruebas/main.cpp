#include <iostream>

using namespace std;

int main()
{
    char numeros[100];
    unsigned short int counter=0;
    unsigned short int numero = 0 ;
    cout << "Ingrese los numeros para convertir : " ;
    cin >> numeros ;
    for(unsigned short int i=0;i < 100 ; i++){
        if(numeros[i]=='\0'){
            break;
        }
        else{
            cout << numeros[i]  << endl;
            counter++;

        }
    }
    cout << "longitud del arreglo "<<counter<<endl;
    counter=counter-1;
    for(unsigned short int k=0 ; k < counter ; k++){
        numero=numeros[k]*(10*(counter));
        counter--;
        cout << "numero en la iteracion "<<k <<" -> "<<numero<<endl;
    }
    return 0;
}
