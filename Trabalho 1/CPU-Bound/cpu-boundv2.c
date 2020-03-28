//programa que calcula o fatorial de um numero, feito para exemplificar o comportamento CPU-bound
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    int n, i;
    unsigned long long fat = 1;

    n = 60;
    int a[10] ={1,2,7,3,8,5,9,0,4,6};

    qsort(a,10,sizeof(int),cmpfunc);

        for (i = 1; i <= n; i++) {
            fat *= i;
        }

            for( i=0;i<10;i++ ) {
          printf("%d ", a[i]);
       }
        printf("Fatorial de %d = %llu", n, fat);


    return 0;
}
