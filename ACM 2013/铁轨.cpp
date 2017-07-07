#include<cstdio>
#include<stack>
using namespace std;
const int maxn = 1000 + 10;

int n, target[maxn];

int main(void)
{
	while (scanf_s("%d", &n) == 1)
	{
		stack<int> s;
		int a = 1, b = 1;
		for (int i = 1; i <= n; i++)
			scanf_s("%d", &target[i]);
		int ok = 1; 
		while (b <= n)
		{
			if (a == target[b])
			{
				a++;
				b++;
			}
			else if (!s.empty() && s.top() == target[b])
			{
				s.pop;
				b++;
			}
			else
			{
				ok = 0;
				break;
			}
		}
		printf("%s\n", ok ? "Yes" : "No");
	}
	return 0;
}