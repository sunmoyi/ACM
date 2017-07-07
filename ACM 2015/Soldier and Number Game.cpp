#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5000010

using namespace std;

int num[maxn];
bool isprime[maxn];
int n, m, t, ans, cnt;

void init()
{
	memset(num, 0, sizeof(num));
	memset(isprime, true, sizeof(isprime));
	isprime[1] = false;
	for (int i = 2; i < maxn; i++)
	{
		if (isprime[i])
		{
			for (int j = i; j < maxn; j += i)
			{
				int temp = j;
				while (temp % i == 0)
				{
					num[j]++;
					temp /= i;
				}
				isprime[j] = false;
			}
		}
	}
	for (int i = 2; i < maxn; i++)
		num[i] = num[i] + num[i - 1];
}

int main(void)
{
	init();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", num[n] - num[m]);
	}
	return 0;
}
