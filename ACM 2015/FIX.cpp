#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 15 

using namespace std;

int sum;
char str1[1000], str2[10000], str3[10000];

bool a(char str1[], char str2[])
{
	if (strlen(str1) < strlen(str2))
	{
		for (int i = 0; i < strlen(str1); i++)
			if (str1[i] != str2[i])
				return true;
	}
	else
	{
		for (int i = 0; i < strlen(str2); i++)
			if (str1[i] != str2[i])
				return true;
	}
	return false;
}

bool b(char str1[], char str2[])
{
	if (strlen(str1) < strlen(str2))
	{
		for (int i = 0; i < strlen(str1); i++)
			if (str1[strlen(str1) - i - 1] != str2[strlen(str2) - i - 1])
				return true;
	}
	else
	{
		for (int i = 0; i < strlen(str2); i++)
			if (str1[strlen(str1) - i - 1] != str2[strlen(str2) - i - 1])
				return true;
	}
	return false;
}

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		getchar();
		while (sum--)
		{
			scanf("%s%s%s", str1, str2, str3);
			bool flag = true;
			if (!(a(str1, str2) && a(str2, str3) && a(str1, str3)))
				flag = false;
			if (!(b(str1, str2) && b(str2, str3) && b(str1, str3)))
				flag = false;
			if (flag)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}