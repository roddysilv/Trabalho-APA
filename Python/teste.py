import random as r
import numpy as np
import time as t

        
def achaPivo(n1,n2,lista):
    esq=n1
    di=n2
    pos=esq+1
    pto=0
    while True :
        if(pos>di):
            break
        elif(lista[pos]>=lista[pos-1]):
            pos=pos+1
        else:
            pto=pos
            break
    return pto
            
def particao(n1,n2,pivo,lista):
    esq=n1
    di=n2
    
    while True:
        if(lista[esq]>pivo and lista[di]>pivo):
            break
        print("1")
        print(lista[esq],lista[di],pivo)
        lista=troca(lista,esq,di)
        print("2")
        print(lista[esq],pivo)
        while(lista[esq]<=pivo):
            print('3')
            print(lista[esq],pivo)
            esq=esq+1
            while(lista[di]>pivo):
                di=di-1
        if(esq>di):
            break
    return di

def quick(lista,n1,n2):
    esq=n1
    di=n2
    pto=achaPivo(esq,di,lista)
    if(pto!=0):
        p=particao(esq,di,pto,lista)
        quick(lista,esq,p)
        quick(lista,p+1,di)
    
def iniciaquick(lista):
    quick(lista,0,len(lista)-1)

def troca(lista, a,b):
    aux=lista[a]
    lista[a]=lista[b]
    lista[b]=aux
    return lista

# CRIA UMA LISTA DE TAMANHO K ORDENADA
def lista(k):
    l=[]
    for i in range(0,k):
        l.append(i)
    return l

# EMBARALHA A LISTA DE ACORDO COM O PARÂMETRO NÍVEL:
#   1 - UMA TROCA APENAS
#   2 - K TROCAS - PADÃO 5 TROCAS
#   3 - TOTALMENTE EMBARALHADO
def embaralhar(lista, nivel, k=5):
    if(nivel==1):
        a=r.randint(0,np.size(lista)-1)
        b=r.randint(0,np.size(lista)-1)
        if(a==b): 
            if(b==len(lista)-1):
                b=b-1
            else:
                b=b+1
        return troca(lista,a,b)
    elif(nivel==2):
        for i in range(k):
            a=r.randint(0,np.size(lista)-1)
            b=r.randint(0,np.size(lista)-1)
            lista=troca(lista,a,b)
        return lista
    elif(nivel==3):
        r.shuffle(lista)
        return lista
    else:
        print("Nível de Embaralhamento Inválido")
        
l=lista(10)
embaralhar(l,3)
#print(l)
inicio=t.time()
iniciaquick(l)
fim=t.time()
#print(l)
print(fim-inicio)
