#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#define TAMANHO 20// tamanho do buffer
#define R 30 //R * TAMANHO é o número de repeticoes do produtor e do consumidor
//compilar com : gcc -pthread -o trabalho2 trabalho2.c
pthread_mutex_t lock;
pthread_cond_t dormir;
int k = 0;//marca o numero da iteracao atual
int fim_prod = 0;//flag indiica se o produtor ja finalizou 
typedef struct{
          int lista[TAMANHO];
          int livre;
          int vazios;
          int ocupados;
}pilha;

void *consumir( void *);
void *produzir( void *);
void regiao_critica(pilha*,int* , int);

int main(){

     pilha *buffer = (pilha*)malloc(sizeof(pilha));
     //inicializa o buffer
     for(int i = 0; i< TAMANHO; i++) buffer->lista[i] = -1;
     buffer->livre = 0;
     buffer->vazios = TAMANHO;
     buffer->ocupados = 0;

	//cria threads
     pthread_t prod, cons;
	int p,c;

	p = pthread_create( &prod, NULL, produzir,(void*) buffer);
	c = pthread_create( &cons, NULL, consumir,(void*) buffer);
     //checa se os threads foram criados sem erros
	if(c != 0 || p != 0 ){
		puts("ERRO\n");
		exit(0);
	}
	//espera as threads finalizarem finalizar 
     pthread_join( cons, NULL);
     pthread_join( prod, NULL);
     puts("\n\nFIM!!!!!!!\n\n");

	return 0;
}

// le o ultimo numero gravado no buffer
void *consumir( void *ptr){
     pilha* b = (pilha*) ptr;
     int n;

     for(int j = 0; j<R*TAMANHO;j++){
	     k++;
          regiao_critica(b, &n , -1);// -1 indica que e o consumidor acessando a regiao critica
     }
}


// produz um numero aleatório e grava no buffer
void *produzir( void *ptr){
     pilha* b = (pilha*) ptr;
     srand(time(0));
     int a;
     for(int j = 0; j<R*TAMANHO;j++){
	     k++;
          a = rand() % 100;
          regiao_critica(b ,NULL , a);// NULL indica que é o produtor acessando a regiao critica
     }
	fim_prod = 1;
}
// regiao critica
void regiao_critica(pilha* buf,int *c, int p){

     pthread_mutex_lock(&lock);

     //produtor escreve no buffer
     if (c == NULL){
          if (buf->livre == 0) pthread_cond_signal(&dormir); //consumidor esvaziou o buffer e dormiu, acorda o consumidor
          if(buf->livre < TAMANHO){
               buf->lista[buf->livre] = p;
               printf("%d - Produzido %d posicao %d\n", k, buf->lista[buf->livre], buf->livre);
               buf->vazios--;
               buf->ocupados++;
               printf("Espacos livres %d\n",buf->vazios );
               printf("Espacos ocupados %d\n",buf->ocupados);
               buf->livre++;
          }else pthread_cond_wait(&dormir,&lock); //buffer encheu, produtor dorme
          
     }
     //consumidor le do buffer
     else if (p == -1){
          if (buf->livre == TAMANHO) pthread_cond_signal(&dormir);//produtor echeu o buffer e dormiu, acorda o produtor
          if(buf->livre > 0){
               buf->livre--;
               printf("%d - Consumido %d posicao %d\n",k,  buf->lista[buf->livre], buf->livre);
               buf->vazios++;
               buf->ocupados--;
               printf("Espacos livres %d\n",buf->vazios );
               printf("Espacos ocupados %d\n",buf->ocupados);
               *c = buf->lista[buf->livre];
               buf->lista[buf->livre] = -1;
          }else if(fim_prod == 0) pthread_cond_wait(&dormir,&lock);// buffer esvaziou, consumidor dorme apenas se o produtor ainda nao finalizou
     }
     pthread_mutex_unlock(&lock);
}
