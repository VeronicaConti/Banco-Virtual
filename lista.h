#ifndef LISTA_H
#define LISTA_H
//clase Lista

template <typename T>
class Lista
{
    public:
        Lista(); // constructor
        ~Lista(); // Destructor
        void AgregarPrim(const T &Elemento);//agrega un cliente al comienzo de la lista
        void AgregarUlt(const T &Elemento);//agrega un cliente al final de la lista
        int CantE() const;//decuelve la cantidad de clientes en la lista
        bool VaciaLista() const;//devuelve true si la lista esta vacia, false si tiene clientes
        void EliminarE(const int &posicion);//elimina un cliente en una posicion dada
        void EliminarE();//Elimina el cliente apuntado por aux, por eso no necesita parametro de posicion
        void Sig();//apunta al siguiente cliente
        const T &elemento() const;//devuelve un cliente
        void BorrarTodo();//borra todos los clientes
        bool VaciaListAux() const;//vacia lista auxiliar
        void reiniciarIte();//reinicia al inicio el iterador
        bool finalLista()const;// retorna si es el final de la lista o no

//-----------------------------------ESTRUCTURA PRIVADA---------------------------------------------------------------------------

    private:
        struct Nodo {
            T Elemento;
            Nodo * Sig;
        };

        Nodo * aux;
        Nodo * first;
        Nodo * last;

        int size;
//----------------------------------OPERACIONES AUXILIARES-------------------------------------------------------------------------

        void newNodo(Nodo * & nodo, const T & Elemento);//crea un nuevo nodo
        void borrarNodo(Nodo * &nodo);//borra un nodo
        void buscarPos(Nodo * &nodo, const int &posicion);//busca una posicion
        void EliminarPrim();//elimina al primer elemento
};

#endif // LISTA_H
