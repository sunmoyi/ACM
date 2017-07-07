#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int phh[10010];

void  phi()
{
	for (int i = 1; i <= 10000; i++)
		phh[i] = i;
	for (int i = 2; i <= 10000; i += 2)
		phh[i] /= 2;
	for (int i = 3; i <= 10000; i += 2)
	{
		if (phh[i] == i)
		{
			for (int j = i; j <= 10000; j += i)
			{
				phh[j] = phh[j] / i * (i - 1);
			}
		}
	}
}

int main(void)
{
	phi();
	for (int i = 1; i <= 10000; i++)
	{
		printf("%d %d\n", i, phh[i]);
	}
	return 0;
}