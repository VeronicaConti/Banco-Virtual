#include "cola.h"
#include "Lista.h"
#include "Cliente.h"
#include <string>

template <typename Cliente>
cola<Cliente>::cola()
{
    //ctor
    this->habilitada = false;
    this->criterio.esCliente = false;
    this->criterio.operacion = "general";
}

template <typename Cliente>
bool cola<Cliente>::AgregarC(const Cliente &c, string opC, bool isClienteC)
{
    /*
    //Codigo original que no anda porque no compila
    if ((criterio.operacion == c.getOperacion()) && (criterio.esCliente == c.isCliente())){
         Cola.AgregarUlt(c);
         return true;
    }
    return false;
    */
    if (criterio.operacion=="general"){ //Camino de la cola general (no importan los criterios)
        Cola.AgregarUlt(c);
        return true;
    }
    else if ((criterio.operacion == opC) && (criterio.esCliente == isClienteC)){ //Camino de la cola especial (si importan los criterios)
        Cola.AgregarUlt(c);
        return true;
    }
    return false;
}
template <typename Cliente>
void cola<Cliente>::Siguiente()
{
    return Cola.Sig();
}
template <typename Cliente>
bool cola<Cliente>::VaciaCola()
{
    return Cola.VaciaLista();
}

template <typename Cliente>
bool cola<Cliente>::VaciaColAux()const
{
    return Cola.VaciaListAux();
}

template <typename Cliente>
void cola<Cliente>::setCriterio(string operacion, bool esCliente)
{
    this->criterio.operacion=operacion;
    this->criterio.esCliente=esCliente;
}

template <typename Cliente>
const Cliente & cola<Cliente>::elem()const
{
    return Cola.elemento();
}
template <typename Cliente>
Cliente cola<Cliente>::obtenerPrimero()
{
    reiniciarIt();
    return Cola.elemento();
}
template <typename Cliente>
int cola<Cliente>::CantElementos()const
{
    return Cola.CantE();
}
template <typename Cliente>
void cola<Cliente>::EliminarElemento(const int &posicion)
{
    Cola.EliminarE(posicion);
}
template <typename Cliente>
void cola<Cliente>::EliminarElemento()
{
    Cola.EliminarE();
}
template <typename Cliente>
void cola<Cliente>::BorrarCola()
{
    Cola.BorrarTodo();
}

template <typename Cliente>
void cola<Cliente>::habilitarCola()
{
    this->habilitada = true;
}
template <typename Cliente>
void cola<Cliente>::deshabilitarCola()
{
    this->habilitada = false;
}
template <typename Cliente>
void cola<Cliente>::reiniciarIt()
{
    Cola.reiniciarIte();
}
template <typename Cliente>
bool cola<Cliente>::isHabilitada()const
{
    return this->habilitada;
}
template <typename Cliente>
bool cola<Cliente>::finalCola()const
{
    return Cola.finalLista();
}

template <typename Cliente>
cola<Cliente>::~cola()
{
    //dtor
}

template class cola<int>;
template class cola<string>;
template class cola<Cliente>;
