#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[1000005];

int uptimes(char a)
{
	int sum1 = 0;
	int sum2 = 0;
	sum1 = 'z' - a; 
	sum2 = a - 'a';
	return max(abs(sum1), abs(sum2));
}

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &a, &b) != EOF)
	{
		scanf_s("%s", str, 1000004); 
		int len = strlen(str);
		int ans = 0;
		for (int i = 0; i < len; i++)
		{
			ans += uptimes(str[i]);
		}
		if (ans < b)
			printf("-1\n");
		else
		{
			int i;
			for (i = 0; i < len; i++)
			{
				int ss = uptimes(str[i]);
				if (b >= ss)
				{
					if (abs('z' - str[i]) == ss)
						printf("z");
					else
						printf("a");
					b -= ss;
				}
				else
				{
					if (str[i] + b > 'z')
						printf("%c", str[i] - b);
					else
						printf("%c", str[i] + b);
					break;
				}
			}
			for (i++; i < len; i++)
				printf("%c", str[i]);
			printf("\n");
		}
	}
	return 0;
}