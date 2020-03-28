//programa que calcula o fatorial de um numero e ordena um vetor de 10 elementos com quicksort
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {//funcao de ordenacao usada pelo qsort()
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n, i;
    unsigned long long fat = 1;

    n = 60;//numero do qual sesra calculado o fatorial
    int a[10] ={1,2,7,3,8,5,9,0,4,6};//vetor a ser ordenado

    qsort(a,10,sizeof(int),cmpfunc);//ordena o vetor

        for (i = 1; i <= n; i++) {//imprime o vetor na tela
            fat *= i;
        }

            for( i=0;i<10;i++ ) {
          printf("%d ", a[i]);
       }
        printf("\nFatorial de %d = %llu", n, fat);//imprime o fatorial na tela


    return 0;
}
