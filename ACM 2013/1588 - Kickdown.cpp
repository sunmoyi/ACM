#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool test(int k, char s1[], char s2[])
{
	for (int i = 0; s1[k + i] && s2[i]; i++)
		if (s1[k + 1] + s2[k] - 2 * '0' > 3)
			return false;
	return true;
}

int fun(char s1[], char s2[])
{
	int k = 0;
	while (!test(k, s1, s2))
		k++;
	return max(strlen(s1), strlen(s2) + k);
}

int main(void)
{
	char bottom[105], top[105];
	while (scanf("%s %s", bottom, top) != EOF)
	{
		printf("%d\n", min(fun(bottom, top), fun(top, bottom)));
	}
	return 0;
}