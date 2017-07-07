#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool check(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
int main(void)
{
	int num, year, month, dayy;
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%d-%d-%d", &year, &month, &dayy);
			if (month == 2 && dayy == 29)
			{
				printf("-1\n");
				continue;
			}
			else
			{
				int sum = 365 * 18;
				for (int i = 1; i <= 17; i++)
					if (check(year + i))
						sum++;
				if (check(year) && (month < 2 || (month == 2 && dayy <= 29)))
					sum++;
				if (check(year + 18) && (month > 2))
					sum++;
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}
