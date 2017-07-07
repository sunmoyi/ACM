#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int year, month, dayy, ans;
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d %d", &year, &month, &dayy);
			if ((month + dayy) % 2 == 1 && ((dayy != 30) || (month != 9) && (month != 11)))
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}