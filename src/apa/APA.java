/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package apa;

import java.time.Duration;
import java.time.Instant;

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
        int nivelOrdenacao = 2;
        int quantTrocas = 2;

        int execucoes = 500;

        long tH[] = new long[execucoes];
        long tL[] = new long[execucoes];
        long tMed3[] = new long[execucoes];
        long tI[] = new long[execucoes];
        long tR[] = new long[execucoes];

        Lomuto lo = new Lomuto();
        Hoare h = new Hoare();
        MedianaDe3 m3 = new MedianaDe3();
        Iterativo ite = new Iterativo();
        Raul r = new Raul();
        
        for (int i = 0; i < execucoes; i++) {
            l.shuffle(nivelOrdenacao, quantTrocas);
            
            Instant inicio = Instant.now();
            h.Hoare(l.lista);
            Instant fim = Instant.now();
            tH[i] = Duration.between(inicio, fim).toNanos();

            l.shuffle(nivelOrdenacao, quantTrocas);

            inicio = Instant.now();
            m3.MedianaDe3(l.lista);
            fim = Instant.now();
            tMed3[i] = Duration.between(inicio, fim).toNanos();

            l.shuffle(nivelOrdenacao, quantTrocas);

            inicio = Instant.now();
            lo.Lomuto(l.lista);
            fim = Instant.now();
            tL[i] = Duration.between(inicio, fim).toNanos();

            l.shuffle(nivelOrdenacao, quantTrocas);

            inicio = Instant.now();
            ite.qIterativo(l.lista);
            fim = Instant.now();
            tI[i] = Duration.between(inicio, fim).toNanos();

            l.shuffle(nivelOrdenacao, quantTrocas);

            inicio = Instant.now();
            r.quickRaul(l.lista);
            fim = Instant.now();
            tR[i] = Duration.between(inicio, fim).toNanos();
        }

        long L, H, R, I, MED3;
        L = H = R = I = MED3 = 0;
        for (int i = 0; i < execucoes; i++) {
            L = L + tL[i];
            H = H + tH[i];
            I = I + tI[i];
            MED3 = MED3 + tMed3[i];
            R = R + tR[i];
        }

        System.out.println("Tempo:");
        System.out.println("Hoare: " + H / execucoes + " ns");
        System.out.println("Lomuto: " + L / execucoes + " ns");
        System.out.println("Med 3: " + MED3 / execucoes + " ns");
        System.out.println("Iterativo: " + I / execucoes + " ns");
        System.out.println("Raul: " + R / execucoes + " ns");
    }
}
