#include<cstdio>
#include<cstring>
#include<algorithm>
const double esp = 1e-8;
using namespace std;

double sum = 0;
int i = 0;

int main(void)
{
	while (15 - sum > esp)
	{
		i++;
		sum += 1.0 / i;
		printf("%lf\n", sum);
	}
	printf("%d", i);
}