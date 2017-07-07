#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int sum_of_cup, sum_of_medals, times;
	int a, b, c, sum;
	while (scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		sum_of_cup = a + b + c;
		scanf("%d %d %d", &a, &b, &c);
		sum_of_medals = a + b + c;
		scanf("%d", &times);
		sum = sum_of_cup / 5 + sum_of_medals / 10;
		if (sum_of_cup % 5 != 0)
			sum++;
		if (sum_of_medals % 10 != 0)
			sum++;
		if (sum <= times)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}