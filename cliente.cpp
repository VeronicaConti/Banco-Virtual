#include "Cliente.h"
#include "cola.h"
#include <string>

Cliente::Cliente(string nom, int edad, string op, string dest, bool cli, int monto)
{
    this->nom = nom;
    this->edad = edad;
    this->op = op;
    this->dest = dest;
    this->cli= cli;
    this->monto = monto;
}

Cliente::Cliente(){
    this->nom = "N/N";
    this->edad = 0;
    this->op = "N/N";
    this->dest = "N/N";
    this->cli = false;
    this->monto = 0;
}

string Cliente::getNombre() const {
    return nom;
}
bool Cliente::isCliente() const {
    return this->cli;
}
int Cliente::getEdad() const {
    return edad;
}

string Cliente::getOperacion() const{
    return this->op;
}
string Cliente::getDestinatario() const {
    return dest;
}

int Cliente::getMonto() const {
    return monto;
}

Cliente::~Cliente()
{
    //dtor
}
