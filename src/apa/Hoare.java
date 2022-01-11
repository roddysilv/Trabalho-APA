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
public class Hoare {

    public void Hoare(ArrayList<Integer> lista) {
        quicksortHoare(lista, 0, lista.size() - 1);
    }

    private void quicksortHoare(ArrayList<Integer> lista, int inicio, int fim) {
        if (inicio < fim) {
            int q = particaoHoare(lista, inicio, fim);
            quicksortHoare(lista, inicio, q);
            quicksortHoare(lista, q + 1, fim);
        }
    }

    private int particaoHoare(ArrayList<Integer> lista, int inicio, int fim) {
        int pivo = lista.get(inicio);
        int i = inicio - 1;
        int j = fim + 1;
        while (1 > 0) {
            i = i + 1;
            while (lista.get(i) < pivo) {
                i = i + 1;
            }
            j = j - 1;
            while (lista.get(j) > pivo) {
                j = j - 1;
            }
            if (i >= j) {
                return j;
            }
            Collections.swap(lista, i, j);
        }
    }
}
