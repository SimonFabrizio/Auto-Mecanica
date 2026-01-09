# 🚗 AutoMecanica24 - Sistema de Gestión de Turnos

Sistema de gestión de colas para un taller mecánico desarrollado en **Lenguaje C**. El proyecto implementa estructuras de datos dinámicas para administrar el flujo de vehículos y la facturación.

## 📋 Descripción Técnica
El software simula la operación de un taller mecánico utilizando una arquitectura basada en **Colas (Queues)** para la recepción de vehículos (FIFO - First In, First Out) y **Listas Enlazadas** para el almacenamiento del historial de trabajos realizados.

El objetivo del proyecto es demostrar el manejo eficiente de la memoria y la implementación manual de estructuras de datos sin depender de librerías de alto nivel.

## ⚙️ Características y Funcionalidades
* **Gestión de Memoria Dinámica:** Uso de `malloc` y `free` para la asignación de nodos en tiempo de ejecución.
* **Estructura de Cola (Queue):** Implementación de punteros `inicio` y `fin` para el encolado eficiente de vehículos pendientes.
* **Persistencia en Lista Enlazada:** Los vehículos atendidos se mueven de la cola a una lista lineal para su registro.
* **Algoritmos Recursivos:** La función de cálculo de recaudación (`recaudado`) utiliza recursividad para recorrer la lista.
* **Sistema de Menú:** Interfaz de consola interactiva para el usuario.

## 🛠️ Tecnologías
* **Lenguaje:** C (Standard C99)
* **Compilador:** Compatible con GCC / MinGW.
* **Librerías:** `stdio.h`, `stdlib.h`, `string.h`.

## 💻 Estructura del Código
El sistema se basa en las siguientes estructuras clave:
```c
// Estructura para el manejo de la Cola (Pendientes)
struct nodo {
    struct turno dato;
    struct nodo *sig;
};

// Estructura para la Lista (Historial)
struct lista {
    struct atendido dato;
    struct lista *sig;
};
