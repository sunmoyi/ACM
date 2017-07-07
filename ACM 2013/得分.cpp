#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num[100];

int main(void)
{
	int n;
	scanf("%d", &n);

	getchar();
	while (n--)
	{
		scanf("%s", num);
		int len = strlen(num);
		int i = 0;
		long long fin = 0;
		for (int k = 0; k < len; k++)
		{
			if (num[k] == 'O')
			{
				i++;
				fin += i;
			}
			else
				i = 0;
		}
		printf("%lld\n", fin);
	}

	return 0;
}