/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.time.Duration;
import java.time.Instant;
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
        int tam = 50000;
        Lista l = new Lista(tam);
        //l.imprime();
   
        l.shuffle(1,20);
        //l.imprime();
     
        Lomuto lo = new Lomuto();
        Hoare h = new Hoare();
        MedianaDe3 m3= new MedianaDe3();
        Iterativo ite = new Iterativo();
        Raul r = new Raul();
        
        Instant inicio = Instant.now();
        
        h.Hoare(l.lista);
        Instant fim = Instant.now();
        //m3.MedianaDe3(l.lista);
        //lo.Lomuto(l.lista);
        //ite.Iterativo(l.lista);
        //r.quickRaul(l.lista);
        //l.imprime();
        long tempo = Duration.between(inicio, fim).toNanos();
        System.out.println(tempo + " ns");
        //for (int i = 0; i < arr.size(); i++) {
        //    System.out.print(arr.get(i) + " ");
        //}
        //System.out.println("teste: " + arr.size());
    }

}
