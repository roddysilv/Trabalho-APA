#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void imprime(int vet[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", vet[i]);
}

void randomize ( int vet[], int n )
{
    srand ( time(NULL));
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&vet[i], &vet[j]);
    }
}

void troca(int v[],int tam, float t)
{
    srand (time(NULL));
    for (int i = 0; i <t; i++)
    {
        swap(&v[rand() % (tam)], &v[rand() % (tam)]);
    }
}

double media(double v[],int M)
{
    double m =0;
    for(int i=0; i<M; i++)
    {
        m=m+v[i];
    }
    return m/M;
}
