#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "hoare.h"
#include "lomuto.h"
#include "iterativo.h"
#include "raul.h"
#include "mediana3.h"
#include "util.h"

#define N 10000  ///500000 MAX
#define M 100

int main()
{


    double hoare[M];
    double lomuto[M];
    double med3[M];
    double raul[M];
    double ite[M];
    double teste[M];

    struct timeval start, stop,t1,t2;

    int vet[N];
    for(int i = 0; i<N; i++)
    {
        vet[i]=i;
    }
    int n = sizeof(vet)/sizeof(vet[0]);
    int cont =0;

    /// TUDO EMBARALHADO
    while(cont <M)
    {
        randomize (vet, n);         // EMBARALHA TUDO

        gettimeofday(&start,NULL);
        Hoare(vet,n-1);
        gettimeofday(&stop,NULL);

        hoare[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        randomize (vet, n);         // EMBARALHA TUDO

        gettimeofday(&start,NULL);
        Lomuto(vet,n-1);
        gettimeofday(&stop,NULL);

        lomuto[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        randomize (vet, n);         // EMBARALHA TUDO

        gettimeofday(&start,NULL);
        MedianaDe3(vet,n-1);
        gettimeofday(&stop,NULL);

        med3[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        randomize (vet, n);         // EMBARALHA TUDO

        gettimeofday(&start,NULL);
        quickSortIterative(vet,0,n-1);
        gettimeofday(&stop,NULL);

        ite[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        cont++;

    }

    printf("Vetor Totalmente Embaralhado: \n");
    printf("Hoare: %f s\n",media(hoare,M));
    printf("Lomuto: %f s\n",media(lomuto,M));
    printf("Med 3: %f s\n",media(med3,M));
    printf("iterativo: %f s\n",media(ite,M));



    ///1 TROCA
    cont=0;
    srand (time(NULL));
    int i,j;
    while(cont<M)
    {
        i = rand() % (n+1);
        j = rand() % (n+1);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        Hoare(vet,n-1);
        gettimeofday(&stop,NULL);

        hoare[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        Lomuto(vet,n-1);
        gettimeofday(&stop,NULL);

        lomuto[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        MedianaDe3(vet,n-1);
        gettimeofday(&stop,NULL);

        med3[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        quicksortRaul(vet,0,n-1);
        gettimeofday(&stop,NULL);

        raul[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        quickSortIterative(vet,0,n-1);
        gettimeofday(&stop,NULL);

        ite[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        cont++;
    }

    printf("\n");
    printf("UMA TROCA APENAS: \n");
    printf("Hoare: %f s\n",media(hoare,M));
    printf("Lomuto: %f s\n",media(lomuto,M));
    printf("Med 3: %f s\n",media(med3,M));
    printf("Raul: %f s\n",media(raul,M));
    printf("iterativo: %f s\n",media(ite,M));

    ///N TROCAS
    cont=0;
    int t=5;
    while(cont<M)
    {
        troca(vet,n,t);

        gettimeofday(&start,NULL);
        Hoare(vet,n-1);
        gettimeofday(&stop,NULL);

        hoare[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);
/*
        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        Lomuto(vet,n-1);
        gettimeofday(&stop,NULL);

        lomuto[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        MedianaDe3(vet,n-1);
        gettimeofday(&stop,NULL);

        med3[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        quicksortRaul(vet,0,n-1);
        gettimeofday(&stop,NULL);

        raul[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

        swap(&vet[i],&vet[j]);

        gettimeofday(&start,NULL);
        quickSortIterative(vet,0,n-1);
        gettimeofday(&stop,NULL);

        ite[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);
*/
        cont++;
    }

    printf("\n");
    printf("N TROCAS: \n");
    printf("Hoare: %f s\n",media(hoare,M));
    printf("Lomuto: %f s\n",media(lomuto,M));
    printf("Med 3: %f s\n",media(med3,M));
    printf("Raul: %f s\n",media(raul,M));
    printf("iterativo: %f s\n",media(ite,M));

    return 0;
}
