#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char num[1005][505];
int sum;

int cmp(const void*elem1, const void *elem2)
{
	return(strcmp((char*)elem1, (char*)elem2));
}

bool bigger(int a, int b, int c)
{
	char kk[510];
	memset(kk, 0, sizeof(kk));
	int i = strlen(num[a]);
	int j =strlen(num[b]);
	int mark = 0;

	int s = i - 1, ss = j - 1, sss = 0;
	for (sss = 0; s >= 0 || ss >= 0 || mark != 0; s--, ss--, sss++)
	{
		kk[sss] = num[a][s] - '0' + num[b][ss] + mark;
		mark = 0;
		if (kk[sss] > '9')
		{
			kk[sss] -= 10;
			mark = 1;
		}
	}

	for (int t = 0; t < sss / 2; t++)
	{
		int temp = kk[t];
		kk[t] = kk[sss - t - 1];
		kk[sss - t - 1] = temp;
	}

	i = strlen(kk);
	j = strlen(num[c]);
	if (i > j)
		return true;
	else if (i < j)
		return false;
	for (int ss = i - 1; ss >= 0; ss--)
	{
		if (num[c][ss] < kk[ss])
			return true;
	}
	return false;
}

bool check(int a)
{
	bool flag = true;
	if (!bigger(a, a + 1, a + 2))
		flag = false;
	if (!bigger(a, a + 2, a + 1))
		flag = false;
	if (!bigger(a + 2, a + 1, a))
		flag = false;
	return flag;
}

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		getchar();
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= sum; i++)
		{
			scanf("%s", num[i]);
		}

		qsort(num + 1, sum, 504, cmp);

		bool flag = false;
		for (int i = 1; i <= sum - 2; i++)
		{
			if (check(i))
			{
				printf("%s %s %s\n", num[i + 2], num[i + 1], num[i]);
				flag = true;
				break;
			}
		}
		if (!flag)
			printf("0\n");
	}
	return 0;
}