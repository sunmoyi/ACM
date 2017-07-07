#include<iostream>
#include <queue>
using namespace std;

int main()
{
	int i, j, k, n;
	queue<int> q;
	while (scanf_s("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
			q.push(i);
		for (; q.size() > 1;)
		{
			k = q.front();
			printf("%d", k);
			q.pop();
			j = q.front();
			q.pop();
			q.push(j);
		}
		printf("%d ", q.front());
	}
}