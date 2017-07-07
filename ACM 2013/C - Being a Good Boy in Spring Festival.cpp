#include<cstdio>

using namespace std;

int num[107];

int main(void)
{
	int ans = 1;
	while (scanf_s("%d", &ans) != EOF && ans)
	{
		for (int i = 1; i <= ans; i++)
			scanf_s("%d", &num[i]);
		int s = 0;
		for (int i = 1; i <= ans; i++)
		{
			int kk = 0;
			for (int j = 1; j <= ans; j++)
			{
				if (j != i)
					kk ^= num[j];
			}
			if (kk < num[i])
				s++;
		}
		printf("%d\n", s);
	}
	return 0;
}