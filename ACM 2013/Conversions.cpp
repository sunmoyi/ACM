#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int num;
double a;
char str[10];

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		for (int i = 1; i <= num; i++)
		{
			memset(str, 0, sizeof(str));
			scanf("%lf %s", &a, str);
			getchar();
			if (str[0] == 'k')
				printf("%d %.4lf lb\n", i, a * 2.2046);
			else if (str[0] == 'l' && str[1] == '\0')
				printf("%d %.4lf g\n", i, a * 0.2642);
			else if (str[0] == 'l' && str[1] == 'b')
				printf("%d %.4lf kg\n", i, a * 0.4536);
			else
				printf("%d %.4lf l\n", i, a * 3.7854);
		}
	}
	return 0;
}