#include "colaDinDoble.h"

void crearCola(tCola *p)
{
    *p = NULL;
}

int colaLlena(const tCola *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux = NULL || info == NULL; ///WARNING: ASIGNACION TIPO VARIABLE
}

int encolar(tCola *p, const void* d, unsigned cantBytes)
{
    tNodo *nue;

    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL || (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return FALSO;
    }

    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;

    if(*p == NULL)
        nue->sig = nue;
    else
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
    }

    *p = nue;

    return VERDADERO;
}

int verPrimeroCola(const tCola *p, void* d, unsigned cantBytes)
{
    if(*p == NULL)
        return FALSO;

    memcpy(d, (*p)->sig->info, MINIMO(cantBytes, (*p)->sig->tamInfo));
    return VERDADERO;
}

void vaciarCola(tCola *p)
{
    while(*p)
    {
        tNodo *aux = (*p)->sig;

        if(*p == aux)
            *p = NULL;
        else
            (*p)->sig = aux->sig;

        free(aux->info);
        free(aux);
    }
}

int desencolar(tCola *p, void* d, unsigned cantBytes)
{
    tNodo *aux;

    if(*p == NULL)
        return FALSO;
    aux = (*p)->sig;
    memcpy(d, aux->info, MINIMO(cantBytes, aux->tamInfo));

    if(aux == *p)
        *p = NULL;
    else
        (*p)->sig = aux->sig;

    free(aux->info);
    free(aux);

    return VERDADERO;
}

