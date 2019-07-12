/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.util.ArrayList;
import java.util.Collections;

/**
 *
 * @author Rodrigo
 */
public class Iterativo {

    private int partiticao(ArrayList<Integer> lista, int inicio, int fim) {
        int x = lista.get(fim);
        int i = (inicio - 1);

        for (int j = inicio; j <= fim - 1; j++) {
            if (lista.get(j) <= x) {
                i++;
                Collections.swap(lista, i, j);
            }
        }
        Collections.swap(lista, i + 1, fim);
        return (i + 1);
    }

    /* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
    private void quickSortIterativo(ArrayList<Integer> lista, int inicio, int fim) {
        // Create an auxiliary stack
        int pilha[] = new int[fim - inicio + 1];

        // initialize top of stack
        int top = -1;

        // push initial values of l and h to stack
        pilha[++top] = inicio;
        pilha[++top] = fim;

        // Keep popping from stack while is not empty
        while (top >= 0) {
            // Pop h and l
            fim = pilha[top--];
            fim = pilha[top--];

            // Set pivot element at its correct position
            // in sorted array
            int p = partiticao(lista, inicio, fim);

            // If there are elements on left side of pivot,
            // then push left side to stack
            if (p - 1 > fim) {
                pilha[++top] = inicio;
                pilha[++top] = p - 1;
            }

            // If there are elements on right side of pivot,
            // then push right side to stack
            if (p + 1 < fim) {
                pilha[++top] = p + 1;
                pilha[++top] = fim;
            }
        }
    }

    public void Iterativo(ArrayList<Integer> lista) {
        quickSortIterativo(lista, 0, lista.size());
    }
}
