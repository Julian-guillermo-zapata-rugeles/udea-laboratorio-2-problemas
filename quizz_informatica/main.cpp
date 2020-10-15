/*
1. En el curso de Informática está dividido en parte teórica y parte práctica. En la parte teórica se
realizan tres parciales (uno del 10%, otro del 15% y el final del 20%) y en la parte práctica se
realizan N laboratorios de igual porcentaje cada uno (se debe ingresar la nota de cada lab). El
profesor requiere un programa que calcule la nota definitiva de cada estudiante, el promedio
definitivo del curso y el porcentaje de estudiantes que ganaron la materia. Para el desarrollo del
programa considere lo siguiente:
 El profesor indica el número de estudiantes.
 Todas las notas deben estar entre 0 y 5 (No se necesitan validar datos).
 Al ingresar todas las notas de cada estudiante se debe mostrar su promedio. Se debe
ingresar las notas de un estudiante e ir procesándola (sin arreglos – utilice acumuladores
y contadores)
 El programa debe tener el menú que se muestra a continuación.
 La única manera de terminar el programa es cuando el profesor seleccione la opción de
Salir (ciclos).

tres parciales (uno del 10%, otro del 15% y el final del 20%) total de 45%
N laboratorios de igual porcentaje cada uno
*/

#include <iostream>

using namespace std;

signed short int contador_estudiantes = 0;
signed short int cantidad_laboratorios = 0;
signed short int contador_ganadores = 0 ;
signed short int cantidad_estudiantes = 0;
signed short int estudiantes_evaluados = 0;
float promedio_general=0;
float promedio=0;


int main()
{
    signed short int user_election;
    bool salir=false;
    float temporal_estudiante ;
    float temporal_promedio ;
    float temporal_quizz;
    while(salir==false){
        cout << "1) Ingresar la cantidad de estudiantes "<<endl;
        cout << "2) Ingresar la cantidad de laboratorios "<<endl;
        cout << "3) Ingresar Notas(mostrar definitiva de cada estudiante "<<endl;
        cout << "4) Mostrar promedio del curso "<<endl;
        cout << "5) Mostrar Porcentaje de estudiantes que ganaron "<< endl ;
        cout << "6) Salir"<<endl;
        cin >> user_election;
        if(user_election==1){
            cout << "Estudiantes : ";
            cin >> cantidad_estudiantes;
        }
        if(user_election==2){
            cout << "Laboratorios :";
            cin >> cantidad_laboratorios ;
        }
        if(user_election==3){
            if(cantidad_estudiantes==0 || cantidad_laboratorios ==0){
                cout << "Alerta (Debe Ingresar los estudiantes y laboratorios)" <<endl;
            }
            else{
                for(short int iterator=0; iterator < cantidad_estudiantes; iterator++){
                    temporal_promedio=0;
                    temporal_estudiante=0;

                    int porcent=10;
                    for(short int parcial = 0 ; parcial <3 ; parcial++){
                        cout << "Ingrese la nota del parcial "<<parcial+1<<" : ";
                        cin >> temporal_estudiante;
                        temporal_promedio=temporal_promedio+(temporal_estudiante*porcent)/100;
                        cout << "porcent <-" << porcent <<endl;
                        porcent=porcent+5;
                    }
                    cout << "Parciales :"<< temporal_promedio;
                    // ------- CICLO DE QUIZES
                    temporal_quizz=0;
                    temporal_estudiante=0;
                    for(short int quizz=0 ; quizz < cantidad_laboratorios;quizz ++){
                        cout << "Ingrese la nota del quizz "<<quizz<<" : ";
                        cin >> temporal_estudiante;
                        temporal_quizz=temporal_quizz+temporal_estudiante;
                    }
                    //--------- -----------------------------
                    //cout << temporal_quizz << " antes "<<endl;
                    temporal_quizz=(temporal_quizz/cantidad_laboratorios)*0.55;
                    //cout << temporal_quizz << " despues "<<endl;
                    //cout << temporal_quizz <<"quizes "<< endl;
                    temporal_promedio=temporal_promedio+temporal_quizz;
                    cout <<"Promedio del estudiante :"<< temporal_promedio<<endl;
                    promedio_general+=temporal_promedio;
                    estudiantes_evaluados++;
                    if(temporal_estudiante>=3){
                        contador_ganadores++;
                    }
                }
            }
        }

        if(user_election==4){
            cout << "El promedio del curso fue "<< promedio_general/cantidad_estudiantes<<endl;;
        }
        if(user_election==5){
            cout << "El porcentaje de estudiantes que ganaron fue :"<<((contador_ganadores*cantidad_estudiantes)/100) <<endl;
        }
        if(user_election==6){
            exit(0);
        }
    }
    return 0;
}
