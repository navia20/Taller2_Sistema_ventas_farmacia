#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> // uso de vector exclusivamente par definir partes de una linea al momento de leer archivo .txt (linea 78)
#include <limits>

using std::string;
using std::cout;
using std::endl;
using std::cin;

Sistema::Sistema (){
  listaProductos = new ListaProductos();
  colaClientes = new ColaClientes();
}
void Sistema::menu (Sistema * sistema){
  leerBodega ("bodega.txt");
  int opcion;
  do{
	  cout << "------ Menu ------" << endl;
	  cout << "1. Agregar cliente a la cola" << endl;
	  cout << "2. Llamar siguiente cliente" << endl;
	  cout << "3. Agregar producto a la bodega" << endl;
	  cout << "4. Mostrar productos en bodega" << endl;
	  cout << "5. Salir" << endl;
	  cout << "------------------" << endl;
	  cout << "Ingrese una opcion: ";
	  cin >> opcion;
	  if (cin.fail ()){
		  cout << "Entrada invalida. Por favor, ingrese un numero." << endl;
		  cin.clear ();
		  cin.ignore (numeric_limits < streamsize >::max (), '\n');
		  continue;
	  }
	  switch (opcion){
		case 1:{
		    cout << "------ Entrega de numero ------" << endl;
		    agregarClienteCola(colaClientes);
			break;
		  }
		case 2:{
            llamarCliente(colaClientes,listaProductos);
			break;
		  }
		case 3:{
		  cout<<"------ Agregar Producto ------"<<endl;
		  agregarProducto(listaProductos);
			break;
		  }
		case 4:{
		cout<<"------ Productos en la bodega ------"<<endl;
		listaProductos->imprimir();
			break;
		  }
		case 5:{break;}
		default:
		  {
			cout << "Opcion invalida. Intente de nuevo." << endl;
			break;
		  }
		}
	} while (opcion != 5);
  guardarBodega("bodega.txt",listaProductos);
}

void Sistema::leerBodega(const string& archivo) {
    cout << "Archivo: " <<archivo<< endl;
    ifstream file(archivo);
    if (!file.is_open()) {
        cout << "Error, no se ha encontrado el archivo." << endl;
        return;
    }
    string line;
    cout<<"Cargando archivo..."<<endl;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> parts; //"uso de vector exclusivamente par definir partes de una linea al momento de leer archivo .txt"
        string part; 
        while (getline(ss, part, ';')) {
            parts.push_back(part);
        }
        string nombre = parts[0];
        string categoria = parts[1];
        string subcategoria = parts[2];
        int precio = stoi(parts[3]);
        int id = stoi(parts[4]);
        Producto* producto= new Producto(nombre, categoria, subcategoria, precio, id);
        listaProductos->insertarUltimo(producto);
    }
    file.close(); 
    cout<<"Lectura de archivo exitoso."<<endl;
}

void Sistema::agregarProducto(ListaProductos* listaProductos){
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   
    string nombre;
    string categoria;
    string subcategoria;
    int precio;
    int id;
    cout << "Ingrese el nombre del producto: ";
    getline(cin, nombre);
    cout << "Ingrese la categoria del producto: ";
    getline(cin, categoria);
    cout << "Ingrese la subcategoria del producto: ";
    getline(cin, subcategoria);
    while (true) {
        cout << "Ingrese el precio del producto: ";
        if (!(cin >> precio)) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error, Ingrese un valor numérico valido para el precio." << endl;
        } else {
            break;
        }
    }
    id = listaProductos->cantidad() + 1;
    Producto* nuevoProducto = new Producto(nombre, categoria, subcategoria, precio, id);
    listaProductos->insertarUltimo(nuevoProducto);
    cout << "Producto agregado con exito." << std::endl;
    cout << "------------------------" << endl;
    cout << "Resumen de Producto agregado:" << endl;
    nuevoProducto->imprimir();
}

void Sistema::guardarBodega(const string& archivo, ListaProductos* listaProductos) {
   cout << "Guardando datos..." << endl;
    ofstream file(archivo);
    if (!file.is_open()) {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }
    string textoProductos = listaProductos->convertirTexto();
    file << textoProductos << endl;
    file.close();
    cout << "Datos guardados exitosamente en " << archivo << endl;
}

void Sistema::agregarClienteCola(ColaClientes* colaClientes) {
    string nombre;
    int edad;
    int tipoCliente;
    bool esPreferencial = false;
    bool esDiscapacitado = false;
    bool estaEmbarazada = false;
    cout << "Ingrese el nombre del cliente: ";
    cin.ignore(); 
    getline(cin, nombre);
    bool entradaValida = false;
    while (!entradaValida) {
        cout << "Ingrese la edad del cliente: ";
        if (!(cin >> edad)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error: Ingrese un valor numerico valido para la edad." << endl;
        } else if (edad < 0 || edad > 100) {
            cout << "Error: La edad debe estar entre 0 y 100 años." << endl;
        } else {
            entradaValida = true; 
        }
    }
    if (edad >= 60) {
        esPreferencial = true;
    } else {
        cout << "Tipo de cliente:" << endl;
        cout << "1 - Normal" << endl; 
        cout << "2 - Preferencial" <<endl;
        cout << "Ingrese una opcion: ";
        while (!(cin >> tipoCliente) || (tipoCliente != 1 && tipoCliente != 2)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Error: Seleccione una opcion valida (1 para normal, 2 para preferencial): " ;
        }
        if (tipoCliente == 2) {
            esPreferencial = true;
            int tipoPreferencial;
            cout << "Tipo de cliente preferencial:" << endl;
            cout << "1 - Discapacidad" << endl;
            cout << "2 - Embarazada" << endl;
            cout << "Ingrese una opcion: ";
            while (!(cin >> tipoPreferencial) || (tipoPreferencial != 1 && tipoPreferencial != 2)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Error: Seleccione una opción valida (1 para Discapacidad, 2 para Embarazada): ";
            }
            if (tipoPreferencial == 1) {
                esDiscapacitado = true;
            } else if (tipoPreferencial == 2) {
                estaEmbarazada = true;
            }
        }
    }
    Cliente* nuevoCliente = new Cliente(nombre, edad);
    nuevoCliente->setDiscapacitado(esDiscapacitado);
    nuevoCliente->setEmbarazada(estaEmbarazada);
    if (esPreferencial) {
        colaClientes->agregarCliente(nuevoCliente, PREFERENCIAL);
    } else {
        colaClientes->agregarCliente(nuevoCliente, NORMAL);
    }
    
    cout << "Cliente agregado exitosamente." << endl;
}

void Sistema::llamarCliente(ColaClientes* colaClientes, ListaProductos* listaProductos) {
    int option;
    if (!colaClientes->hayClientes()) {
        cout << "No hay clientes en la fila." << endl;
        return;
    }
    Cliente* clienteActual = colaClientes->siguienteCliente();
    if (clienteActual == nullptr) {
        cout << "Error: No se pudo obtener el siguiente cliente." << endl;
        return;
    }
    cout << "Cliente: " << clienteActual->getNombre() << "; Edad: " << clienteActual->getEdad() << endl;
    cout << "ID  Producto  Precio " <<endl;
    cout << "---------------------" <<endl;
    listaProductos->catalogo();
    ListaProductos* productosSeleccionados = new ListaProductos();
    int idProducto = -1;
    while (idProducto != 0) {
        cout << "Ingrese el ID del producto que desea comprar (0 para finalizar): ";
        cin >> idProducto;
        Producto* producto = listaProductos->buscarProducto(idProducto);

        if (producto == nullptr) {
            cout << "Producto no encontrado. Intente nuevamente." << endl;
        } else {
            productosSeleccionados->insertarUltimo(producto);

            cout << "Producto agregado: " << producto->getNombre() << endl;
        }
    }
    if (!productosSeleccionados->vacia()) {
        cout<<"Resumen carrito:"<<endl;
        cout << "ID  Producto  Precio " <<endl;
        cout << "---------------------" <<endl;
        productosSeleccionados->catalogo();
        cout<<"------------------"<<endl;
        cout<<"Total a pagar: $"<<productosSeleccionados->calcularTotal()<<endl;
        cout<<"Metodo de pago:"<<endl;
        cout<<"1) Efectivo | 2) Tarjeta Debito/Credito | 3) Transferencia | 4) Cheque"<<endl;
        bool entradaValida = false;
        while (!entradaValida) {
            cout << "Ingrese una opcion: ";
            if (!(cin >> option)) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Error: Ingrese un valor numerico valido." << endl;
            } else if (option < 0 || option > 100) {
                cout << "Error: Seleccione una opcion valida." << endl;
            } else {
                entradaValida = true; 
            }
            cout << "Pago exitoso." << endl;
            int opcion;
            cout << "¿Llamar siguiente cliente?" << endl;
            cout << "1. Sí              0. No" << endl;
            cout << "Ingrese su opcion (0 para No, 1 para Si): ";
            cin >> opcion;
            if (opcion == 1) {
                cout << "Llamando al siguiente cliente..." << endl;
                llamarCliente(colaClientes,listaProductos);
            } else if (opcion == 0) {
                cout<<"Cargando menu..."<<endl;
            } else {
                cout << "Opción invalida. Volviendo al menu..." << endl;
            }
        }
    } 
} 