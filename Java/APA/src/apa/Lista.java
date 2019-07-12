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

    public void shuffle(int t,int n) {
        Random r = new Random();
        switch (t) {
            case 1://EMBARALHA TUDO
                Collections.shuffle(this.lista); 
                break;
            case 2://UMA TROCA - TROCA UMA POSICAO COM A PROXIMA
                int aux = r.nextInt(lista.size() - 2);
                Collections.swap(lista, aux, aux + 1);
                break;
            case 3: // UMA TROCA - TROCA UMA POSICAO COM OUTRA ALEATORIA
                Collections.swap(lista, r.nextInt(lista.size() - 2), r.nextInt(lista.size() - 2));
                break;
            case 4: //N TROCAS
                for(int i=0;i<n;i++){
                    Collections.swap(lista, r.nextInt(lista.size() - 2), r.nextInt(lista.size() - 2));
                }
                break;
            default:
                break;
        }
    }

    public void umaTroca(){
        int tam = this.lista.size()/2;
        Collections.swap(lista, tam, tam+1);
    }
    
    public void imprime() {
        for (int i = 0; i < this.lista.size(); i++) {
            System.out.print(this.lista.get(i) + " ");
        }
         System.out.println("");
    }
}
