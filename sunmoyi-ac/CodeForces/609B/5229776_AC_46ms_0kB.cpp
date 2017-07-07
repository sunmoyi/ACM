#include<cstdio>
#include<cstring>

using namespace std;

int k[15];

int main (void)
{
	int a, b, c;
	while(scanf("%d %d", &a, &b) != EOF)
	{
		memset(k, 0, sizeof(k));
		for(int i = 1; i <= a; i++)
		{
			scanf("%d", &c);
			k[c]++;
		}
		int num = 0;
		for(int i = 1; i < b; i++)
		{
			for(int j = i + 1; j <= b; j++)
			{
				num += k[i] * k[j];
			}
		}
		printf("%d\n", num);
	}
	return 0;
}