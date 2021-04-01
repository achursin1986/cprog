#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_THREADS     19

time_t t;
int value=0;
pthread_mutex_t value_lock;
int flag=0;
pthread_cond_t cond_var=PTHREAD_COND_INITIALIZER;

void *AddRandom(void *threadid)
{
	
	long tid;
	tid = (long)threadid;
	int random;
	int i=0;
	pthread_mutex_lock(&value_lock);
	pthread_cond_wait(&cond_var,&value_lock);
	//pthread_mutex_lock(&value_lock);
	random = rand() % 7;
        printf("thread #%ld adding random which is %i\n", tid, random);
	value += random;
	pthread_mutex_unlock(&value_lock);
//	printf("we just unlocked mutex\n");
	pthread_exit(NULL);
}

void *CreateNumber(void *threadid)
{
   	long tid;
   	tid = (long)threadid;
   	int i=0;
  	pthread_mutex_lock(&value_lock);
	printf("\nPlease enter value\n");
	scanf("%d",&value);
   	printf("thread #%ld initializing value to %i\n", tid, value);
	pthread_cond_broadcast(&cond_var);
//	printf("we have reached here\n");
	pthread_mutex_unlock(&value_lock);
   	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   	pthread_t threads[NUMBER_OF_THREADS];
   	int return_code;
   	long t;
	int i=0;

	srand((unsigned) time(&t));

	if (pthread_mutex_init(&value_lock, NULL) != 0)
	{
		printf("\n mutex initialization failed\n");
		return 1;
	}


   	for(t=0; t<NUMBER_OF_THREADS; t++){
      		printf("In main: creating thread %ld\n", t);
      		return_code = pthread_create(&threads[t], NULL, AddRandom, (void *)t);
      		if (return_code){
         		printf("ERROR; return code from pthread_create() is %d\n", return_code);
         	exit(-1);
      		}
	}
	return_code = pthread_create(&threads[t], NULL, CreateNumber, (void *)t);
      	if (return_code){
         	printf("ERROR; return code from pthread_create() is %d\n", return_code);
         exit(-1);
        }		
   	while(i < (int)NUMBER_OF_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}	
   	/* Last thing that main() should do */
	printf("Sum is %i\n", value);
   	pthread_exit(NULL);
	return 0;
}

