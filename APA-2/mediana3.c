#include "mediana3.h"

void MedianaDe3(int lista[],int tam)
{
    quicksortMedianaDeTres(lista, 0, tam);
}

void quicksortMedianaDeTres(int lista[],int inicio,int fim)
{
    if(inicio < fim)
    {
        int q = particaoMediana3(lista, inicio, fim) ;
        quicksortMedianaDeTres(lista, inicio, q - 1);
        quicksortMedianaDeTres(lista, q + 1, fim) ;
    }
}

int particaoMediana3(int lista[],int inicio,int fim)
{
    int meio = ( (inicio + fim) / 2);
    int a = lista[inicio];
    int b = lista[meio];
    int c = lista[fim];
    int medianaIndice;
    if(a < b)
    {
        if(b < c)
        {
            medianaIndice = meio;
        }
        else
        {
            if(a < c)
            {
                medianaIndice = fim;
            }
            else
            {
                medianaIndice = inicio;
            }
        }
    }
    else
    {
        if(c < b)
        {
            medianaIndice = meio;
        }
        else
        {
            if(c < a)
            {
                medianaIndice = fim;
            }
            else
            {
                medianaIndice = inicio;
            }
        }
    }
    swap(&lista[medianaIndice],&lista[fim]);

//#PARTIÇÃO DE CORMEN
    int pivo = lista[fim];
    int i = inicio - 1;
    for (int j =inicio; j<fim; j++)
    {
        if(lista[j] <= pivo)
        {
            i = i + 1;
            swap(&lista[i],&lista[j]);
        }
    }
    swap(&lista[i + 1],&lista[fim]);
    return i + 1;
}
