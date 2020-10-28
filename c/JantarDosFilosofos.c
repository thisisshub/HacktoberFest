#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define QtdeFilosofos 5
#define Pensar 0
#define Fome 1
#define Comer 2
#define Esquerda (filosofos+4)%QtdeFilosofos //pega garfo da esquerda
#define Direita (filosofos+1)%QtdeFilosofos  //pega garfo da direita
void *filosofo(void *num);
void pegaGarfo(int);
void soltaGarfo(int);
void verifica(int);

sem_t mutex;
sem_t S[QtdeFilosofos]; //inicializacao do semáforo
int estado[QtdeFilosofos];
int filosofos[QtdeFilosofos]={0,1,2,3,4};

void *filosofo(void *num)
{
   while(1)
   {
      int *i = num;
      sleep(1);
      pegaGarfo(*i);
      sleep(1);
      soltaGarfo(*i);
   }
}

void pegaGarfo(int filosofos)
{
   sem_wait(&mutex);
   estado[filosofos] = Fome;
   printf("Filosofo %d ta com fome.\n", filosofos+1);
   verifica(filosofos);
   sem_post(&mutex);
   sem_wait(&S[filosofos]);
   sleep(1);
}

void soltaGarfo(int filosofos)
{
   sem_wait(&mutex);
   estado[filosofos]=Pensar;
   printf("Filosofo %d soltou os garfos %d e %d na mesa.\n", filosofos+1, Esquerda+1, filosofos+1);
   printf("Filosofo %d ta pensando.\n", filosofos+1);
   verifica(Esquerda);
   verifica(Direita);
   sem_post(&mutex);
}

void verifica(int filosofos)
{
   if(estado[filosofos]==Fome && (estado[Esquerda]
 !=Comer && estado[Direita]!=Comer))
   {
      estado[filosofos]=Comer;
      sleep(2);
      printf("Filosofo %d agarrou os garfos %d e %d da mesa.\n", filosofos+1, Esquerda+1, filosofos+1);
      printf("Filosofo %d ta comendo.\n", filosofos+1);
      sem_post(&S[filosofos]);
   }
}

int main() {
   pthread_t thread_id[QtdeFilosofos]; //id das threads
   sem_init(&mutex,0,1);
   int i;
   for(i=0; i<QtdeFilosofos; i++)
      sem_init(&S[i],0,0);
   for(i=0; i<QtdeFilosofos; i++)
   {
      pthread_create(&thread_id[i], NULL, filosofo, &filosofos[i]);
      //criar as threads
      printf("Filosofo %d ta pensando.\n",i+1);
   }
   for(i=0;i<QtdeFilosofos;i++)
   pthread_join(thread_id[i],NULL); //sincronizar as threads
   return(0);
}
