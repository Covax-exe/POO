/*
* @Ejercicio_6.cpp
* @brief un programa que recibe una lista de numeros que se tienen que poner en pila pero deben cumplir con ciertos parametros.
*
* @details El uso de los condicionales y los ciclos/bucles se hacen presentes a la hora de agregar o no los numeros a la pila,
* e imprimir la pila resultante.
* @author [Lina Vanessa Cosme Arce - 2436459]--[Whitsell Stiven Diosa Villada - 2439170]
* @mail [lina.cosme@correounivalle.edu.co]--[whitsell.diosa@correounivalle.edu.co] 
* @date 2025-03-08
* @version 1.23.6
*
* @comentario: se uso la libreria stack para así poder crear una pila y trabajar en la misma.

*/
//aca "llamamos" la librería stack para así poder apilar elementos
#include <stack>
#include <iostream>
using namespace std;
int main(){
    //Aca se define la pila y lo que alamecenará, en este caso trabajaremos con enteros.
    stack <int> pila;
    //creamos una lista de los numeros que entraran a la pila.
    int numeros[] = {1,22,3,5,0};
    //creamos un contador que indnicara el tamaño de los elementos apilados.
    int tama = 0;
    //creamos un ciclo for con los parametros de la lista ya establecida para asi ir apilando los numeros.
    for (int i = 0; i<5; i++){ 

        int num = numeros[i];
        //se toma el cero como el que para el ciclo de apilamiento.
        if (num == 0) break;
        //si el numero es par, no entra a ser apilado.
        if (num % 2 == 0){
            cout<<"El numero: "<<num<<", ha sido apilado."<<endl;
            pila.push(num);
            pila.pop();
            tama++;
            tama = tama - 1;
            cout<<"EL numero: "<<num<<", ha sido desapliado"<<endl;
            cout<<"Tamano de la pila: "<<tama<<endl;
        }
        else{
            pila.push(num);
            cout << "el numero: "<<numeros[i]<<", se apilo."<<endl;
            cout<<"el numero NO se desapilo."<<endl;
            tama = tama + 1;
            cout<<"Tamano de la pila: "<<tama<<endl;
        }

    }
    //aca se imprime la pila final.
    while(!pila.empty()){
        cout << pila.top()<<endl;
        pila.pop();
    }
    return 0;
}
    