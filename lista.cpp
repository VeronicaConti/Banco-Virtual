#include "Lista.h"
#include <cstddef>
#include <string>
#include "Cliente.h"

using namespace std;

template <typename T>
Lista<T>::Lista()
//CONSTRUCTOR
{
    first = NULL;
    last = NULL;
    aux = first;
    size = 0;

}

template <typename T>
void Lista<T>::newNodo(Nodo * &nodo, const T &Elemento)
{
    nodo = new Nodo;
    nodo->Elemento = Elemento;
    nodo->Sig = NULL;
}

template <typename T>
void Lista<T>::AgregarPrim(const T &Elemento)
{

    Nodo * nodo = NULL;
    newNodo(nodo, Elemento);
    if ( size == 0)
    {
        first = nodo;
        last = nodo;
        aux = first;
    } else
    {
        nodo-> Sig = first;
        first = nodo;
        aux = first;
    }
    size++;
}
template <typename T>
void Lista<T>::AgregarUlt(const T &Elemento)
{
    Nodo * nodo = NULL;
    newNodo(nodo, Elemento);
    if (size == 0){
        AgregarPrim(Elemento);
    }else
    {
        last->Sig = nodo;
        last = nodo;
    }
    size++;
}

template <typename T>
bool Lista<T>::VaciaLista() const
{
    return (first == NULL);
}

template <typename T>
bool Lista<T>::VaciaListAux() const
{
    return (aux == NULL);
}
template <typename T>
void Lista<T>::buscarPos(Nodo * &nodo, const int &posicion)
{
    int contador = 0;
    while (contador < posicion)
    {
        nodo = nodo ->Sig;
        contador++;
    }
}
template <typename T>
void Lista<T>::EliminarE(const int &posicion)
{
    if ((posicion>= 0)&& (posicion<size))
    {
        Nodo * nodo = first;
        if (posicion > 0)
        {
            buscarPos(nodo,posicion-1);
            Nodo * nodo2 = nodo->Sig;
            nodo->Sig = nodo2->Sig;
            nodo2->Sig = NULL;
            delete nodo2;
            size--;
        }
    }
    else
        EliminarPrim();
}
template <typename T>
void Lista<T>::EliminarE()
{
    Nodo * it = first;
    while (it->Sig!=aux){
        it = it->Sig;
    }
    it->Sig = aux->Sig;
    aux->Sig = NULL;
    size--;
    aux = it;
}

template <typename T>
void Lista<T>::EliminarPrim()
{
    if (first!=NULL)
    {
        Nodo * aux = first;
        first= aux->Sig;
        delete aux;
        size--;
        this->aux = first;
    }
}
template <typename T>
void Lista<T>::BorrarTodo()
{
    while (size != 0){
        EliminarPrim();
        first=NULL;
        last=NULL;
        aux=NULL;
    }
}
template <typename T>
int Lista<T>::CantE()const
{
    return size;
}
template <typename T>
void Lista<T>::Sig()
{
    aux=aux->Sig;
}

template <typename T>
const T & Lista<T>::elemento() const
{
    return aux->Elemento;
}
template <typename T>
void Lista<T>::reiniciarIte()
{
    this->aux=first;
}
template <typename T>
bool Lista<T>::finalLista()const
{
    return aux==NULL;
}
template <typename T> Lista<T>::~Lista()
//DESTRUCTOR
{
    first=NULL;
    last=NULL;
    aux=NULL;
}

template class Lista<int>;
template class Lista<string>;
template class Lista<Cliente>;
