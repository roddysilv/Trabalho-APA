#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int* a, int* b);

void imprime(int vet[], int size);

void randomize ( int vet[], int n );

void troca(int v[],int tam, float t);

double media(double v[],int M);


#endif // UTIL_H_INCLUDED
