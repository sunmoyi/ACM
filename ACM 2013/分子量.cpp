#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	char num[1000];
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		double fin = 0;
		scanf("%s", num);
		int len = strlen(num);
		for (int i = 0; i < len;)
		{
			int sum = 0;
			if (num[i] == 'C')
			{
				while (num[++i] >= '0' && num[i] <= '9')
				{
					sum *= 10;
					sum += (num[i] - '0');
				}
				if (sum == 0)
					sum = 1;
				fin += sum * 12.01;
			}
			else if (num[i] == 'H')
			{
				while (num[++i] >= '0' && num[i] <= '9')
				{
					sum *= 10;
					sum += (num[i] - '0');
				}
				if (sum == 0)
					sum = 1;
				fin += sum * 1.008;
			}
			else if (num[i] == 'O')
			{
				while (num[++i] >= '0' && num[i] <= '9')
				{
					sum *= 10;
					sum += (num[i] - '0');
				}
				if (sum == 0)
					sum = 1;
				fin += sum * 16.00;
			}
			else if (num[i] == 'N')
			{
				while (num[++i] >= '0' && num[i] <= '9')
				{
					sum *= 10;
					sum += (num[i] - '0');
				}
				if (sum == 0)
					sum = 1;
				fin += sum * 14.01;
			}
		}
		printf("%.3lf\n", fin);
		}
	return 0;
}