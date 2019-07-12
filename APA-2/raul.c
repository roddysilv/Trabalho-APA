#include "raul.h"

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
