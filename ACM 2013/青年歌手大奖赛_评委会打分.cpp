# include <stdio.h>
int main (void)
{
	int score[100], max , min, n , i, sum;
	float average;
	while(scanf("%d", &n) !=EOF)
	{
		max = 0;min = 10000;sum = 0;
		for(i = 0 ;i <= n-1 ; i++)
		{
			scanf("%d", &score[i]);
			if(score[i] > max)
				max = score[i];
			if(score[i] < min)
				min = score[i];
			sum = sum + score[i];
		}
		sum = sum - min - max;
		average = (float)sum/(n - 2);
		printf("%.2lf\n", average);

	}
	return 0;
}