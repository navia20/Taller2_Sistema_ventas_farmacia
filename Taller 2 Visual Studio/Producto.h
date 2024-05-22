#include <iostream>
#pragma once
using namespace std;

class Producto {
private:
    string nombre;
    string categoria;
    string subcategoria;
    int precio;
    int id;
public:
    //Contructor
    Producto(string nombre, string categoria, string subcategoria, int precio, int id);
    //Getters
    string getNombre();
    string getCategoria();
    string getSubcategoria();
    int getPrecio();
    int getId();
    //Setters
    void setNombre(string nuevoNombre);
    void setCategoria(string nuevaCategoria); 
    void setSubcategoria(string nuevaSubcategoria); 
    void setPrecio(int nuevoPrecio);
    void setId(int nuevoId);
    void imprimir();
};