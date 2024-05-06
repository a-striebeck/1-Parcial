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
