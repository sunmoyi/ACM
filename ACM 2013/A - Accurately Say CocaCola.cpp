#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int num = 0;
	for (int i = 1; i <= 3000; i++)
	{
		int t = i;
		if (i % 7 == 0)
		{
			printf("%d %d\n", i, i - num);
			num = i;
		}
		else
		{
			while (t > 0)
			{
				if (t % 10 == 7)
				{
					printf("%d %d\n", i, i - num);
					num = i;
					break;
				}
				t /= 10;
			}
		}
	}
	return 0;
}