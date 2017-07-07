#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a, b, ans;
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &a, &b);
			if (a % (b + 1))
				printf("Grass\n");
			else
				printf("Rabbit\n");
		}
	}
}