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
    NodoP* nodo = raiz;
    string categoriaActual = "";
    string subcategoriaActual = "";
    int productosImpresos = 0;
    if (!vacia()) {

        do {
            // Verificar si la categoría del producto actual es diferente a la categoría anterior
            if (nodo->producto->getCategoria() != categoriaActual) {
                categoriaActual = nodo->producto->getCategoria();
                cout << categoriaActual << endl;
            }
            // Verificar si la subcategoría del producto actual es diferente a la subcategoría anterior
            if (nodo->producto->getSubcategoria() != subcategoriaActual) {
                subcategoriaActual = nodo->producto->getSubcategoria();
                cout << "  " << subcategoriaActual << endl;
            }

            cout << "    " << nodo->producto->getId() << ". " << nodo->producto->getNombre() << " $" << nodo->producto->getPrecio() << endl;
            productosImpresos++;


            nodo = nodo->sig;
        } while (productosImpresos < cantidad());
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