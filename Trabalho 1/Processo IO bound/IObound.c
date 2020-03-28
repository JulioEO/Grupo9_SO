#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char string[1001];
	puts("Digite algo para ser invertido:");
	fgets(string,1000,stdin); // le uma string
	for(int i = strlen(string) -1; i>=0 ;i--) putchar(string[i]); //imprimi a string invertida 
	putchar('\n');
	return 0;
}
