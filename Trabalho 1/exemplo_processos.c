#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(int argc, char const *argv[])//programa exemplo para as primitivas fork(), wait() e getpid()
{
	int processo = fork();//cria um processo filho com fork()
	if (processo==0){
		printf("Sou o processo filho!\n");//imprime se for o processo filho
		printf("Meu PID: %d\n",getpid() );//imprime o pid do filho com getpid()
		exit(0);
	}
	else if(processo > 0){
		wait(NULL);//espera o filho terminar com wait()
		printf("Sou o processo pai! Espero o filho acabar para imprimir essa mensagem!\n");//imprime se for o processo pai
		printf("Meu PID: %d\n",getpid() );//imprime o id do pai com getpid()
	}
	else{
		printf("Erro na criacao do processo!\n" );//imprime se houve erro na criacao do processo
	}
	return 0;
}
