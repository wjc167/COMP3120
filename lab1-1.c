#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x;
	int pid = fork();

	x = 100;
	if(pid == 0){
		printf("child process : %d\n", x);
		x = 50;
		printf("child x = 50\n");
		printf("child process : %d\n", x);
	}
	else{
		printf("main process : %d\n", x);
		x = 150;
		printf("main x = 150\n");
		printf("main process : %d\n", x);
	
	}

	return 0;
}
