#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[105];
char goalstr[55];

void a(char str[], int n, char goalstr[])
{
	int j = 0;
	for (int i = 0; i < n; i += 2)
		goalstr[j++] = str[i];
}

int main(void)
{
	while (scanf("%s", str) != EOF)
	{
		int len = strlen(str);
		a(str, len, goalstr);
		printf("%s\n", goalstr);
		printf("ËïÆôÁú 201507189 Èí¼þ153\n");
	}
	return 0;
}
