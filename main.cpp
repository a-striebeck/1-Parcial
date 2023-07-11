/*
Una Empresa que realiza Servicios de Limpieza de Tapizados “Biuty-Sand” nos convoca para la
realización de una App que permita registrar los Pedidos de Embellecimiento de los Autos.
En esta etapa del desarrollo, solo deberemos realizar el módulo “Solicitudes”
La misma debe permitir:
1. Gestionar las Solicitudes
a. Dar de alta la Solicitud (el código de la Solicitud es la ubicación en el array x 100).
b. Dar de Baja las Solicitudes x código de Solicitud.
c. Modificar las Solicitudes, ingresar el código, mostrarlo y editarlo.
2. Listar las solicitudes.
a. Listar todas las Solicitudes.
b. Buscar unas Solicitud x código y mostrarla (imprimir cartel de no encontrado).
3. Todo esto mediante un Menú, Modularizando en Funciones, utilizando Archivos, arreglos y
estructuras.
*/

#include <iostream>
#include <fstream>
 
const int MAXCARS = 100;
using namespace std;

typedef struct car
{
    string name;
    string lastname;
    int dni;
    int ticketID;
    bool isCharged = false;


} car;

typedef car cars[MAXCARS];

int menu(cars& tCars, int totalRequests);
car createNewCar(int tTicketID);
void addNewCar(cars& tCars, int& totalRequests);
car addCarFromFile(string tName, string tLastname, int tDNI, int tTicketID, bool tIsCharged);
void deleteCar(cars& tCars, int tDNI, int totalRequests);
void editCar(cars& tCars, int tDNI, int totalRequests);
void listCars(cars& tCars, int totalRequests);
void searchCar(cars& tCars, int tDNI, int totalRequests);
int readfile(cars& tCars);
void save(cars& tCars, int totalRequests);


int main()
{   
    cars Cars;
    int totalRequests = 0;

    totalRequests = readfile(Cars);
    totalRequests = menu(Cars, totalRequests);
    save(Cars, totalRequests);
    return 0;
}

int menu(cars& tCars, int totalRequests){

    int requesterDNI = 0;
    int choice;
    int i = 0;

    while (choice != 6)
    {
        cout << "Sistema de gestion de solicitudes" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Ingresar nueva solicitud." << endl;
        cout << "2. Editar solicitud." << endl;
        cout << "3. Eliminar solicitud." << endl;
        cout << "4. Listar solicitudes." << endl;
        cout << "5. Buscar solicitud" << endl;
        cout << "6. Cerrar el programa." << endl;
        cout << "--------------------------------" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
           
            while (tCars[i].isCharged == true)
            {
                i++;
            }
            addNewCar(tCars, totalRequests);
            break;

        case 2:

            cout << "Ingrese DNI del titular de la solicitud: ";
            cin >> requesterDNI;
            editCar(tCars, requesterDNI, totalRequests);

            break;
        case 3: 

            cout << "Ingrese DNI del titular de la solicitud a borrar: ";
            cin >> requesterDNI;
            deleteCar(tCars, requesterDNI, totalRequests);

            break;
        case 4:

            listCars(tCars, totalRequests);

            break;
        case 5:

            cout << "Ingrese DNI del titular de la solicitud: ";
            cin >> requesterDNI;
            searchCar(tCars, requesterDNI,totalRequests);

            break;
        case 6:

            cout << "Gracias por utilizar nuestro software";

            break;
        default:

            cout << "La opcion ingresada no es valida";

            break;
        }
    }
return totalRequests; 
}

car createNewCar(int tTicketID)
{
    car newCar;
    newCar.ticketID = tTicketID;
    newCar.isCharged = true;
    cout << "Ingrese Nombre del titular: ";
    cin >> newCar.name;
    cout << "Ingrese Apellido del titular: ";
    cin >> newCar.lastname;
    cout << "Ingrese DNI del titular: ";
    cin >> newCar.dni;

    return newCar;
}
void addNewCar(cars& tCars, int& totalRequests)
{
    if (totalRequests < MAXCARS)
    {
        tCars[totalRequests] = createNewCar(totalRequests);
        totalRequests++;
    }
    else
    {
        cout << "No se pueden agregar más autos. Límite alcanzado." << endl;
    }
}


car addCarFromFile(string tName, string tLastname, int tDNI, int tTicketID, bool tIsCharged){

    car newCar;
    newCar.name = tName;
    newCar.lastname = tLastname;
    newCar.dni = tDNI;
    newCar.ticketID = tTicketID;
    newCar.isCharged = tIsCharged;

return newCar;
}

void deleteCar(cars& tCars, int tDNI, int totalRequests){
    
    for (int i = 1; i < totalRequests; i++)
    {
        if (tDNI == tCars[i].dni)
        {
            for (int j = i; j < totalRequests; j++)
            {
                tCars[j].dni = tCars[j + 1].dni;
                tCars[j].name = tCars[j + 1].name;
                tCars[j].lastname = tCars[j + 1].lastname;
            
            }
            totalRequests--;
            break;
        }
    }

}

void editCar(cars& tCars, int tDNI, int totalRequests){

    for (int i = 1; i < totalRequests; i++)
    {
        if (tDNI == tCars[i].dni)
        {   
            cout << "\n Ingrese nuevo DNI: ";
            cin >> tCars[i].dni;
            cout << "\n Ingrese nuevo nombre: ";
            cin >> tCars[i].name;
            cout << "\n Ingrese nuevo apellido";
            cin >> tCars[i].lastname;
        }
    }
}

void listCars(cars& tCars, int totalRequests)
{
    
    cout << "Solicitudes ingresadas: " << endl;
    for (int i = 0; i < totalRequests; i++)
    {
        cout << "Nombre: " << tCars[i].name << endl;
        cout << "Apellido: " << tCars[i].lastname << endl;
        cout << "DNI: " << tCars[i].dni << endl;
        cout << "Nro de solicitud: " << tCars[i].ticketID << endl;
    }
}

void searchCar(cars& tCars, int tDNI, int totalRequests){
    for (int i = 0; i < totalRequests; i++)
    {
        if (tDNI == tCars[i].dni)
        {   
        cout << "Nombre: " << tCars[i].name << endl;
        cout << "Apellido: " << tCars[i].lastname << endl;
        cout << "Nro de solicitud: " << tCars[i].ticketID << endl; 
        }
    }
}

int readfile(cars& tCars){
    
    ifstream file("cars.csv");
    if (file.is_open()) {
        string name;
        string lastname;
        int dni;
        int ticketID;
        bool isCharged;
        int countRequests = 0;

        while (countRequests < MAXCARS && file >> ticketID >> name >> lastname >> dni >> isCharged) {
            tCars[countRequests] = addCarFromFile(name, lastname, dni, ticketID, isCharged);
            countRequests++;
        }

        file.close();
        return countRequests;
    } else {
        cout << "No se pudo abrir el archivo cars.csv" << endl;
        return 0;
    }
}
void save(cars& tCars, int totalRequests){
    
    ofstream file("cars.csv");
    if (file.is_open()) {
        for (int i = 0; i < totalRequests; i++) {
            file << tCars[i].ticketID << "," << tCars[i].name << "," << tCars[i].lastname << "," << tCars[i].dni << "," << tCars[i].isCharged << endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo cars.csv" << endl;
    }
}