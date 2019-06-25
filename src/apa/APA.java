package apa;

import java.util.Random;

public class APA {

    public static void main(String[] args) {
        /*
        int[] arr = {10, 7, 8, 9, 1, 5};
        int n = arr.length;
        Lomuto l = new Lomuto();
        l.quickSort(arr, 0, n - 1);
        System.out.println("Sorted array: ");
        l.printArray(arr, n);

        int[] arr2 = {10, 7, 8, 9, 1, 5};
        int n2 = arr2.length;
        Hoare h = new Hoare();
        h.quickSort(arr, 0, n - 1);
        System.out.println("Sorted array: ");
        h.printArray(arr, n);
         */

        //Random r = new Random();
        //System.out.println(r.nextInt(1000)-r.nextInt(1000));
        
        
        vet v = new vet(1000000);
        v.sort(4);
        //v.imprime();
        
        Lomuto l = new Lomuto();
        Hoare h = new Hoare();
        long t=System.currentTimeMillis();
        //h.quickSort(v.v, 0, v.n - 1);
        long f=System.currentTimeMillis();
        System.out.println(f-t);
        //System.out.println("Sorted array: ");
        //h.printArray(v.v, v.n);
        
        System.out.println(t);
        System.out.println(f);

        v.imprime();
        Iterativo i = new Iterativo();
        i.quickSortIterative(v.v, 0,v.n- 1);
        v.imprime();
    }

}
