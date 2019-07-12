/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Stack;

/**
 *
 * @author Rodrigo
 */
public class Iterativo {

    public  void qIterativo(ArrayList<Integer> arr) {
        Stack<Integer> pilha = new Stack<Integer>();
        pilha.push(0);
        pilha.push(arr.size());
        while (!pilha.isEmpty()) {
            int fim = pilha.pop();
            int inicio = pilha.pop();
            if (fim - inicio < 2) {
                continue;
            }
            int p = inicio + ((fim - inicio) / 2);
            p = particao(arr, p, inicio, fim);

            pilha.push(p + 1);
            pilha.push(fim);

            pilha.push(inicio);
            pilha.push(p);

        }
    }

    private int particao(ArrayList<Integer> arr, int p, int inicio, int fim) {
        int l = inicio;
        int h = fim - 2;
        int pivo = arr.get(p);
     
        Collections.swap(arr, p, fim - 1);

        while (l < h) {
            if (arr.get(l) < pivo) {
                l++;
            } else if (arr.get(h) >= pivo) {
                h--;
            } else {
                Collections.swap(arr, l, h);
            }
        }
        int index = h;
        if (arr.get(h) < pivo) {
            index++;
        }
        Collections.swap(arr, fim - 1, index);
        return index;
    }
}
