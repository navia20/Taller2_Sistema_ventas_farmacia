#include "Cliente.h"
using namespace std;

Cliente::Cliente(string nombre, int edad) {
    this->nombre = nombre;
    this->edad = edad;
    this->discapacitado = false; 
    this->embarazada =false;    
}
void Cliente::setNombre(string name) {
    this->nombre = name;
}
string Cliente::getNombre() {
    return this->nombre;
}
void Cliente::setEdad(int edad) {
    this->edad = edad;
}
int Cliente::getEdad() {
    return this->edad;
}
void Cliente::setDiscapacitado(bool discapacitado_) {
    this->discapacitado = discapacitado_;
}
bool Cliente::isDiscapacitado() {
    return this->discapacitado;
}
void Cliente::setEmbarazada(bool embarazada_) {
    this->embarazada = embarazada_;
}
bool Cliente::isEmbarazada() {
    return this->embarazada;
}