//Programa 1
// syscall read(), open() e close()
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	char texto[26];
	char path[100];

	int arq = open("arquivo",O_RDONLY);
	int b = read(arq,texto,25);
	texto[25] = '\0';
	puts(texto);
	int a = close(arq);
	return 0;
}



