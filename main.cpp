/*
Una Empresa que vende “productos de seguridad industrial NicTech” nos convoca para la
realización de una App que permita registrar los Pedidos de Artículos de los clientes.
En esta etapa del desarrollo, solo deberemos realizar el módulo “Clientes”
La misma debe permitir:
1. Gestionar los Clientes
a. Dar de alta el cliente (el código del cliente es la ubicación en el array x 100).
b. Dar de Baja los clientes x código de cliente.
c. Modificar los clientes, ingresar el código, mostrarlo y editarlo.
2. Listar los Clientes.
a. Listar todos los Clientes.
b. Buscar un Clientes x código y mostrarlo (imprimir cartel de no encontrado).
3. Todo esto mediante un Menú, Modularizando en Funciones, utilizando Archivos, arreglos y
estructuras.
*/

#include <iostream>
#include <fstream>
 
const int MAXCLIENTS = 100;
using namespace std;

typedef struct client
{
    string name;
    string lastName;
    int dni;
    int clientID;


} client;

typedef client clients[MAXCLIENTS];

int menu(clients& tClients, int totalClients);
client createNewclient(int tClientID);
void addNewclient(clients& tClients, int& totalClients);
void deleteclient(clients& tClients, int tDNI, int totalClients);
void editClient(clients& tClients, int tDNI, int totalClients);
void listClients(clients& tClients, int totalClients);
void searchclient(clients& tClients, int tDNI, int totalClients);
int readFromFile(clients& tClients);
void save(clients& tClients, int totalClients);


int main()
{   
    clients Clients;
    int totalClients = 0;

    totalClients = readFromFile(Clients);
    totalClients = menu(Clients, totalClients);
    save(Clients, totalClients);
    return 0;
}

int menu(clients& tClients, int totalClients){

    int requesterDNI = 0;
    int choice;

    while (choice != 6)
    {
        cout << "Sistema de gestion de clientes" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Ingresar cliente." << endl;
        cout << "2. Editar cliente." << endl;
        cout << "3. Eliminar cliente." << endl;
        cout << "4. Listar clientes." << endl;
        cout << "5. Buscar cliente" << endl;
        cout << "6. Cerrar el programa." << endl;
        cout << "--------------------------------" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
           

            addNewclient(tClients, totalClients);
            break;

        case 2:

            cout << "Ingrese DNI del titular de cliente: ";
            cin >> requesterDNI;
            editClient(tClients, requesterDNI, totalClients);

            break;
        case 3: 

            cout << "Ingrese DNI del cliente que desea borrar: ";
            cin >> requesterDNI;
            deleteclient(tClients, requesterDNI, totalClients);

            break;
        case 4:

            listClients(tClients, totalClients);

            break;
        case 5:

            cout << "Ingrese DNI del cliente: ";
            cin >> requesterDNI;
            searchclient(tClients, requesterDNI, totalClients);

            break;
        case 6:

            cout << "Gracias por utilizar nuestro software";

            break;
        default:

            cout << "La opcion ingresada no es valida";

            break;
        }
    }

return totalClients; 
}

client createNewclient(int tClientID)
{
    client newclient;
    newclient.clientID = tClientID * 100;
    cout << "Ingrese Nombre: ";
    cin >> newclient.name;
    cout << "Ingrese Apellido: ";
    cin >> newclient.lastName;
    cout << "Ingrese DNI: ";
    cin >> newclient.dni;

    return newclient;
}
void addNewclient(clients& tClients, int& totalClients)
{
    if (totalClients < MAXCLIENTS)
    {
        tClients[totalClients] = createNewclient(totalClients);
        cout << "Cliente creado con el nro: " << tClients[totalClients].clientID << endl;
        totalClients++;
    }
    else
    {
        cout << "No se pueden agregar más clientes. Límite alcanzado." << endl;
    }
}

void deleteclient(clients& tClients, int tDNI, int totalClients){
    bool choice = false;
    for (int i = 0; i < totalClients; i++)
    {
        if (tDNI == tClients[i].dni)
        {   
            cout << "Desea borrar el cliente " << tClients[i].name << " " <<  tClients[i].lastName << endl << "Ingrese 1 para confirmar o 0 para cancelar";
            cin >> choice;
            if (choice == true)
            {
                for (int j = i; j < totalClients; j++)
                {
                    tClients[j].dni = 0;
                    tClients[j].name = nullptr;
                    tClients[j].lastName = nullptr;
                
                }
                totalClients--;
            }

        }
    }

}

void editClient(clients& tClients, int tDNI, int totalClients){
    cout << "Cliente a editar: ";
    for (int i = 0; i < totalClients; i++)
    {
        if (tDNI == tClients[i].dni)
        {   cout << tClients[i].clientID << "\t" << tClients[i].name << "\t" << tClients[i].lastName;
            cout << "\nIngrese nuevo DNI: ";
            cin >> tClients[i].dni;
            cout << "\nIngrese nuevo nombre: ";
            cin >> tClients[i].name;
            cout << "\nIngrese nuevo apellido: ";
            cin >> tClients[i].lastName;
            break;
    }
}
}

void listClients(clients& tClients, int totalClients)
{
    
    cout << "Listado de clientes: " << endl;
    cout << "Nro de cliente\tNombre\t\tApellido\t\tDNI\n";
    for (int i = 0; i < totalClients; i++)
    {
        cout << tClients[i].clientID<< "\t\t" << tClients[i].name << "\t\t" << tClients[i].lastName<< "\t\t" << tClients[i].dni << endl;
    }
}

void searchclient(clients& tClients, int tDNI, int totalClients){
    for (int i = 0; i < totalClients; i++)
    {
        if (tDNI == tClients[i].dni)
        {   
        cout << "Nombre: " << tClients[i].name << endl;
        cout << "Apellido: " << tClients[i].lastName << endl;
        cout << "Nro de cliente: " << tClients[i].clientID << endl; 
        }
    }
}

int readFromFile(clients& tClients)
{
    ifstream file("clients.txt");
    int countClients = 0;

    if (file.is_open())
    {
        while (countClients < MAXCLIENTS && file >> tClients[countClients].clientID >> tClients[countClients].name >> tClients[countClients].lastName >> tClients[countClients].dni)
        {
            countClients++;
        }

        file.close();
        cout << "Archivo cargado exitosamente." << endl;
    }
    else
    {
        cout << "No se pudo abrir el archivo clients.txt" << endl;
    }

    return countClients;
}
void save(clients& tClients, int totalClients){
    
    ofstream file("clients.txt");
    if (file.is_open()) {
        for (int i = 0; i < totalClients; i++) {
            file << tClients[i].clientID << " " << tClients[i].name << " " << tClients[i].lastName << " " << tClients[i].dni << endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo clients.txt" << endl;
    }
}