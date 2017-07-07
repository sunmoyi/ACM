#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

char str[maxn];

int main(void)
{
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		str[1] = ch;
		int i = 1;
		while (scanf("%c", &ch) && ch != '\n')
			str[++i] = ch;
		str[0] = str[i];
		int die = 0, live = 0, sum = 0;;
		for (int j = 0; j < i; j++)
		{
			if (str[j] == '0' && str[j + 1] == '0')
				live++, sum++;
			else if (str[j] == '0' && str[j + 1] == '1')
				die++, sum++;
		}
		double shoot = live * 1.0 / sum;
		double rotate = sum * 1.0 / i;
		if (shoot < rotate)
			printf("ROTATE\n");
		else if (shoot > rotate)
			printf("SHOOT\n");
		else
			printf("EQUAL\n");
	}
	return 0;
}