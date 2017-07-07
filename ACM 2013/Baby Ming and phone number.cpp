#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num[100005][12];
int t, a, b, n;
int dayy[2][12] = { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

bool check1(char k[])
{
	if (k[7] == k[8] == k[9] == k[10])
		return true;
	else
		return false;
}

bool check2(char k[])
{
	int a1 = k[7] - k[8];
	int a2 = k[8] - k[9];
	int a3 = k[9] - k[10];
	if (a1 == 1 && a2 == 1 && a3 == 1)
		return true;
	else if (a1 == -1 && a2 == -1 && a3 == -1)
		return true;
	return false;
}

bool check3(char k[])
{
	int year = (k[3] - '0') * 1000 + (k[4] - '0') * 100 + (k[5] - '0') * 10 + (k[6] - '0');
	int month = (k[7] - '0') * 10 + (k[8] - '0') * 1000;
	int day = (k[9] - '0') * 10 + (k[10] - '0');
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		if (month <= 12 && month >= 1)
		{
			if (dayy[2][month] == day)
				return true;
		}
	}
	else
	{
		if (month <= 12 && month >= 1)
		{
			if (dayy[1][month] == day)
				return true;
		}
	}
	return false;
}

int main(void)
{
	while (scanf_s("%d", &t) != EOF)
	{
		while (t--)
		{
			long long sum = 0;
			bool flag = false;
			scanf_s("%d %d %d", &n, &a, &b);
			for (int i = 0; i < n; i++)
			{
				getchar();
				scanf_s("%s", num[i], 12);
				if (check1(num[i]))
					flag = true;
				if (check2(num[i]))
					flag = true;
				if (check2(num[i]))
					flag = true;
				if (flag)
					sum += a;
				else
					sum += b;
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}