import numpy as np
import random as r
import time as t
import sys
#import matplotlib.pyplot as plt

sys.setrecursionlimit(10000)
#print(sys.getrecursionlimit())
##############################################################################

#PARTIÇÃO ESQUEMA MEDIANA DE 3 COM PARTIÇÃO DE CORMAN

def MedianaDe3(lista):
    quicksortMedianaDeTres(lista, 0, len(lista)-1)

def quicksortMedianaDeTres(lista, inicio, fim):
    if(inicio < fim):
        q = particaoMediana3(lista, inicio, fim) 
        quicksortMedianaDeTres(lista, inicio, q - 1)
        quicksortMedianaDeTres(lista, q + 1, fim) 
   

def particaoMediana3(lista, inicio, fim):
    meio = int( (inicio + fim) / 2)
    a = lista[inicio]
    b = lista[meio]
    c = lista[fim]
    if(a < b):
        if(b < c):
            medianaIndice = meio
        else:
            if(a < c):
                medianaIndice = fim
            else:
                medianaIndice = inicio
    else:
        if(c < b):
            medianaIndice = meio
        else:
            if(c < a):
                medianaIndice = fim
            else:
                medianaIndice = inicio
    troca(lista, medianaIndice, fim)
 
    #PARTIÇÃO DE CORMEN
    pivo = lista[fim]
    i = inicio - 1
    for j in range(inicio,fim):
        if(lista[j] <= pivo):
            i = i + 1
            troca(lista, i, j)
    troca(lista, i + 1, fim)
    return i + 1



###############################################################################

# PARTIÇÃO ESQUEMA DAS MEDIANAS

def MedianaK(listaInteiros, k): 
        quicksortMedianaK(listaInteiros, 0, np.size(listaInteiros)-1, k)
    
def particionaMedianaK(listaInteiros, inicio, fim, k):
    div = ((float) (fim - inicio)) / (float) (k - 1)
    aux = 0
    indice=[]
    for i in range(0,k):
            indice.append(aux)
            aux = aux + div
            aux = int(aux)

    n = np.size(indice)
    temp = 0
    for i in range(0,n):
        for j in range(1,n-1):
            if (listaInteiros[indice[j - 1]] > listaInteiros[indice[j]]):
                temp = indice[j - 1]
                indice[j - 1] = indice[j]
                indice[j] = temp

    medianaIndice =int( (inicio + fim) / 2)
    troca(listaInteiros,medianaIndice,fim)

    pivo = listaInteiros[fim]
    i = inicio - 1

    for j in range(inicio,fim):            
        if(listaInteiros[j]<=pivo):
            i = i + 1;
            troca(listaInteiros,i,j)

    troca(listaInteiros,i+1,fim)
    return i + 1
    

def quicksortMedianaK(listaInteiros, inicio, fim, k):
    if (inicio < fim):
        q = particionaMedianaK(listaInteiros, inicio, fim, k)
        quicksortMedianaK(listaInteiros, inicio, q - 1, k)
        quicksortMedianaK(listaInteiros, q + 1, fim, k)
        
###############################################################################

# PARTIÇÃO ESQUEMA DE LOMUTO

def Lomuto(lista):
    quicksortLomuto(lista,0,len(lista)-1)

def quicksortLomuto(lista, inicio, fim): 
    if (inicio < fim):
        q = particaoLomuto(lista, inicio, fim)
        quicksortLomuto(lista, inicio, q - 1)
        quicksortLomuto(lista, q + 1, fim)

def particaoLomuto(lista, inicio, fim):
    pivo = lista[fim]
    i = inicio
    for j in range(inicio,fim):
        if (lista[j] < pivo):
            troca(lista,i,j)
            i = i + 1
    troca(lista,i,fim)
    return i    

###############################################################################

# PARTIÇÃO ESQUEMA DE HOARE

def Hoare(lista):
    quicksortHoare(lista,0,len(lista)-1)

def quicksortHoare(lista, inicio, fim):
    if inicio < fim:
        q = particaoHoare(lista, inicio, fim)
        quicksortHoare(lista, inicio, q)
        quicksortHoare(lista, q + 1, fim)

def particaoHoare(lista, inicio, fim):
    pivo = lista[inicio]
    i=inicio-1
    j=fim+1
    while 1:
        i = i + 1
        while (lista[i] < pivo):
            i = i + 1
        j=j-1
        while (lista[j] > pivo):
            j=j-1
        
        if (i >= j):
            return j
        #lista[i],lista[j]=lista[j],lista[i]
        troca(lista,i,j)

###############################################################################

# ESQUEMA DO PROF
        
def achaPivo(n1,n2,lista):
    esq=n1
    di=n2
    pos=esq+1
    pto=0
    while(1>0):
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
    while(esq<=di):
        troca(lista,esq,di)
        while(lista[esq]<=pivo):
            esq=esq+1
            while(lista[di]>pivo):
                di=di-1
    return di

def quicksortRaul(lista,n1,n2):
    esq=n1
    di=n2
    pto=achaPivo(esq,di,lista)
    if(pto!=0):
        p=particao(esq,di,pto,lista)
        quicksortRaul(lista,esq,p)
        quicksortRaul(lista,p+1,di)
    
def iniciaquick(lista):
    quicksortRaul(lista,0,len(lista)-1)

###############################################################################

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
#   2 - K TROCAS - PADRÃO 5 TROCAS
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

###############################################################################
n=3
y=1000000
l=lista(y)
embaralhar(l,n)

t1=[]
t2=[]
t3=[]
t4=[]
t5=[]
t6=[]
#print("Lista Embaralhada:",l)

ti1=t.time()

for i in range(100):
    
    inicio=t.time()
    MedianaDe3(l)
    fim=t.time()
    t1.append(fim-inicio)
    #print("Tempo Mediana de 3:",fim-inicio,"s")

    embaralhar(l,n)
    
    inicio=t.time()
    MedianaK(l,5)
    fim=t.time()
    t2.append(fim-inicio)
    #print("Tempo Mediana de K:",fim-inicio,"s")
    
    embaralhar(l,n)
    
    inicio=t.time()
    Hoare(l)
    fim=t.time()
    t3.append(fim-inicio)
    #print("Tempo Hoare:",fim-inicio,"s")
    
    embaralhar(l,n)
    
    inicio=t.time()
    Lomuto(l)
    fim=t.time()
    t4.append(fim-inicio)
    #print("Tempo Lomuto:",fim-inicio,"s")
    
#    embaralhar(l,n)
#    
#    inicio=t.time()
#    iniciaquick(l)
#    fim=t.time()
#    t5.append(fim-inicio) 
    
    embaralhar(l,n)
    
    inicio=t.time()
    l.sort()
    fim=t.time()
    t6.append(fim-inicio)

del l

ti2=t.time()
print(ti2-ti1)
#plt.boxplot(t1)
#plt.boxplot(t2)
#plt.boxplot(t3)
#plt.boxplot(t4)

print("Tamanho:",y)
print("Nível Embaralhamento:",n)
print("Mediana de 3:",np.mean(t1),"s")
print("Mediana de k:",np.mean(t2),"s")
print("Hoare:       ",np.mean(t3),"s")
print("Lomuto:      ",np.mean(t4),"s")
#print("Raul:        ",np.mean(t5),"s")
print("Python:      ",np.mean(t6),"s")

#print("Lista Ordenada",l)


