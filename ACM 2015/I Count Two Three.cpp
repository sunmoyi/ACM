#include<cstdio>
#include<cstring>
#include<algorithm>
#include <queue>
#include<stack>
#include<functional>

#define INF 1000000000

using namespace std;

int sum, n;
priority_queue<long long, vector<long long>, greater<long long> >Q;
long long num[100000], top = 0;;

int main(void)
{
	Q.push(1);
	long long temp = 0;
	while (temp < INF)
	{
		while (!Q.empty() && Q.top() == temp)
			Q.pop();
		temp = Q.top();
		Q.pop();
		num[top++] = temp;
		Q.push(temp * 2);
		Q.push(temp * 3);
		Q.push(temp * 5);
		Q.push(temp * 7);
	}
	for(int i = 0; i < top; i++)
		printf("%lld,", num[i]);
	while (scanf("%d", &sum) != EOF)
	{
		while (sum--)
		{
			scanf("%d", &n);
			int j = lower_bound(num, num + top, n) - num;
			printf("%d\n", num[j]);
		}
	}
	return 0;
}