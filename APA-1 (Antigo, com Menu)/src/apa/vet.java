/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.util.Random;

/**
 *
 * @author Rodrigo
 */
public class vet {

    public int[] v;
    public int n;

    public vet(int n) {
        this.n = n;
        vetor(n);
    }

    private void vetor(int n) {
        this.v = new int[this.n];
        for (int i = 0; i < n; i++) {
            this.v[i] = i;
        }
    }

    public void sort(int s) {
        Random r = new Random();
        if (s == 1) {
            Swap(this.v, r.nextInt(this.n), r.nextInt(this.n));
        } else if (s == 2) {
            for (int i = 0; i < (n/10); i++) {
                Swap(this.v, r.nextInt(this.n), r.nextInt(this.n));
            }
        } else if (s == 3) {
            for (int i = 0; i < 1000; i++) {
                Swap(this.v, r.nextInt(this.n), r.nextInt(this.n));
            }
        }
        else if(s==4){
            for(int i=0;i<this.n;i++){
                this.v[i]=this.n-(i+1);
            }
        }
        else{
            System.out.println("Valor Errado");
        }
    }

    private void Swap(int[] array, int position1, int position2) {
        int temp = array[position1];
        array[position1] = array[position2];
        array[position2] = temp;
    }
    
    public void imprime() {
        int i;
        for (i = 0; i < this.n; i++) {
            System.out.print(" " + this.v[i]);
        }
        System.out.println();
    }
}
