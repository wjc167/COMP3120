#include <stdio.h>
#define DELAY 2

int main(void){
	int newpid;
	void parent_code(), child_code();

	printf("before: mypid is %d\n", getpid());

	if((newpid = fork()) == -1)
		perror("fork");
	else if (newpid == 0)
		child_code(DELAY);
	else
		parent_code(newpid);
}
void parent_code(int delay)
{
	printf("parent %d here. will sleep for %d seconds \n", getpid(), DELAY);
	sleep(DELAY);
	printf("parent done. about to exit\n");
	exit(17);
}

void child_code(int parentpid)
{
	int wait_rv;
	wait_rv = wait(NULL);
	printf("done waiting for %d. Wait returned: %d\n", parentpid, wait_rv);
}
