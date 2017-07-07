#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char pass[100];

bool isvowels(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	return false;
}

bool test1(void)
{
	int cnt = 0;
	for (int i = 0; i < strlen(pass); i++)
		if (isvowels(pass[i]))
			cnt++;
	if (cnt == 0)
		return false;
	return true;
}

bool test2(void)
{
	for (int i = 0; i + 2< strlen(pass); i++)
	{
		if (isvowels(pass[i]) && isvowels(pass[i + 1]) && isvowels(pass[i + 2]))
			return false;
		if (!isvowels(pass[i]) && !isvowels(pass[i + 1]) && !isvowels(pass[i + 2]))
			return false;
	}
	return true;
}

bool test3(void)
{
	for (int i = 0; i + 1< strlen(pass); i++)
	{
		if (pass[i] == pass[i + 1] && pass[i] != 'e' && pass[i] != 'o')
			return false;
	}
	return true;
}

bool test(void)
{
	if (!test1())
		return false;
	if (!test2())
		return false;
	if (!test3())
		return false;
	return true;
}
int main(void)
{
	while (scanf("%s", pass) != EOF)
	{
		if (!strcmp(pass, "end"))
			break;
		if (test())
			printf("<%s> is acceptable.\n", pass);
		else
			printf("<%s> is not acceptable.\n", pass);
	}
	return 0;
}