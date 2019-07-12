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
public class APA {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int tam = 10000;
        Lista l = new Lista(tam);
        //l.imprime();
   
        l.shuffle(3);
        //l.imprime();
     
        Lomuto lo = new Lomuto();
        Hoare h = new Hoare();
        MedianaDe3 m3= new MedianaDe3();
        
        h.Hoare(l.lista);
        //m3.MedianaDe3(l.lista);
        //lo.Lomuto(l.lista);
        l.imprime();
        //for (int i = 0; i < arr.size(); i++) {
        //    System.out.print(arr.get(i) + " ");
        //}
        //System.out.println("teste: " + arr.size());
    }

}
