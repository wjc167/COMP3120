#include <stdio.h>

int main(void){
	char *argv[3] = {"ls", ".", NULL};

	int pid = fork();

	if(pid == 0){
		execvp ("ls", argv);
	}

	wait(2);
		
	return 0;
}


