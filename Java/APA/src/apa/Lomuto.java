/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.util.ArrayList;

/**
 *
 * @author Rodrigo
 */
import java.util.ArrayList;
import java.util.Collections;

public class Lomuto {

    public void Lomuto(ArrayList<Integer> lista) {
        quicksortLomuto(lista, 0, lista.size() - 1);
        }

    private void quicksortLomuto(ArrayList<Integer> lista, int inicio, int fim) {
        if (inicio < fim) {
            int q = particaoLomuto(lista, inicio, fim);
            quicksortLomuto(lista, inicio, q - 1);
            quicksortLomuto(lista, q + 1, fim);
        }
    }

    private int particaoLomuto(ArrayList<Integer> lista, int inicio, int fim) {
        int pivo = lista.get(fim);
        int i = inicio;
        for (int j = inicio; j < fim; j++) {
            if (lista.get(j) < pivo) {
                Collections.swap(lista, i, j);
                i = i + 1;
            }
        }
        Collections.swap(lista, i, fim);
        return i;
    }

}
