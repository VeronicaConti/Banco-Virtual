#include "Lista.h"
#include "cola.h"
#include "Cliente.h"
#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <limits>
#include <conio.h>
#include <stdio.h>

using namespace std;

Cliente DatosCliente(string &nom, bool &clien,string &ope,string &desti, int &mont, int &edad)
//solicita el ingreso de los datos del cliente, los carga, crea y retorna el cliente c
{
        cout<<"ingrese el nombre "<<endl;
        cin >> nom;
        cout<<"ingrese la edad"<<endl;
        cin >> edad;
        cout<<"ingrese la operacion a realizar: Retiro, Deposito, Transferencia o Pago"<<endl;
        cin >> ope;
        cout<<"ingrese destinatario: persona, banco o impuesto "<<endl;
        cin >> desti;
        cout<<"ingrese si es cliente del banco: si(1)-no(0)"<<endl;
        cin >> clien;
        cout<<"ingrese monto a depositar"<<endl;
        cin >> mont;
        cout << endl;
        Cliente c(nom,edad,ope,desti,clien,mont);
        return c;

}

void IngresaCliente(cola<Cliente> &Cola1, cola<Cliente> &ColaEspecial,cola<Cliente> &ColaEspecial2)
//ingresa el cliente en la cola general o en alguna cola especial si esta habilitada y cumple con los dos criterios
{
        string nom;
        bool clien;
        string ope;
        string desti;
        int mont;
        int edad;
        Cliente Cliente1 = DatosCliente(nom,clien,ope,desti,mont,edad);
        bool agregado = false;
        if (ColaEspecial.isHabilitada()){
            agregado = ColaEspecial.AgregarC(Cliente1,ope,clien);
        }
        if((ColaEspecial2.isHabilitada()) && (!agregado)){
            agregado = ColaEspecial2.AgregarC(Cliente1,ope, clien);
        }
        if (!agregado){
            Cola1.AgregarC(Cliente1, ope, clien);
        }
}

void imprimirDatosCliente(Cliente c)
//muestra los datos del cliente
{
    cout<<" Los datos del cliente son: "<< endl;
    cout<<" NOMBRE: "<<c.getNombre()<< endl;
    cout<<" ES CLIENTE DEL BANCO: "<<c.isCliente()<< endl;
    cout<<" OPERACION A REALIZAR: "<<c.getOperacion()<< endl;
    cout<<" DESTINATARIO: "<<c.getDestinatario()<< endl;
    cout<<" MONTO: "<<c.getMonto()<< endl;
    cout<<" EDAD: "<<c.getEdad()<<endl;
    cout << endl;
}

void mostrarCliente(cola<Cliente> ColaActual, Lista<Cliente> &atendidos)
{
    //Obtener el cliente desde la cola pasada por parametro
    Cliente c = ColaActual.obtenerPrimero();
    //Muestro todos los datos
    imprimirDatosCliente(c);
    //Agrego c al historial
    atendidos.AgregarPrim(c);
    //Elimino c de la cola
    ColaActual.EliminarElemento(0);
}

void ProximoCliente(cola<Cliente> &Cola1, cola<Cliente> &ColaEspecial,cola<Cliente> &ColaEspecial2,Lista<Cliente> &atendidos)
{
    if ((!ColaEspecial.isHabilitada())&& (!ColaEspecial2.isHabilitada()))
    {
        //Solo puedo atender por la general
        mostrarCliente(Cola1,atendidos); //Imprime los datos por pantalla, elimina de la cola, agrega al historial.

    }
    else {
     cout<<" ¿ Quiere ser atendido por la cola: general o especial 1, o especial 2? Ingrese 0, 1, o 2, correspondientemente "<<endl;
     int eleccion;
     cin >> eleccion;
     switch(eleccion){
        case 0:
            mostrarCliente(Cola1,atendidos);
            break;
        case 1:
            if(ColaEspecial.isHabilitada()){
                mostrarCliente(ColaEspecial,atendidos);
            }
            else{
                cout << "Error, la cola especial 1 esta deshabilitada" << endl;
            }
            break;
        case 2:
            if(ColaEspecial2.isHabilitada()){
                mostrarCliente(ColaEspecial2,atendidos);
            }
            else{
                cout << "Error, la cola especial 2 esta deshabilitada" << endl;
            }
            break;
        default:
            cout << "OPCIÓN INCORRECTA" << endl;
     }

    }
}
void llenarColaEspecial(cola<Cliente> &Cola1, cola<Cliente> &ColaEspecial)
{
    Cola1.reiniciarIt();
    Cliente c;
    string opC;
    bool esClienteC;
    while (!Cola1.finalCola()){
        c = Cola1.elem();
        opC = c.getOperacion();
        esClienteC = c.isCliente();
        //Comparar segun criterios
        if (ColaEspecial.AgregarC(c, opC, esClienteC)){ //Si pude agregar, elimino
            Cola1.EliminarElemento();
        }
        //Si no agregue, es porque no cumple, entonces no hago nada
        Cola1.Siguiente();
    }
    //Ya recorri todo
}
void solicitarCriterios(string &operacion, bool &esCliente)
{
    cout<<"ingrese la operacion: "<<endl;
    cin>>operacion;
    cout << "" << endl;
    cout<<"ingrese si desea que sea cliente: si(1) - no(0)"<<endl;
    cin>>esCliente;
    cout << "" << endl;
    cout << "" << endl;
}
void NuevaColaEspecial(cola<Cliente> &Cola1, cola<Cliente> &ColaEspecial,cola<Cliente> &ColaEspecial2)
//si alguna cola especial de las dos, NO esta habilitada, solicito el criterio y habilito una cola especial
{
    string operacion;
    bool esCliente;
    if (ColaEspecial.isHabilitada()){
        if (ColaEspecial2.isHabilitada()){
            cout<<" las dos colas especiales ya estan habilitadas"<<endl;
            return;//salir y volver al menu principal
        }
        else{
            ColaEspecial2.habilitarCola();
            solicitarCriterios(operacion,esCliente);
            ColaEspecial2.setCriterio(operacion,esCliente);
            llenarColaEspecial(Cola1,ColaEspecial2);
        }
    }
    else{
        ColaEspecial.habilitarCola();
        solicitarCriterios(operacion,esCliente);
        ColaEspecial.setCriterio(operacion,esCliente);
        llenarColaEspecial(Cola1,ColaEspecial);
    }
}
void CerrarColaEspecial(cola<Cliente> &ColaEspecial,cola<Cliente> &ColaEspecial2)
//solicita el numero de la cola especial para cerrar y si esta vacia la deshabilita sino no hace nada
{
    int opcion;
    cout<< "ingrese el numero de cola especial a cerrar: 1-2"<<endl;
    cin>>opcion;
    switch (opcion){
    case 1:
        if (ColaEspecial.VaciaCola()){
            ColaEspecial.deshabilitarCola();
            cout<<"se deshabilito la cola especial 1"<<endl;
        } else{
             cout<<"la cola especial 1 no se puede cerrar porque no esta vacia"<<endl;
        }
        break;
    case 2:
        if (ColaEspecial2.VaciaCola()){
            ColaEspecial2.deshabilitarCola();
            cout<<"se deshabilito la cola especial 2"<<endl;
        } else{
             cout<<"la cola especial 2 no se puede cerrar porque no esta vacia"<<endl;
        }
        break;
    default:
        cout<<"opcion incorrecta"<<endl;
        break;
    }
}
void ListarOperaciones(Lista<Cliente> &atendidos)
//solicita un monto minimo y un monto maxim, recorre la lista de atendidos suma la edad de los clientes dentro de ese rango y lleva un contador para retornar el promedio
{
    int cantidad = 0;
    double promedio = 0.0;
    int suma = 0;
    //Solicitar datos al usuario
    int montoMin, montoMax;
    cout<<"ingrese el monto minimo: "<<endl;
    cin>>montoMin;
    cout<<"ingrese el monto maximo: "<<endl;
    cin>>montoMax;
    //Recorrer toda la lista
    atendidos.reiniciarIte();
    while (!atendidos.finalLista()){
        //obtengo cliente
        Cliente c = atendidos.elemento();
        if ((c.getMonto() >= montoMin) && (c.getMonto() <= montoMax)){
            imprimirDatosCliente(c);
            suma += c.getEdad();
            cantidad++;
        }
        atendidos.Sig();// avanzo el iterador
    }
    promedio = suma/cantidad;
    cout<<"el promedio de edad de los clientes del listado es: "<< promedio<<endl;
}
void Menu(int & OpcionMenu)
{
        cout<<"   MENU DE OPCIONES "<<endl;
        cout<<"1. INGRESA UN NUEVO CLIENTE"<<endl;
        cout<<"2. PROXIMO CLIENTE"<<endl;
        cout<<"3. NUEVA COLA ESPECIAL"<<endl;
        cout<<"4. CERRAR COLA ESPECIAL"<<endl;
        cout<<"5. LISTAR OPERACIONES SEGUN MONTOS"<<endl;
        cout<<"6. SALIR"<<endl;
        cout << endl;
        cout<<"INGRESA UNA OPCION"<<endl;
        cin >> OpcionMenu;
        cout << endl;
}

void MenuActividades(cola<Cliente> &Cola1, cola<Cliente> &ColaEspecial,cola<Cliente> &ColaEspecial2, Lista<Cliente> &atendidos)

{
    bool salir = false;
    int OpcionMenu;
    while(!salir)
    {
        Menu(OpcionMenu);
        switch(OpcionMenu)
        {
            case 1:IngresaCliente(Cola1,ColaEspecial,ColaEspecial2);break;
            case 2:ProximoCliente(Cola1,ColaEspecial,ColaEspecial2,atendidos);break;
            case 3:NuevaColaEspecial(Cola1,ColaEspecial,ColaEspecial2);break;
            case 4:CerrarColaEspecial(ColaEspecial,ColaEspecial2);break;
            case 5:ListarOperaciones(atendidos);break;
            case 6:salir=true;break;
            default:cout<<"OPCION INCORRECTA"<<endl;
        }
    }
    cout << "SALIO DEL MENU" << endl;
}

int main()

{   cola<Cliente>Cola1; //General, por orden de llegada
    cola<Cliente>ColaEspecial; //Especial, con criterio
    cola<Cliente>ColaEspecial2; //Especial, con criterio
    Lista<Cliente>atendidos;//lista de clientes atendidos
    cout << "        BANCO, AGUARDE UN MOMENTO Y SERA ATENDIDO     " << endl;
    cout << endl;
    cout << "BIENVENIDO" << endl;
    cout << endl;
    MenuActividades(Cola1,ColaEspecial,ColaEspecial2,atendidos);//menu principal
    return 0;
}
