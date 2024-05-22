#include "Producto.h"
using namespace std;

Producto::Producto( string nombre, string categoria,string subcategoria, int precio, int id) {
    this->nombre = nombre;
    this->categoria = categoria;
    this->subcategoria = subcategoria; 
    this->precio = precio;
    this->id = id;
}

string Producto::getNombre() {
    return this->nombre;
}

string Producto::getCategoria() {
    return this->categoria;
}
string Producto::getSubcategoria() {
    return this->subcategoria;
}

int Producto::getPrecio() {
    return this->precio;
}

int Producto::getId() {
    return this->id;
}

void Producto::setNombre(string nuevoNombre) {
    this->nombre = nuevoNombre;
}

void Producto::setCategoria(string nuevaCategoria) {
    this->categoria = nuevaCategoria;
}

void Producto::setSubcategoria(string nuevaSubcategoria) {
    this->subcategoria = nuevaSubcategoria;
}

void Producto::setPrecio(int nuevoPrecio) {
    this->precio = nuevoPrecio;
}

void Producto::setId(int nuevoId) {
    this->id = nuevoId;
}

void Producto::imprimir(){
        cout << "Nombre: " << nombre << endl;
        cout << "Categoría: " << categoria << endl;
        cout << "Subcategoría: " << subcategoria << endl;
        cout << "Precio: " << precio << endl;
        cout << "ID: " << id << endl;
        cout << "------------------------" << endl;
}