#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 25010

using namespace std;

struct node {
	int A, B;
	node(int A = 0, int B = 0) :A(A), B(B){}
}num[maxn];
int t, sum;

bool cmp(node a, node b)
{
	return min(a.A, b.B) < min(a.B, b.A);
}

int main(void)
{
	while (scanf("%d", &sum) != EOF)
	{
		for (int i = 1; i <= sum; i++)
			scanf("%d %d", &num[i].A, &num[i].B);
		sort(num + 1, num + sum + 1, cmp);

		t = 0;
		for (int i = 1; i <= sum; i++)
		{
			num[i].A += num[i - 1].A;
			if (num[i].A > t)
				t = num[i].A;
			t += num[i].B;
		}
		printf("%d\n", t);
	}
	return 0;
}