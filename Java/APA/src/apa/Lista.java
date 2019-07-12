/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

/**
 *
 * @author Rodrigo
 */
public class Lista {

    ArrayList<Integer> lista;

    public Lista(int tam) {
        lista = new ArrayList();
        for (int i = 0; i < tam; i++) {
            this.lista.add(i);
        }
    }

    public void shuffle(int t) {
        Random r = new Random();
        switch (t) {
            case 1:
                Collections.shuffle(this.lista);
                break;
            case 2:
                int aux = r.nextInt(lista.size() - 2);
                Collections.swap(lista, aux, aux + 1);
                break;
            case 3:
                Collections.swap(lista, r.nextInt(lista.size() - 2), r.nextInt(lista.size() - 2));
                break;
            case 4:
                break;
            default:
                break;
        }
    }

    public void imprime() {
        for (int i = 0; i < this.lista.size(); i++) {
            System.out.print(this.lista.get(i) + " ");
        }
         System.out.println("");
    }
}
