#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int ans;
	int year, month, dayy;
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d %d", &year, &month, &dayy);
			if ((month + dayy) % 2 == 0 || (dayy == 30) && (month == 9 || month == 11))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}