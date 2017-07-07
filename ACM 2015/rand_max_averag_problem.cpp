/*#include<cstdio>
#include<cstring>
#include<algorithm>
#include<time.h>
#define mod 100000

using namespace std;

int main(void)
{
	srand((unsigned)time(NULL));
	FILE * fp = fopen("input5.txt", "w");
	for (int t = 1; t <= 50; t++)
	{
		
		int n = rand() % mod;
		if(n <= 90000)
			n = rand() % mod;
		int k = rand() % (mod / 3);
		while (k >= n)
			k = rand() % mod;


		fprintf(fp, "%d %d\n", n, k);
		for (int i = 1; i <= n; i++)
		{
			fprintf(fp, "%d ", rand() % 2001);
		}
		fprintf(fp, "\n");
	}
	return 0;
}*/