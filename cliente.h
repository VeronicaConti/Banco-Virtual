#ifndef CLIENTE_H
#define CLIENTE_H
#include "cola.h"
#include <iostream>
#include <string>

using namespace std;

class Cliente
{
    public:
        Cliente(string nom, int edad,string op, string dest,bool cli, int monto);//carga los datos del cliente
        Cliente();//inicializa cliente//CONSTRUCTOR
        ~Cliente();//DESTRUCTOR
        string getNombre() const;//devuelve nombre del cliente
        int getEdad() const;//devuelve edad del cliente
        string getOperacion() const;//retorna operacion
        string getDestinatario() const;//retorna destinatario de la operacion
        int getMonto() const;//da el monto de la transaccion
        bool isCliente() const;//retorna si es cliente del banco o no

//-----------------------------------------------ESTRUCTURA PRIVADA-------------------------------------------------------------------

    private:
        string nom;
        int edad;
        int monto;
        string op;
        string dest;
        bool cli;

};


#endif // CLIENTE_H
