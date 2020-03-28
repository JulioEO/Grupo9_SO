//programa que calcula o fatorial de um numero, feito para exemplificar o comportamento CPU-bound
//o programa passas a maior parte do tempo de execucao realizando a multiplicacao do fatorial
#include <stdio.h>

int main() {
    int n, i;
    unsigned long long fat = 1;
    printf("Digite um inteiro: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Nao existe fatorial de numeros negativos.");
    else if (n==0){
    	printf("Fatorial de %d = 1", n);
    } 
    else{
        for (i = 1; i <= n; i++) {
            fat *= i;
        }
        printf("Fatorial de %d = %llu", n, fat);
    }

    return 0;
}
