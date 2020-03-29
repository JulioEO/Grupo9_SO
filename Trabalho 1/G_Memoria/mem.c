/*
Nesse c�digo foram chamadas 3 system calls :

    1 -> void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset)-> cria um novo mapeamento no espa�o de endere�o virtual do processo de chamada.
    2 -> int munmap(void *addr, size_t length)-> deleta os mapeamentos de uma determinada regi�o especificada em um endere�o de mem�ria.
    3 -> int mprotect(void *addr, size_t len, int prot) -> Define uma prote��o em uma �rea da mem�ria .

System calls utilizadas pelo sistema :

    Tempo(s):    Syscall:

    0.000072    access
    0.000045    mmap
    0.000021    open
    0.000015    mprotect
    0.000011    write
    0.000006    munmap
    0.000005    fstat
    0.000004    read
    0.000004    close
    0.000003    execve
    0.000002    arch_prctl
    0.000001    brk
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>

int main(){
	int *mp = mmap(0, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0); // Retorna o ponteiro da area mapeada
	if(mp== MAP_FAILED) // Verifica se o mapeamento foi bem sucedido
        printf("Erro !! \n");
	else
    {
		printf("Foi mapeado com sucesso: %p\n", mp);

		int prot = mprotect(mp, 4096, PROT_READ); // define uma prote��o pra essa �rea de mem�ria
        if(prot==0) // verifica se a prote��o foi bem sucedida
            printf("A regiao da memoria esta protegida\n");
        else
            printf("Erro, nao foi possivel completar a opera�ao\n");

        int flag = munmap(mp, 4096); // deleta o mapeamento nesse espa�o de mem�ria

        if(flag == 0) // verifica se foi removido o mapeamento
            printf("Foi removido o mapeamento !!\n");
        else
            printf("Erro !!\n");
	}
	return 0;
}
