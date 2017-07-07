#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[100010];
int lena[100010];
int costa[100010];
int lenb[100010];
int costb[100010];
int n, m;

int main(void)
{
	while (scanf_s("%d %d", &n, &m) != EOF)
	{
		getchar();
		scanf_s("%s", str, 100005);
		memset(lena, 0, sizeof(lena));
		memset(lenb, 0, sizeof(lenb));

		int sitea = 0;//奇数是获得  偶数是花费
		if (str[0] == 'a')
			sitea = 1;
		int j = 0;
		while (j < n)
		{
			char c = str[j];
			int num = 0;
			while (c == str[j] && j < n)
			{
				num++;
				j++;
			}
			lena[sitea++] = num;
		}
		if ((sitea % 2))
			sitea++;

		int siteb = 0;//奇数是获得  偶数是花费
		if (str[0] == 'b')
			siteb = 1;
		j = 0;
		while (j < n)
		{
			char c = str[j];
			int num = 0;
			while (c == str[j] && j < n)
			{
				num++;
				j++;
			}
			lenb[siteb++] = num;
		}
		if ((siteb % 2))
			siteb++;

		int cost, spend = 0, get, reget;
		int endd = 0, start = 0;
		int final1 = 0;
		int maxx = -10000;

		while (endd < sitea)
		{
			cost = lena[endd];
			get = lena[endd] + lena[endd + 1];
			if (spend + cost <= m)
			{
				spend += cost;
				final1 += get;
				endd += 2;
				maxx = max(maxx, final1);
			}
			else
			{
				reget = 0;
				while (reget + m - spend < lena[endd])
				{
					reget += lena[start];
					final1 -= lena[start];
					if (start - 1 > 0)
						final1 -= lena[start - 1];
					start += 2;
				}
				spend -= reget;
				spend += lena[endd];
				final1 += (lena[endd] + lena[endd + 1]);
				endd += 2;
				maxx = max(maxx, final1);
			}
		}


		cost = 0, spend = 0, get = 0, reget = 0;
		endd = 0, start = 0;
		int final2 = 0;

		while (endd < siteb)
		{
			cost = lenb[endd];
			get = lenb[endd] + lenb[endd + 1];
			if (spend + cost <= m)
			{
				spend += cost;
				final2 += get;
				endd += 2;
				maxx = max(maxx, final2);
			}
			else
			{
				reget = 0;
				while (reget + m - spend < lenb[endd])
				{
					reget += lenb[start];
					final2 -= lenb[start];
					if (start - 1 > 0)
						final2 -= lenb[start - 1];
					start += 2;
				}
				spend -= reget;
				spend += lenb[endd];
				final2 += (lenb[endd] + lenb[endd + 1]);
				endd += 2;
				maxx = max(maxx, final2);
			}
		}
		printf("%d\n", maxx);
	}
	return 0;
}