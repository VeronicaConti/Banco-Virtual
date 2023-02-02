#ifndef COLA_H
#define COLA_H
#include "Lista.h"
#include <iostream>
#include <string>
#include "Cliente.h"

 using namespace std;

template <typename Cliente>
class cola
{
    public:
        cola();
        ~cola();
        bool AgregarC(const Cliente &c, string opC, bool isClienteC);//agrega un cliente al final de la cola
        void EliminarElemento(const int &posicion);//elimina un cliente en una posicion dada
        void EliminarElemento(); //Elimina el elemento apuntado por aux, por eso no necesita parametro de posicion
        void BorrarCola();//borra la cola
        bool VaciaCola();//devuelve si la cola esta vacia o no
        bool VaciaColAux() const;
        int CantElementos()const;//devuelve la cantidad de clientes en la cola
        void Siguiente();//apunta al siguiente cliente
        const Cliente &elem() const;//devuelve un cliente
        void habilitarCola();//habilita una cola especial
        void deshabilitarCola();//deshabilita una cola especial
        bool isHabilitada() const;//devuelve si una cola especial esta habilitada o no
        void reiniciarIt();// lleva el iterador al comienzo de la cola
        bool finalCola()const;//retorna si es el fin de la cola o no
        Cliente obtenerPrimero();//devuelve el primer cliente
        void setCriterio(string operacion, bool esCliente);//el criterio de operacion y si es cliente para alguna de las dos colas especiales

//------------------------------------ESTRUCTURA PRIVADA------------------------------------------------------------------------------------------
    private:
        struct Criterio {
            string operacion;
            bool esCliente;
        };

        Lista<Cliente>Cola;
        bool habilitada; //devuelve si esta habilitada una cola o no
        Criterio criterio;//asigna criterio

};
#endif // COLA_H
