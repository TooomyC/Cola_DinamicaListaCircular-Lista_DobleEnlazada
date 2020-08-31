#ifndef COLADINDOBLE_H_INCLUDED
#define COLADINDOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINIMO(X, Y) ((X) <= (Y) ? (X) : (Y))

#define FALSO 0
#define VERDADERO 1

typedef struct sNodo
{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;

} tNodo;

typedef tNodo *tCola;

void crearCola(tCola *p);
int encolar(tCola *p, const void* d, unsigned cantBytes);
int colaLlena(const tCola *p, unsigned cantBytes);
int verPrimeroCola(const tCola *p, void* d, unsigned cantBytes);
void vaciarCola(tCola *p);
int desencolar(tCola *p, void* d, unsigned cantBytes);
///int colaVacia(const Cola* cola); ///FALTA ESTE?

#endif // COLADINDOBLE_H_INCLUDED
