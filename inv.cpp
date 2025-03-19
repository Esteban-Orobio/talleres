#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100 // Maximo numero de productos en el inventario
#define LONG_NOMBRE 50    // Longitud maxima del nombre del producto

// Estructura para representar un producto
typedef struct {
    int codigo;
    char nombre[LONG_NOMBRE];
    int cantidad;
    int precio;
} Producto;

Producto inventario[MAX_PRODUCTOS]; // Arreglo para almacenar los productos
int totalProductos = 0;             // Contador de productos registrados

// Funcion para mostrar un titulo centrado
void mostrarTitulo(const char *titulo) {
    printf("\n========================================\n");
    printf("          %s\n", titulo);
    printf("========================================\n");
}

// Funcion para mostrar un mensaje de error
void mostrarError(const char *mensaje) {
    printf("\n[Error] %s\n", mensaje);
}

// Funcion para mostrar un mensaje de exito
void mostrarExito(const char *mensaje) {
    printf("\n[Exito] %s\n", mensaje);
}

// Funcion para registrar un nuevo producto
void registrarProducto() {
    if (totalProductos >= MAX_PRODUCTOS) {
        mostrarError("No hay espacio suficiente en el inventario.");
        return;
    }

    Producto nuevoProducto;

    mostrarTitulo("Registrar Producto");
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &nuevoProducto.codigo);

    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nuevoProducto.nombre); // Leer una cadena con espacios

    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &nuevoProducto.cantidad);

    printf("Ingrese el precio por unidad del producto: ");
    scanf("%d", &nuevoProducto.precio);

    inventario[totalProductos] = nuevoProducto;
    totalProductos++;

    mostrarExito("Producto registrado con exito.");
}

// Funcion para mostrar todos los productos
void mostrarProductos() {
    if (totalProductos == 0) {
        mostrarError("No hay productos en el inventario.");
        return;
    }

    mostrarTitulo("Inventario de Productos");
    for (int i = 0; i < totalProductos; i++) {
        printf("Codigo: %d\n", inventario[i].codigo);
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Cantidad: %d\n", inventario[i].cantidad);
        printf("Precio por unidad: %d\n", inventario[i].precio);
        printf("Costo total por producto: %d\n", inventario[i].cantidad * inventario[i].precio);
        printf("-----------------------------\n");
    }
}

// Funcion para actualizar la cantidad tras una compra
void actualizarCantidad() {
    int codigo, cantidadVendida;

    mostrarTitulo("Actualizar Cantidad");
    printf("Ingrese el codigo del producto vendido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            printf("Ingrese la cantidad vendida: ");
            scanf("%d", &cantidadVendida);

            if (cantidadVendida > inventario[i].cantidad) {
                mostrarError("No hay suficiente stock para esta venta.");
            } else {
                inventario[i].cantidad -= cantidadVendida;
                mostrarExito("Cantidad actualizada con exito.");
            }
            return;
        }
    }

    mostrarError("Producto no encontrado.");
}

// Funcion para calcular el costo total del inventario
void calcularCostoTotal() {
    int costoTotal = 0;

    for (int i = 0; i < totalProductos; i++) {
        costoTotal += inventario[i].cantidad * inventario[i].precio;
    }

    mostrarTitulo("Costo Total del Inventario");
    printf("El costo total del inventario es: %d\n", costoTotal);
}

// Funcion para eliminar un producto del inventario
void eliminarProducto() {
    int codigo;

    mostrarTitulo("Eliminar Producto");
    printf("Ingrese el codigo del producto a eliminar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].codigo == codigo) {
            if (inventario[i].cantidad != 0) {
                mostrarError("No se puede eliminar el producto porque aun tiene stock.");
            } else {
                // Mover los productos restantes una posicion hacia atras
                for (int j = i; j < totalProductos - 1; j++) {
                    inventario[j] = inventario[j + 1];
                }
                totalProductos--;
                mostrarExito("Producto eliminado con exito.");
            }
            return;
        }
    }

    mostrarError("Producto no encontrado.");
}

// Menu principal
int main() {
    int opcion;

    do {
        mostrarTitulo("Menu de Gestion de Inventario");
        printf("1. Registrar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Actualizar cantidad tras compra\n");
        printf("4. Calcular costo total del inventario\n");
        printf("5. Eliminar producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                actualizarCantidad();
                break;
            case 4:
                calcularCostoTotal();
                break;
            case 5:
                eliminarProducto();
                break;
            case 6:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                mostrarError("Opcion no valida. Intente de nuevo.");
        }
    } while (opcion != 6);

    return 0;
}