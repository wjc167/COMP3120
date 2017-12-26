#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	struct timeval mytime;

	gettimeofday(&mytime, NULL);
	printf("%1dsecond:%1dmicro second\n", mytime.tv_sec, mytime.tv_usec);
	printf("%1d:%1d:%1d\n", (mytime.tv_sec/60/24%24)-1, mytime.tv_sec/60%60, mytime.tv_sec%60);

	return 0;
}
