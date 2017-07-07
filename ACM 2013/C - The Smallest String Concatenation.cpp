#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

int ans;
string str[50010];

bool cmp(string &a, string &b)
{
	return a + b < b + a;
}
int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		getchar();
		for (int i = 1; i <= ans; i++)
			getline(cin, str[i]);

		sort(str + 1, str + ans + 1, cmp);

		for (int i = 1; i <= ans; i++)
		{
			cout << str[i];
		}
		printf("\n");
	}
	return 0;
}