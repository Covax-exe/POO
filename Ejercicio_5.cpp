/*
* @Ejercicio_5.cpp
* @brief Un programa que recibe dos numeros (x,y) y los compara, los prosibles resultados
* son: x > y, ó y > x, ó x = y.
*
* @details El uso de los condicionales y los conectores se hacen presentes a la hora de evaluar ambos numeros para así poder
* cubrir con el problema de saber cual de los 2 es más grande ó si ambos son iguales.
* @author [Lina Vanessa Cosme Arce - 2436459]--[Whitsell Stiven Diosa Villada - 2439170]
* @mail [lina.cosme@correounivalle.edu.co]--[whitsell.diosa@correounivalle.edu.co] 
* @date 2025-03-08
* @version 1.23.6
*
* @comentario: se uso el uso de condicionales para asi simplificar el codigo.

*/

#include <iostream>
using namespace std;
int main(){
    /*se define los numero de entrada como floats para así cubrir tmbn la posibilidad
      que el usuario ingrese decimales  */
    float nUno,nDos;
    cout<<"Digite el primer numero: ";
    cin>> nUno;
    cout<<"Digite el segundo numero: ";
    cin>>nDos;
    //se crean los condicionales que evaluaran los posibles resultados al comparar los numeros ingresados.
    if(nUno > nDos)
    {
        cout<<"El numero mayor es: "<<nUno<<endl;
    }
    else if(nDos > nUno)
    {
        cout<<"El numero mayor es: "<<nDos<<endl;
    }
    else
    {
        cout<<"Los numeros son iguales...."<<endl;
    }
    return 0;
}

