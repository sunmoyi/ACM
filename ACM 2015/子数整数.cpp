#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num1, num2, num3;
int ans;

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		bool flag = false;
		for (int i = 10000; i <= 30000; i++)
		{
			int temp = i;
			num1 = num2 = num3 = 0;
			num3 = temp % 1000;
			temp /= 10;
			num2 = temp % 1000;
			temp = i / 100;
			num1 = temp % 1000;
			//printf("%d %d %d\n", num1, num2, num3);
			if (num1 % ans)
				continue;
			if (num2 % ans)
				continue;
			if (num3 % ans)
				continue;
			printf("%d\n", i);
			flag = true;
		}
		if (!flag)
			printf("No\n");
	}
	return 0;
}