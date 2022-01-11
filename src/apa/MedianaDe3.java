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
public class MedianaDe3 {

    public void MedianaDe3(ArrayList<Integer> lista) {
        quicksortMedianaDeTres(lista, 0,lista.size()-1);
    }

    private void quicksortMedianaDeTres(ArrayList<Integer> lista, int inicio, int fim) {
        if (inicio < fim) {
            int q = particaoMediana3(lista, inicio, fim);
            quicksortMedianaDeTres(lista, inicio, q - 1);
            quicksortMedianaDeTres(lista, q + 1, fim);
        }
    }

    private int particaoMediana3(ArrayList<Integer> lista, int inicio, int fim) {
        int meio = ((inicio + fim) / 2);
        int a = lista.get(inicio);
        int b = lista.get(meio);
        int c = lista.get(fim);
        int medianaIndice;
        if (a < b) {
            if (b < c) {
                medianaIndice = meio;
            } else {
                if (a < c) {
                    medianaIndice = fim;
                } else {
                    medianaIndice = inicio;
                }
            }
        } else {
            if (c < b) {
                medianaIndice = meio;
            } else {
                if (c < a) {
                    medianaIndice = fim;
                } else {
                    medianaIndice = inicio;
                }
            }
        }
        Collections.swap(lista, medianaIndice, fim);

//#PARTIÇÃO DE CORMEN
        int pivo = lista.get(fim);
        int i = inicio - 1;
        for (int j = inicio; j < fim; j++) {
            if (lista.get(j) <= pivo) {
                i = i + 1;
                Collections.swap(lista, i, j);
            }
        }
        Collections.swap(lista, i+1, fim);
        return i + 1;
    }
}
