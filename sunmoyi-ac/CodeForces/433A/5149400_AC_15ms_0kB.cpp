#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int maxx, num[105];
int suma, sumb;
bool flag;

int main(void)
{
	while (scanf("%d", &maxx) != EOF)
	{
		suma = sumb = 0;
		flag = false;
		for (int i = 1; i <= maxx; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] == 100)
				suma++;
			else
				sumb++;
		}
		if (suma % 2 == 0 && suma != 0)
			flag = true;
		if (suma == 0 && sumb % 2 == 0)
			flag = true;
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}