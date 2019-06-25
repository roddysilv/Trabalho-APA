#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000


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

///-----------------------------------------------------------------

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

///-----------------------------------------------------------------------------------------------------------

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
///-----------------------------------------------------------------------------------------------------------
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int particao (int arr[], int inicio, int fim)
{
    int pivo = arr[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim- 1; j++)
    {
        if (arr[j] <= pivo)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[fim]);
    return (i + 1);
}

void quickSort(int arr[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int q = particao(arr, inicio, fim);
        quickSort(arr, inicio, q - 1);
        quickSort(arr, q + 1, fim);
    }
}

///-------------------------------------------------------------------------------------------------------

void imprime(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
}

void randomize ( int arr[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );

    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);

        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}


int main()
{

    time_t t1;
    time_t t2;

    clock_t in,fi;
    in=clock();

    int arr[N];
    for(int i = 0; i<N; i++)
    {
        arr[i]=i;
    }
    int n = sizeof(arr)/sizeof(arr[0]);

    //swap(&arr[5],&arr[77]);  //TROCA APENAS 2 ELEMENTOS DA LISTA
    randomize (arr, n);         // EMBARALHA TUDO

    //imprime(arr, n);

    t1= time(NULL);


    Hoare(arr,n-1);
    randomize (arr, n);
    Lomuto(arr,n-1);
    randomize (arr, n);
    MedianaDe3(arr,n-1);

    printf("Sorted array: ");
    printf("\n");
    imprime(arr, n);

    fi=clock();
    t2= time(NULL);

    double time_taken = (fi - in) / (CLOCKS_PER_SEC);

    float tempo = difftime(t2,t1);


    printf("\n");
    printf("Tempo: %f s\n",time_taken);
    return 0;
}
