#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, m;
	while (scanf_s("%d %d", &n, &m) != EOF && (n + m))
	{
		bool flag = false;
		while (true)
		{
			if (n > m)
			{
				int temp = n;
				n = m;
				m = temp;
			}

			if (m % n == 0)
				break;

			if (m - n > n)
				break;

			flag = !flag;
			m = m - n * (m / n);
		}
		if (!flag)
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}