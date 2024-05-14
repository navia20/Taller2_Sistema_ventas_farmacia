#include <iostream>
#pragma once
using namespace std;

class Cliente{
private:
    string nombre;
    int edad;
    bool discapacitado;
    bool embarazada;
public:
    //Constructor
    Cliente (string nombre, int edad);
    //Getters
    string getNombre();
    int getEdad();
    //Setters
    void setNombre (string nombre);
    void setEdad (int edad);
    void setDiscapacitado (bool discapacitado_);
    void setEmbarazada (bool embarazada_);
    //Metodos de verificacion
    bool isDiscapacitado ();
    bool isEmbarazada ();
    
};