Programa exemplo para system call de processos. 

As system calls principais usadas são: fork(), wait() e getpid().
O programa não tem interação do usuário, então basta rodá-lo. Ele simplesmente cria um processo filho com fork().
O processo filho então escreve uma mensagem e termina. Enquanto isso o pai espera o filho encerrar, para depois escrever uma mensagem
utilizando o getpid() para mostrar qual processo mandou qual mensagem.
