#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define TAMANHO 50 // tamanho do buffer
//compilar com : gcc -pthread -o trabalho2 trabalho2.c
pthread_mutex_t lock;


typedef struct{
          int lista[TAMANHO];
          int livre;// proximo espaco vazio
}pilha;

void *consumir( void *);
void *produzir( void *);
void regiao_critica(pilha* buf,int* , int);

int main(){

     pilha *buffer;
     //inicializa o buffer
     for(int i = 0; i< TAMANHO; i++) buffer->lista[i] = -1;
     buffer->livre = 0;


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
	
	puts("\n\nFIM!!!!!!!\n\n");

	return 0;
}

// le o ultimo numero gravado no buffer
void *consumir( void *ptr){
     pilha* b = (pilha*) ptr;
     int n;
     for(int j = 0; j<100*TAMANHO;j++){//repeticoes, para testar o codigo
          regiao_critica(b, &n , -1);
     }
}


// produz um numero aleatório e grava no buffer
void *produzir( void *ptr){
     pilha* b = (pilha*) ptr;
     srand(time(0));
     for(int j = 0; j<100*TAMANHO;j++){//repeticoes, para testar o codigo
          int a = rand() % 100;
          regiao_critica(b ,NULL , a);
     }
}
// regiao critica, eu nao tenho certeza se o mutex funciona em uma funcao chamada por um thread.
void regiao_critica(pilha* buf,int *c, int p){

     pthread_mutex_lock(&lock);

     //escreve noo buffer
     if (c == NULL && buf->livre < TAMANHO){
          buf->lista[buf->livre] = p;
	  printf("Produzido %d posicao %d\n",  buf->lista[buf->livre], buf->livre);
          buf->livre++;
	  
     }
     //le do buffer
     else if(p == -1 && buf->livre > 0){
	  printf("Produzido %d posicao %d\n",  buf->lista[buf->livre -1 ], buf->livre -1);
          buf->livre--;
          *c = buf->lista[buf->livre];
          buf->lista[buf->livre] = -1;
     }
     pthread_mutex_unlock(&lock);
}
