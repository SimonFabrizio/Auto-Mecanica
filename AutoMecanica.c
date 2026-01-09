#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct turno
{
    int patente;
    int tipo;
    int dni;
    char nombre[50];
    char apellido[50];
};

struct nodo
{
    struct turno dato;
    struct nodo *sig;
};

struct cola
{
    struct nodo *pini;
    struct nodo *pfin;
};

void iniciar_cola(struct cola *c)
{
    c->pini = NULL;
    c->pfin = NULL;
}

void encolar(struct cola *c)
{
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    printf("Ingrese la patente: ");
    scanf("%d", &nuevo->dato.patente);
    printf("Ingrse tipo de servicio (1.Manteniemto General || 2.Cambio de Aceite || 3.Reparacion de Aceite):");
    scanf("%d", &nuevo->dato.tipo);
    printf("Ingrese el DNI: ");
    scanf("%d", &nuevo->dato.dni);
    printf("Ingrese el nombre del cliente:");
    scanf("%s", nuevo->dato.nombre);
    printf("Ingrese el apellido del cliente:");
    scanf("%s", nuevo->dato.apellido);

    nuevo->sig = NULL;

    if (c->pini == NULL)
    {
        c->pini = nuevo;
    }
    else
    {
        c->pfin->sig = nuevo;
    }
    c->pfin = nuevo;
}

void desencolar(struct cola *c, struct turno *t)
{
    if (c->pini == NULL)
    {
        printf("No hay turnos pendientes\n");
        return;
    }
    struct nodo *aux = c->pini;
    *t = aux->dato;
    c->pini = aux->sig;
    if (c->pini == NULL)
    {
        c->pfin = NULL;
    }
    free(aux);
}

struct atendido
{
    int patente;
    int dni;
    char nombre[50];
    char apellido[50];
    int tipo;
    float importe;
};

struct lista
{
    struct atendido dato;
    struct lista *sig;
};

void turnos_atendidos(struct lista **l, struct atendido a)
{
    struct lista *nuevo = malloc(sizeof(struct lista));
    nuevo->dato = a;
    nuevo->sig = *l;
    *l = nuevo;
}

void recaudado(struct lista *l, int tipo, float *precio)
{
    if (l != NULL)
    {
        if (l->dato.tipo == tipo)
        {
            *precio += l->dato.importe;
        }
        recaudado(l->sig, tipo, precio);
    }
}

int main()
{
    struct cola c;
    struct turno t;
    struct atendido a;
    struct lista *l = NULL;

    float totalgeneral, totalaciete, totalmecanica;
    float precio[3] = {1000, 5000, 2000};
    int cantidad_turnos = 0;
    int opcion = 0;

    iniciar_cola(&c);
    while (opcion != 5)
    {
        printf("\n----Menu AutoMecaninca24----\n");
        printf("1.Cargar nuevo turno\n");
        printf("2.Atender turno\n");
        printf("3.Mostrar cantidad de turnos pendientes\n");
        printf("4.Mostrar lo recaudado\n");
        printf("5.Salir.\n");
        printf("Seleccione una opcion:");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            encolar(&c);
            cantidad_turnos++;
            break;
        case 2:
            desencolar(&c, &t);
            cantidad_turnos--;

            a.patente = t.patente;
            a.dni = t.dni;
            strcpy(a.nombre, t.nombre);
            strcpy(a.apellido, t.apellido);
            a.tipo = t.tipo;
            a.importe = precio[t.tipo - 1];
            turnos_atendidos(&l, a);
            break;

        case 3:
            printf("\nCantidad de turnos pendiente: %d\n", cantidad_turnos);
            break;

        case 4:
            totalgeneral = 0;
            totalaciete = 0;
            totalmecanica = 0;

            recaudado(l, 1, &totalgeneral);
            recaudado(l, 2, &totalaciete);
            recaudado(l, 3, &totalmecanica);

            printf("El total recaudado por mantenimiento general: %.2f\n", totalgeneral);
            printf("El total recaudado por cambio de aciete: %.2f\n", totalaciete);
            printf("El total recaudado por reparacion mecanica: %.2f\n", totalmecanica);

            break;

        case 5:
            printf("Saliendo...");
            break;

        default:
            printf("\nOpcion invalida\n");
            break;
        }
    }
}