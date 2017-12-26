#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int pipefd[2];
	int pid1, pid2;
	char buf;

	if(pipe(pipefd) == -1){
		exit(1);
	}

	pid1 = fork();
	pid2 = fork();
	if(pid1 == 0){
		close(pipefd[1]);
		while(read(pipefd[0], &buf, 1) >0)
			write(STDOUT_FILENO, &buf,1);

		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		exit(1);
	}else if(pid2 == 0){
		close(pipefd[0]);
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]);
		wait(NULL);
		exit(1);
	}

	return 0;
}
