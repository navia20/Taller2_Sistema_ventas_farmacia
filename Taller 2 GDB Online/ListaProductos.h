#include <iostream>
#pragma once
#include "Producto.h"
using namespace std;

class ListaProductos {
private:
    class NodoP {
    public:
        Producto* producto;
        NodoP *sig;
        NodoP *ant;
    
    };
    NodoP *raiz;
public:
    //Constructor
    ListaProductos();
    //Destructor
    ~ListaProductos();
    /**
    * Metodo para insertar un producto al inicio de la lista
    * @param x Puntero al objeto Producto que se va a insertar en la lista
    */
    void insertarPrimero(Producto* x);
    /**
    * Metodo para insertar un producto a la ultima posicion de la lista
    * @param x Puntero al objeto Producto que se va a insertar en la lista
    */
    void insertarUltimo(Producto* x);
    /**
    * Metodo para verificar si la lista de productos está vacía
    * @return "true" si hay al menos un cliente en alguna de las colas, "false" en caso contrario.
    */   
    bool vacia();
    /**
    * Metodo para imprimir todos los productos en la lista
    */
    void imprimir();
    /**
    * Metodo para obtener la cantidad de productos en la lista
    * @return Cantidad de productos en la lista.
    */
    int cantidad();
    /**
    * Metodo para borrar un producto de la lista en una posición específica
    * @param pos Posición del producto que se desea borrar (comenzando desde 0)
    * 
    */
    void borrar(int pos);
    /**
    * Metodo para convertir la lista de productos a formato de texto
    * @return Cadena de texto con la representación de la lista de productos
    */
    string convertirTexto();
    /**
    * Metodo para desplegar por consola el catalogo/lista de los productos que hay
    */
    void catalogo();
    /**
    * Metodo para buscar un producto por su ID en la lista de productoS
    * @param ID del producto que se desea buscar.
    * @return Puntero al objeto "Producto" encontrado, o `nullptr` si el producto no está en la lista.
    */
    Producto* buscarProducto(int id);
    /**
    * Metodo que calcula el total de la suma de precios de todos los productos seleccionado.
    * @return Total de la suma de precios de todos los productos en la lista.
    */
    int calcularTotal();
    
};