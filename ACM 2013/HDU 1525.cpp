#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int a, b;
	while (scanf_s("%d %d", &a, &b) != EOF && (a + b))
	{
		bool flag = true;
		if (a > b)
		{
			int t = a;
			a = b;
			b = t;
		}
		while (1)
		{
			if (b == 0 || b / a > 1 || a % b == 0)
				break;
			b = b - a;
			int t;
			t = b;
			b = a;
			a = t;
			flag = !flag;
		}
		if (flag)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}