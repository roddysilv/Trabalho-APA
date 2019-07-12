#include "hoare.h"

void Hoare(int lista[],int tam)
{
    quicksortHoare(lista,0,tam);
}

void quicksortHoare(int lista[],int inicio,int fim)
{
    if (inicio < fim)
    {
        int q = particaoHoare(lista, inicio, fim);
        quicksortHoare(lista, inicio, q);
        quicksortHoare(lista, q + 1, fim);
    }
}

int particaoHoare(int lista[],int inicio,int fim)
{
    int pivo = lista[inicio];
    int i=inicio-1;
    int j=fim+1;
    while (1>0)
    {
        i = i + 1;
        while (lista[i] < pivo)
        {
            i = i + 1;
        }
        j=j-1;
        while (lista[j] > pivo)
        {
            j=j-1;
        }
        if (i >= j)
        {
            return j;
        }
        swap(&lista[i],&lista[j]);
    }
}



