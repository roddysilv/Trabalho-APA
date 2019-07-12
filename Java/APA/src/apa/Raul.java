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
public class Raul {

    private int achaPivo(int n1, int n2, ArrayList<Integer> lista) {
        int esq = n1;
        int dir = n2;
        int pos = esq + 1;
        int pto = 0;
        while (true) {
            if (pos > dir) {
                break;
            } else if (lista.get(pos) >= lista.get(pos - 1)) {
                pos = pos + 1;
            } else {
                pto = pos;
                break;
            }
        }
        return pto;
    }

    private int particao(int n1, int n2, int pivo, ArrayList<Integer> lista) {
        int esq = n1;
        int dir = n2;
        while (esq <= dir) {
            Collections.swap(lista, esq, dir);
            while (lista.get(esq) <= pivo) {
                esq = esq + 1;
                while (lista.get(dir) > pivo) {
                    dir = dir - 1;
                }
            }
            if (lista.get(esq) > pivo && lista.get(dir) > pivo) {
                esq = esq + 1;
                dir = dir - 1;
            }
        }

        return dir;
    }

    private void quicksort(ArrayList<Integer> lista, int n1, int n2) {
        int esq = n1;
        int dir = n2;
        int pto = achaPivo(esq, dir, lista);
        if (pto != 0) {
            int p = particao(esq, dir, lista.get(pto), lista);
            quicksort(lista, esq, p);
            quicksort(lista, p + 1, dir);
        }
    }

    public void quickRaul(ArrayList<Integer> lista) {
        quicksort(lista, 0, lista.size() - 1);
    }
}
