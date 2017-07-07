#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

char str[maxn];
int num;

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		getchar();
		scanf("%s", str);
		num = 1;
		for (int i = 0; str[i + 1] != 0; i++)
			if (str[i] != str[i + 1])
				num++;
		printf("%d\n", min(num + 2, (int)strlen(str)));
	}
	return 0;
}