//Programa 1
// syscall read(), open() e close()
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
int main(){
	char texto[12];
	int arq = open("arquivo",O_RDONLY); // abre o arquivo no modo READ ONLY
	read(arq,texto,strlen("Arquivo lido com sucesso.")); //  le o arquivo
	printf("%s\n", texto);
	close(arq); // fecha o arquivo
	return 0;
}
