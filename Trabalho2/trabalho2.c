#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define TAMANHO 100
//compilar com : gcc -pthread -o trabalho2 trabalho2.c
pthread_mutex_t lock;


typedef struct{
          int lista[TAMANHO];
          int livre;
}pilha;

void *consumir( void *);
void *produzir( void *);
void regiao_critica(pilha* buf,int* , int);

int main(){

     pilha *buffer;
     //inicializa o buffer
     for(int i = 0; i< TAMANHO; i++) (*buffer).lista[i] = -1;
     (*buffer).livre = 0;


     pthread_t prod, cons;
	int p,c;

	p = pthread_create( &prod, NULL, produzir,(void*) buffer);
	c = pthread_create( &cons, NULL, consumir,(void*) buffer);
     //checa se os threads foram criados sem erros
	if(c != 0 || p !=0 ){
		puts("ERRO\n");
		exit(0);
	}

     pthread_join( cons, NULL);
     pthread_join( prod, NULL);

	return 0;
}

// le o ultimo numero gravado no buffer
void *consumir( void *ptr){
     pilha* b = (pilha*) ptr;
     int n;
     for(int j = 0; j<100*TAMANHO;j++){
          regiao_critica(b, &n , -1);
          printf("Consumido %d posicao %d\n", n, b->livre -1);
     }
}


// produz um numero aleatório e grava no buffer
void *produzir( void *ptr){
     pilha* b = (pilha*) ptr;
     srand(time(0));
     for(int j = 0; j<100*TAMANHO;j++){
          int a = rand() % 100;
          regiao_critica(b ,NULL , a);
          printf("Produzido %d posicao %d\n", a, b->livre -1);
     }
}
// regiao critica
void regiao_critica(pilha* buf,int *c, int p){

     pthread_mutex_lock(&lock);
     if (c == NULL && buf->livre < TAMANHO){
          buf->lista[(*buf).livre] = p;
          buf->livre++;
     }
     else if(p > -1 && buf->livre > 0){
          *c = buf->lista[(*buf).livre -1];
          buf->livre--;
     }
     pthread_mutex_unlock(&lock);
}