#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int len, i, j, k, t;
	char str[100];
	while (scanf_s("%d", &t) != EOF)
	{
		getchar();
		for (k = 1; k <= t; k++)
		{
			scanf_s("%s", str, 99);
			getchar();
			len = strlen(str);
			printf("String #%d\n", k);
			for (i = 0; i < len; i++)
			{
				if (str[i] != 'Z')
					printf("%c", str[i] + 1);
				else
					printf("A");
			}
			printf("\n\n");
		}
	}
	return 0;
}