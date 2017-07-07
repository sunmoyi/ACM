#include<cstdio>
#include<cstring>
#include<algorithm>
#define yearrun 53
#define yearnorun 52

using namespace std;

int ans;
int year1, month1, dayy1;
int year2, month2, dayy2;
int datrun[13] = { 0,0,10,11,0,11,0,11,0,0,0,10,0 };
int datnorun[13] = { 0,0,9,11,0,11,0,11,0,0,0,10,0 };
bool prime[32] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1 };
int sumnorun[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool check(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	return false;
}

int main(void)
{
	while (scanf("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf("%d %d %d", &year1, &month1, &dayy1);
			scanf("%d %d %d", &year2, &month2, &dayy2);
			int sum = 0;
			for (int i = year1 + 1; i <= year2 - 1; i++)
			{
				if (check(i))
					sum += yearrun;
				else
					sum += yearnorun;
			}
			if (year1 == year2 && check(year1))
			{
				for (int j = month1 + 1; j <= month2 - 1; j++)
					sum += datrun[j];
			}
			else if (year1 == year2 && !check(year1))
			{
				for (int j = month1 + 1; j <= month2 - 1; j++)
					sum += datnorun[j];
			}
			else 
			{
				if (check(year1))
				{
					for (int i = month1 + 1; i <= 12; i++)
						sum += datrun[i];
				}
				else
				{
					for (int i = month1 + 1; i <= 12; i++)
						sum += datnorun[i];
				}
				if (check(year2))
				{
					for (int i = 1; i <= month2 - 1; i++)
						sum += datrun[i];
				}
				else
				{
					for (int i = 1; i <= month2 - 1; i++)
						sum += datnorun[i];
				}
			}
			if (year1 == year2 && month1 == month2)
			{
				if (prime[month1])
				{
					for (int i = dayy1; i <= dayy2; i++)
						if (prime[i])
							sum++;
				}
			}
			else
			{
				if (prime[month1])
				{
					for (int i = dayy1; i <= sumnorun[month1]; i++)
						if (prime[i])
							sum++;
					if (check(year1) && month1 == 2)
						sum++;
				}
				if (prime[month2])
				{
					for (int i = 1; i <= dayy2; i++)
						if (prime[i])
							sum++;
				}
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}