#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define N 100000  ///500000 MAX
#define M 100

///========================================

/* This function is same in both iterative and recursive*/
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSortIterative(int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

///======================================

/// ESQUEMA DO PROF

int achaPivo(int n1,int n2,int lista[])
{
    int esq=n1;
    int dir=n2;
    int pos=esq+1;
    int pto=0;
    while(1>0)
    {
        if(pos>dir)
        {
            break;
        }
        else if(lista[pos]>=lista[pos-1])
        {
            pos=pos+1;
        }
        else
        {
            pto=pos;
            break;
        }
    }
    return pto;
}

int particaoRaul(int n1,int n2,int pivo,int lista[])
{
    int esq=n1;
    int dir=n2;
    while(esq<=dir)
    {

        swap(&lista[esq],&lista[dir]);
        while(lista[esq]<=pivo)
        {
            esq=esq+1;
            while(lista[dir]>pivo)
            {
                dir=dir-1;
            }
        }
        if(lista[esq]>pivo && lista[dir]>pivo)
        {
            //esq=esq+1;
            dir=dir-1;
        }

    }
    return dir;
}

void quicksortRaul(int lista[],int n1,int n2)
{
    int esq=n1;
    int dir=n2;
    int pto=achaPivo(esq,dir,lista);
    if(pto!=0)
    {
        int p=particaoRaul(esq,dir,pto,lista);
        quicksortRaul(lista,esq,p);
        quicksortRaul(lista,p+1,dir);
    }
}

void iniciaquick(int lista[],int tam)
{
    quicksortRaul(lista,0,tam);
}

///----------------------------------------------------------

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
    srand ( time(NULL));
    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

void troca(int v[],int tam, float t)
{
    srand (time(NULL));
    float aux = tam*(t/100);
    int aux1=aux;
    int a,b;
    for (int i = 0; i <aux; i++)
    {
        a= rand() % (tam);
        b= rand() % (tam);
        swap(&v[a], &v[b]);
    }
   }

double media(double v[])
{
    double m =0;
    for(int i=0; i<M; i++)
    {
        m=m+v[i];
    }
    return m/M;
}


int main()
{

    struct timeval start, stop,t1,t2;

    int arr[N];
    for(int i = 0; i<N; i++)
    {
        arr[i]=i;
    }
    int n = sizeof(arr)/sizeof(arr[0]);


    double hoare[M];
    double lomuto[M];
    double med3[M];
    double raul[M];
    double ite[M];
    double teste[M];

    int in,cont;

    printf("Menu \n 1 - Uma Troca \n 2 - Parcialmente Embaralhado \n 3 - Vetor Totalmente Embaralhado \n 0 - Sair\n\n");


    printf("Opcao: ");
    scanf("%d",&in);
    while(in!=0)
    {
        switch(in)
        {
        case 1:
            cont=0;
            srand ( time(NULL) );
            int i,j;
            while(cont<M)
            {
                i = rand() % (n+1);
                j = rand() % (n+1);


                swap(&arr[i],&arr[j]);

                gettimeofday(&start,NULL);
                Hoare(arr,n-1);
                gettimeofday(&stop,NULL);

                hoare[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                swap(&arr[i],&arr[j]);

                gettimeofday(&start,NULL);
                Lomuto(arr,n-1);
                gettimeofday(&stop,NULL);

                lomuto[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                swap(&arr[i],&arr[j]);

                gettimeofday(&start,NULL);
                MedianaDe3(arr,n-1);
                gettimeofday(&stop,NULL);

                med3[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                swap(&arr[i],&arr[j]);

                gettimeofday(&start,NULL);
                quicksortRaul(arr,0,n-1);
                gettimeofday(&stop,NULL);

                raul[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                swap(&arr[i],&arr[j]);

                gettimeofday(&start,NULL);
                quickSortIterative(arr,0,n-1);
                gettimeofday(&stop,NULL);

                ite[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                cont++;
            }

            printf("\n");

            printf("Hoare: %f s\n",media(hoare));
            printf("Lomuto: %f s\n",media(lomuto));
            printf("Med 3: %f s\n",media(med3));
            printf("Raul: %f s\n",media(raul));
            printf("iterativo: %f s\n",media(ite));
            break;
        case 2:
            cont=0;
            int e;
            printf("Entre com a Porcentagem de Embaralhamento: ");
            scanf("%d",&e);
            printf("Vetor %d%% embaralhado \n",e);
            while(cont <M)
            {
                troca(arr,n-1,e);

                gettimeofday(&start,NULL);
                Hoare(arr,n-1);
                gettimeofday(&stop,NULL);

                hoare[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                troca(arr,n-1,e);

                gettimeofday(&start,NULL);
                Lomuto(arr,n-1);
                gettimeofday(&stop,NULL);

                lomuto[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                troca(arr,n-1,e);

                gettimeofday(&start,NULL);
                MedianaDe3(arr,n-1);
                gettimeofday(&stop,NULL);

                med3[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                troca(arr,n-1,e);

                /*gettimeofday(&start,NULL);
                quicksortRaul(arr,0,n-1);
                gettimeofday(&stop,NULL);

                raul[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);
*/
                troca(arr,n-1,e);

                gettimeofday(&start,NULL);
                quickSortIterative(arr,0,n-1);
                gettimeofday(&stop,NULL);

                ite[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                cont++;

            }

            printf("\n");

            printf("Hoare: %f s\n",media(hoare));
            printf("Lomuto: %f s\n",media(lomuto));
            printf("Med 3: %f s\n",media(med3));
            printf("Raul: %f s\n",media(raul));
            printf("iterativo: %f s\n",media(ite));
            break;
        case 3:
            cont=0;
            while(cont <M)
            {
                randomize (arr, n);         // EMBARALHA TUDO

                gettimeofday(&start,NULL);
                Hoare(arr,n-1);
                gettimeofday(&stop,NULL);

                hoare[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                randomize (arr, n);         // EMBARALHA TUDO

                gettimeofday(&start,NULL);
                Lomuto(arr,n-1);
                gettimeofday(&stop,NULL);

                lomuto[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                randomize (arr, n);         // EMBARALHA TUDO

                gettimeofday(&start,NULL);
                MedianaDe3(arr,n-1);
                gettimeofday(&stop,NULL);

                med3[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                randomize (arr, n);         // EMBARALHA TUDO

                /*gettimeofday(&start,NULL);
                quicksortRaul(arr,0,n-1);
                gettimeofday(&stop,NULL);

                raul[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);
*/
                randomize (arr, n);         // EMBARALHA TUDO

                gettimeofday(&start,NULL);
                quickSortIterative(arr,0,n-1);
                gettimeofday(&stop,NULL);

                ite[cont]=(double)(stop.tv_usec - start.tv_usec)/1000000+(double)(stop.tv_sec-start.tv_sec);

                cont++;

            }

            printf("\n");

            printf("Hoare: %f s\n",media(hoare));
            printf("Lomuto: %f s\n",media(lomuto));
            printf("Med 3: %f s\n",media(med3));
            printf("Raul: %f s\n",media(raul));
            printf("iterativo: %f s\n",media(ite));
            break;
        default:
            printf("COMANDO INVALIDO!\n\n");
            break;

        }

        printf("\n");
        printf("Opcao: ");
        scanf("%d",&in);
    }

    return 0;
}
