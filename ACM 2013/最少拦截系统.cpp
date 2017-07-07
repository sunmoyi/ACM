#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int k[1000000];
int lanjie[1000000];

int main(void)
{
	while (scanf_s("%d", &n) != EOF)
	{
		memset(k, 0, sizeof(k));
		memset(lanjie, 0, sizeof(lanjie));
		for (int i = 0; i < n; i++)
			scanf_s("%d", &k[i]);
		int t = 0;
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			for (j = 0; j < t; j++)
			{
				if (lanjie[j] > k[i])
				{
					lanjie[j] = k[i];
					break;
				}

			}
			if (j == t)
			{
				t++;
				lanjie[j] = k[i];
			}
			sort(lanjie, lanjie + t);
		}
		printf("%d\n", t);
	}
	return 0;
}