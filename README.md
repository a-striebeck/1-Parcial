### README - Examen de Gestión de Clientes

Este código es un programa de gestión de clientes desarrollado en C++, diseñado para realizar operaciones básicas como agregar, editar, eliminar, listar y buscar clientes en un archivo de texto llamado `clients.txt`. El programa proporciona un menú interactivo que permite al usuario realizar estas operaciones de manera intuitiva.

#### Funcionalidades Principales:

1. **Agregar Cliente:**
   - Permite al usuario ingresar los datos de un nuevo cliente, como nombre, apellido y DNI.
   - Asigna un número de cliente único basado en un identificador incremental.

2. **Editar Cliente:**
   - Permite al usuario modificar los datos de un cliente existente, identificado por su DNI.
   - Muestra los datos del cliente antes de la edición y solicita los nuevos datos al usuario.

3. **Eliminar Cliente:**
   - Permite al usuario eliminar un cliente existente, identificado por su DNI.
   - Solicita confirmación antes de proceder con la eliminación del cliente.

4. **Listar Clientes:**
   - Muestra una lista de todos los clientes registrados en el sistema, incluyendo su número de cliente, nombre, apellido y DNI.

5. **Buscar Cliente:**
   - Permite al usuario buscar un cliente por su número de DNI.
   - Muestra los datos del cliente si se encuentra en la base de datos.

6. **Guardar y Cargar Datos:**
   - Los datos de los clientes se guardan en un archivo de texto llamado `clients.txt`.
   - Al iniciar el programa, carga automáticamente los datos de este archivo para restaurar el estado anterior del sistema.

#### Estructura del Código:

- El código está organizado en funciones que realizan tareas específicas, como agregar clientes, editar clientes, etc.
- Se utiliza un arreglo de estructuras (`clients`) para almacenar los datos de los clientes.
- Se implementa la lectura y escritura de datos desde y hacia el archivo `clients.txt`.
- Se incluye un menú interactivo que permite al usuario seleccionar las operaciones que desea realizar.

#### Uso del Programa:

- Al ejecutar el programa, se mostrará un menú con las opciones disponibles.
- El usuario puede seleccionar una opción ingresando el número correspondiente.
- El programa solicitará los datos necesarios para realizar la operación seleccionada.
- Los datos de los clientes se guardarán automáticamente al salir del programa.

Este README proporciona una descripción general del programa y su funcionalidad. Para obtener más detalles sobre la implementación específica de cada función, se recomienda revisar el código fuente proporcionado.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

### README - Customer Management Exam

This code is a customer management program developed in C++, designed to perform basic operations such as adding, editing, deleting, listing, and searching customers in a text file named `clients.txt`. The program provides an interactive menu that allows the user to perform these operations intuitively.

#### Main Features:

1. **Add Customer:**
   - Allows the user to enter the data of a new customer, such as name, last name, and ID.
   - Assigns a unique customer number based on an incremental identifier.

2. **Edit Customer:**
   - Allows the user to modify the data of an existing customer, identified by their ID.
   - Displays the customer's data before editing and prompts the user for the new data.

3. **Delete Customer:**
   - Allows the user to delete an existing customer, identified by their ID.
   - Requests confirmation before proceeding with the deletion of the customer.

4. **List Customers:**
   - Displays a list of all customers registered in the system, including their customer number, name, last name, and ID.

5. **Search Customer:**
   - Allows the user to search for a customer by their ID.
   - Displays the customer's data if found in the database.

6. **Save and Load Data:**
   - Customer data is saved in a text file named `clients.txt`.
   - Upon starting the program, it automatically loads the data from this file to restore the previous state of the system.

#### Code Structure:

- The code is organized into functions that perform specific tasks, such as adding customers, editing customers, etc.
- An array of structures (`clients`) is used to store customer data.
- Data reading and writing from and to the `clients.txt` file are implemented.
- An interactive menu is included that allows the user to select the operations they want to perform.

#### Program Usage:

- Upon running the program, a menu will be displayed with the available options.
- The user can select an option by entering the corresponding number.
- The program will prompt for the necessary data to perform the selected operation.
- Customer data is automatically saved when exiting the program.

This README provides a general description of the program and its functionality. For more details on the specific implementation of each function, it is recommended to review the provided source code.
