#include <queue>
#include "Cliente.cpp"
#pragma once

enum TipoCliente {NORMAL, PREFERENCIAL};

class ColaClientes {
private:
    queue<Cliente*> clientesNormales;
    queue<Cliente*> clientesPreferencialesTerceraEdad;
    queue<Cliente*> clientesPreferencialesDiscapacidad;
    queue<Cliente*> clientesPreferencialesEmbarazadas;

public:
    //Constructor
    ColaClientes();
    //Destructor
    ~ColaClientes();
    /**
    * Metodo para agregar un cliente a la cola de clientes
    * @param cliente Puntero al objeto Cliente que se va a agregar a la cola
    * @param tipo Tipo de cliente (NORMAL, PREFERENCIAL) determina a qué cola se va a agregar
    */
    void agregarCliente(Cliente* cliente, TipoCliente tipo);
    /**
    * Metodo para obtener el siguiente cliente en la cola
    * @return Puntero al siguiente cliente en la cola
    */
    Cliente* siguienteCliente();
    /**
    * Metodo para corroborar y verificar si hay clientes en alguna de las colas
    */
    bool hayClientes();
};