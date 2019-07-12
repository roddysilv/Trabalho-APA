#include "lomuto.h"

void Lomuto(int lista[],int tam)
{
    quicksortLomuto(lista,0,tam);
}
void quicksortLomuto(int lista[],int inicio,int fim)
{
    if (inicio < fim)
    {
        int q = particaoLomuto(lista, inicio, fim);
        quicksortLomuto(lista, inicio, q - 1);
        quicksortLomuto(lista, q + 1, fim);
    }
}

int particaoLomuto(int lista[],int inicio,int fim)
{
    int pivo = lista[fim];
    int i = inicio;
    for (int j=inicio; j<fim; j++)
    {
        if (lista[j] < pivo)
        {
            swap(&lista[i],&lista[j]);
            i = i + 1;
        }
    }
    swap(&lista[i],&lista[fim]);
    return i    ;
}
