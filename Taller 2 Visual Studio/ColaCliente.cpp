#include "ColaClientes.h"
using namespace std;
ColaClientes::ColaClientes() {
}

void ColaClientes::agregarCliente(Cliente* cliente, TipoCliente tipo) {
    switch (tipo) {
        case NORMAL:
            clientesNormales.push(cliente);
            break;
        case PREFERENCIAL:
            if (cliente->isDiscapacitado())
                clientesPreferencialesDiscapacidad.push(cliente);
            else if (cliente->isEmbarazada())
                clientesPreferencialesEmbarazadas.push(cliente);
            else
                clientesPreferencialesTerceraEdad.push(cliente);
            break;
    }
}

Cliente* ColaClientes::siguienteCliente() {
    if (!clientesPreferencialesTerceraEdad.empty()) {
        Cliente* cliente = clientesPreferencialesTerceraEdad.front();
        clientesPreferencialesTerceraEdad.pop();
        return cliente;
    } else if (!clientesPreferencialesDiscapacidad.empty()) {
        Cliente* cliente = clientesPreferencialesDiscapacidad.front();
        clientesPreferencialesDiscapacidad.pop();
        return cliente;
    } else if (!clientesPreferencialesEmbarazadas.empty()) {
        Cliente* cliente = clientesPreferencialesEmbarazadas.front();
        clientesPreferencialesEmbarazadas.pop();
        return cliente;
    } else if (!clientesNormales.empty()) {
        Cliente* cliente = clientesNormales.front();
        clientesNormales.pop();
        return cliente;
    } else {
        return nullptr; 
    }
}

bool ColaClientes::hayClientes() {
    return !(clientesNormales.empty() && clientesPreferencialesTerceraEdad.empty() &&
             clientesPreferencialesDiscapacidad.empty() && clientesPreferencialesEmbarazadas.empty());
}

ColaClientes::~ColaClientes() {
    while (!clientesNormales.empty()) {
        delete clientesNormales.front();
        clientesNormales.pop();
    }
    while (!clientesPreferencialesTerceraEdad.empty()) {
        delete clientesPreferencialesTerceraEdad.front();
        clientesPreferencialesTerceraEdad.pop();
    }
    while (!clientesPreferencialesDiscapacidad.empty()) {
        delete clientesPreferencialesDiscapacidad.front();
        clientesPreferencialesDiscapacidad.pop();
    }
    while (!clientesPreferencialesEmbarazadas.empty()) {
        delete clientesPreferencialesEmbarazadas.front();
        clientesPreferencialesEmbarazadas.pop();
    }
}