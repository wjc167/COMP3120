#include <stdlib.h> 
#include <stdio.h>

int main()
{
	int a;

	char test[100];
	FILE *fp;
	FILE *fp1;

	fp = fopen("in.txt", "r");
	fp1 = fopen("out.txt", "w");
	
	fscanf(fp, "%s", test);
	fprintf(fp1, "%s", test);
	
	fclose(fp);
	fclose(fp1);
	return 0;
} 
