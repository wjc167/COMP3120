#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
 
int count = 0;
int b = 0;
pthread_t p[10000];
pthread_mutex_t mutex_lock;
struct timeval starttime, finishtime;
int start, finish;

void *ThreadRun(void *arg)
{
		
	while(1){
		if(count >= 10000){
			return 0;
		}
		if(b == 1){
			pthread_mutex_lock(&mutex_lock);
		}
		count++;
		if(b == 1){
			pthread_mutex_unlock(&mutex_lock);
		}
	}

}

int main(void){
	int i, a;
	

	printf("want lock?(1. yes 2. no)");
	scanf("%d", &b);
	if( b ==1)
		pthread_mutex_init(&mutex_lock, NULL);
	printf("how many?");
	scanf("%d", &a);
	gettimeofday(&starttime, NULL);	
	for(i = 0; i < a; i++){
		pthread_create(&p[i], NULL, ThreadRun, NULL);
	}
	for(i = 0; i < a; i++){
		pthread_join(p[i], NULL);
	}

	gettimeofday(&finishtime, NULL);			
	printf("counter : %d\n", count);
	printf("time : %d micro second\n", finishtime.tv_usec-starttime.tv_usec);	
	
	return 0;
}
