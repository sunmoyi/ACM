#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int num, numm, a[105], minn, k;
	while (scanf("%d", &num) != EOF)
	{
		while (num--)
		{
			scanf("%d", &numm);
			for (int i = 1; i <= numm; i++)
				scanf("%d", &a[i]);
			sort(a + 1, a + numm + 1);
			minn = (a[numm] - a[1]) * 2;
			printf("%d\n", minn);
		}
	}
	return 0;
}