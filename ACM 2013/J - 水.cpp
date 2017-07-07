#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, num;

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%d %d", &n, &m);
			if (n % (m + 1) == 0)
				printf("Rabbit\n");
			else
				printf("Grass\n");
		}
	}
	return 0;
}