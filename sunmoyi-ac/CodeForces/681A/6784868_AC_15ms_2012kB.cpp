#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum;
char name[500];
int price1, price2;

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		bool flag = false;
		while (sum--)
		{
			scanf("%s", name);
			scanf("%d %d", &price1, &price2);
			if (price1 >= 2400 && price2 > price1)
				flag = true;
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}