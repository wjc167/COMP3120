#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

int read_proc_stat(char *stat)
{
	FILE *fp;
	int ret;
	int i, u , s;
	char utime[10], stime[10];
	
	fp = fopen(stat, "r");

	for(i = 0; i < 13; i++)
	{
		ret = fscanf(fp, "%s", &utime);
	}
	ret = fscanf(fp, "%s %s", &utime, &stime);
	
	u = atol(utime);
	s = atol(stime);

	return 100 * (u + s);
}

void read_proc_status(char *status)
{
	FILE *fp;
	char one[200], two[200], three[200];

	fp = fopen(status, "r");

	while(!feof(fp)){
		fscanf(fp, "%s", one);
		if((strcmp("VmSize:", one)) == 0)
		{
			fscanf(fp, "%s", two);
			fscanf(fp, "%s", three);
			printf("%s %s %s\n", one, two, three);
		}
	}
}

void *p(void *data)
{
	char id[100], stat[100], status[100];

	printf("input id : ", id);
	scanf("%s", id);
	
	strcat(stat,"/proc/");
	strcat(stat, id);
	strcat(stat, "/stat");
	strcat(status,"/proc/");
	strcat(status, id);
	strcat(status, "/status");
	while(1){
		printf("%d in milisecond\n", read_proc_stat(stat));
		read_proc_status(status);
		sleep(2);
	}
}

int main(void)
{
	pthread_t p_thread;

	pthread_create(&p_thread, NULL, p, NULL);
	pthread_join(p_thread, NULL);

	return 0;
}
