#include "ListaProductos.h"
#include <sstream> 
using namespace std;
ListaProductos::ListaProductos() {
    raiz = NULL;
}

ListaProductos::~ListaProductos() {
    if (raiz != NULL) {
        NodoP *reco = raiz->sig;
        NodoP *bor;
        while (reco != raiz) {
            bor = reco;
            reco = reco->sig;
            delete bor;
        }
        delete raiz;
    }
}

void ListaProductos::insertarPrimero(Producto* x) {
    NodoP *nuevo = new NodoP();
    nuevo->producto = x;
    if (raiz == NULL) {
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        raiz = nuevo;
    } else {
        NodoP *ultimo = raiz->ant;
        nuevo->sig = raiz;
        nuevo->ant = ultimo;
        raiz->ant = nuevo;
        ultimo->sig = nuevo;
        raiz = nuevo;
    }
}

void ListaProductos::insertarUltimo(Producto* x) {
    NodoP *nuevo = new NodoP();
    nuevo->producto = x;
    if (raiz == NULL) {
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        raiz = nuevo;
    } else {
        NodoP *ultimo = raiz->ant;
        nuevo->sig = raiz;
        nuevo->ant = ultimo;
        raiz->ant = nuevo;
        ultimo->sig = nuevo;
    }
}

bool ListaProductos::vacia() {
    return raiz == NULL;
}

void ListaProductos::imprimir() {
    if (!vacia()) {
        NodoP *reco = raiz;
        cout <<"ID    Producto    Categoria    Subcategoria    Precio"<< endl;
        cout <<"---------------------------------------------------------"<<endl;
        do {
            cout <<reco->producto->getId();
            cout <<"  "<< reco->producto->getNombre();
            cout <<"  "<< reco->producto->getCategoria();
            cout <<"  "<< reco->producto->getSubcategoria();
            cout <<"  $"<< reco->producto->getPrecio()<<endl;
            reco = reco->sig;
        } while (reco != raiz);
        cout << "\n";
    }
}

int ListaProductos::cantidad() {
    int cant = 0;
    if (!vacia()) {
        NodoP *reco = raiz;
        do {
            cant++;
            reco = reco->sig;
        } while (reco != raiz);
    }
    return cant;
}

void ListaProductos::borrar(int pos) {
    if (pos <= cantidad()) {
        if (pos == 1) {
            if (cantidad() == 1) {
                delete raiz;
                raiz = NULL;
            } else {
                NodoP *bor = raiz;
                NodoP *ultimo = raiz->ant;
                raiz = raiz->sig;
                ultimo->sig = raiz;
                raiz->ant = ultimo;
                delete bor;
            }
        } else {
            NodoP *reco = raiz;
            for (int f = 1; f <= pos - 1; f++)
                reco = reco->sig;
            NodoP *bor = reco;
            NodoP *anterior = reco->ant;
            reco = reco->sig;
            anterior->sig = reco;
            reco->ant = anterior;
            delete bor;
        }
    }
}

string ListaProductos::convertirTexto() {
    ostringstream texto;
    if (!vacia()) {
        NodoP* reco = raiz;
        do {
            Producto* prod = reco->producto;
            texto << prod->getNombre() << ";" << prod->getCategoria() << ";";
            texto << prod->getSubcategoria() << ";" << prod->getPrecio() << ";" << prod->getId();
            
            reco = reco->sig;
            if (reco != raiz) {
                texto <<endl;
            }
        } while (reco != raiz);
    }   
    return texto.str();
}

void ListaProductos::catalogo() {
    if (!vacia()) {
        NodoP *reco = raiz;
        do {
            cout <<" "<< reco->producto->getId();
            cout <<" "<< reco->producto->getNombre();
            cout <<"  $"<< reco->producto->getPrecio()<<endl;
            reco = reco->sig;
        } while (reco != raiz);
        cout << "\n";
    }
}
    
Producto* ListaProductos::buscarProducto(int id) {
    if (vacia()) {
        return nullptr; 
    }
    NodoP *reco = raiz;
    do {
        if (reco->producto->getId() == id) {
            return reco->producto; 
        }
        reco = reco->sig;
    } while (reco != raiz);
    return nullptr;
}

int ListaProductos::calcularTotal() {
    int total = 0;
    if (!vacia()) {
        NodoP* reco = raiz;
        do {
            Producto* prod = reco->producto;
            total += prod->getPrecio();
            reco = reco->sig;
        } while (reco != raiz);
    }
    return total;
}