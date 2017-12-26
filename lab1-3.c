#include <stdio.h>

int main(void){
	int i;
	int pid = fork();

	if(pid == 0){
		printf("hello\n");
	}
	else{
		for(i = 0; i < 1000000; i++);
		printf("goodbye\n");
	}
}
