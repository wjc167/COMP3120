#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char* buffer1 = "child\n";
char* buffer2 = "parent\n";

int main(void){
	int des;
	int pid;

	des = open("./in.txt",O_RDWR);

	pid = fork();
	
	if( pid == 0)
	{
		printf("child descriptor : %d\n", des);
		write(des, buffer1, strlen(buffer1));
	}else{
		printf("parent descriptor : %d\n", des);
		write(des, buffer2, strlen(buffer2));
	}

	return 0;
}
