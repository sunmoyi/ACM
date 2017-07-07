#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int daysy[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int daysf[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int syear, smonth, day, eyear, emonth;
int sum1, sum2, num;

int check(int year, int month, int day)
{
	if (month == 1 || month == 2)//ÅĞ¶ÏmonthÊÇ·ñÎª1»ò2¡¡
	{
		year--;
		month += 12;
	}
	int c = year / 100;
	int y = year - c * 100;
	if (year * 10000 + month * 100 + day <= 15821004)
	{
		int week = (c / 4) - 2 * c + (y + y / 4) + (13 * (month + 1) / 5) + day + 2;
		while (week < 0) { week += 7; }
		week %= 7;
		return week;
	}
	else
	{
		int week = (c / 4) - 2 * c + (y + y / 4) + (13 * (month + 1) / 5) + day - 1;
		while (week < 0) { week += 7; }
		week %= 7;
		return week;
	}
}

int main(void)
{
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			sum1 = sum2 = 0;
			scanf("%d %d %d %d", &syear, &smonth, &eyear, &emonth);
			if (syear == eyear)
			{
				for (int i = smonth; i <= emonth; i++)
				{
					int ans = check(syear, i, 1);
					if (ans == 0 || ans == 1 || ans == 6)
						sum2++;
					if (
						(eyear < 1582 && (eyear & 4) == 0 )
						|| eyear == 1700
						|| (eyear >= 1582 && (((0 == eyear % 4) && (0 != eyear % 100)) || (0 == eyear % 400)))
						)
					{
						ans = check(syear, i, daysy[i]);
						if (ans == 5 || ans == 6 || ans == 0)
							sum1++;
					}
					else
					{
						ans = check(syear, i, daysf[i]);
						if (ans == 5 || ans == 6 || ans == 0)
							sum1++;
					}
				}
			}
			else
			{
				for (int i = smonth; i <= 12; i++)
				{
					int ans = check(syear, i, 1);
					if (ans == 0 || ans == 1 || ans == 6)
						sum2++;
					if (
						(syear < 1582 && (syear & 4) == 0)
						|| (syear == 1700)
						|| (syear >= 1582 && (((0 == syear % 4) && (0 != syear % 100)) || (0 == syear % 400)))
						)
					{
						ans = check(syear, i, daysy[i]);
						if (ans == 5 || ans == 6 || ans == 0)
							sum1++;
					}
					else
					{
						ans = check(syear, i, daysf[i]);
						if (ans == 5 || ans == 6 || ans == 0)
							sum1++;
					}
				}
				for (int i = syear + 1; i < eyear; i++)
				{
					for (int j = 1; j <= 12; j++)
					{
						int ans = check(i, j, 1);
						if (ans == 0 || ans == 1 || ans == 6)
							sum2++;
						if (
							(i < 1582 && (i & 4) == 0)
							|| i == 1700
							|| (i >= 1582 && (((0 == i % 4) && (0 != i % 100)) || (0 == i % 400)))
							)
						{
							ans = check(i, j, daysy[j]);
							if (ans == 5 || ans == 6 || ans == 0)
								sum1++;
						}
						else
						{
							ans = check(i, j, daysf[j]);
							if (ans == 5 || ans == 6 || ans == 0)
								sum1++;
						}
					}
				}
				for (int i = 1; i <= emonth; i++)
				{
					int ans = check(eyear, i, 1);
					if (ans == 0 || ans == 1 || ans == 6)
						sum2++;
					if (
						(eyear < 1582 && (eyear & 4) == 0 )
						|| eyear == 1700
						|| (eyear >= 1582 && (((0 == eyear % 4) && (0 != eyear % 100)) || (0 == eyear % 400)))
						)
					{
						ans = check(eyear, i, daysy[i]);
						if (ans == 5 || ans == 6 || ans == 0)
							sum1++;
					}
					else
					{
						ans = check(eyear, i, daysf[i]);
						if (ans == 5 || ans == 6 || ans == 0)
							sum1++;
					}
				}
			}
			printf("%d %d\n", sum1, sum2);
		}
	}
	return 0;
}