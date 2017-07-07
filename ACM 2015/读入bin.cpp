#include<stdio.h>

int main(void)
{
	double temp;
	FILE *fp = fopen("bin.dat", "w");
	/****************input************************/
	for (int i = 1; i <= 5; i++)
	{
		scanf("%lf", &temp);
		fprintf(fp, "%lf\n", temp);
	}
	/*******************output**************************/
	for (int i = 1; i <= 5; i++)
	{
		fscanf(fp, "%lf", &temp);
		printf("%d: %lf\n", i, temp);
	}
	fclose(fp);
	return 0;
}