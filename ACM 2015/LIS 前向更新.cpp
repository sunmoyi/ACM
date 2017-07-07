#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1010

using namespace std;

int a[maxn];
int maxlen[maxn];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
		maxlen[i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			if (a[j] > a[i])
				maxlen[j] = max(maxlen[j], maxlen[i] + 1);
		}
	}
	cout << *max_element(maxlen + 1, maxlen + N + 1) << endl;
	return 0;
}