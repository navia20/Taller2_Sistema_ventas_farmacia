#pragma once
#include <iostream>
#include "ListaProductos.h"
#include "ColaClientes.h"
using namespace std;

class Sistema{
    private:
        ListaProductos* listaProductos;
        ColaClientes* colaClientes;
        /**
        * Metodo para leer los productos de una bodega desde un archivo .txt
        * @param archivo Nombre del archivo
        */
        void leerBodega(const string& archivo);
        /**
        * Metodo para leer los productos de una bodega desde un archivo .txt
        * @param archivo Nombre del archivo
        */        
        void agregarProducto(ListaProductos* listaProductos);
        /**
        * Metodo para guardar la información de la bodega en un archivo
        * @param archivo Nombre del archivo para guardar la información
        * @param listaProductos Puntero a la lista de productos que se desea guardar
        */
        void guardarBodega(const string& archivo, ListaProductos* listaProductos);
        /**
        * Metodo para agregar un cliente a la cola de clientes
        * @param colaClientes Puntero a la cola de clientes donde se agregar el nuevo cliente
        */
        void agregarClienteCola(ColaClientes* colaClientes);
        /**
        * Metodo para llamar al siguiente cliente en la cola y atenderlo
        * @param colaClientes Puntero a la cola de clientes donde se agregar el nuevo cliente
        */
        void llamarCliente(ColaClientes* colaClientes,ListaProductos* listaProductos);
        
    public:
        //Constructor
        Sistema();
        /*
        * Metodo que muestra el menu principal
        * @param Sistema* Donde se guardan los datos
        */
        void menu(Sistema* sistema);
    
};