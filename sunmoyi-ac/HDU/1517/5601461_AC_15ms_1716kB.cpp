#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	double  ans;
	while (scanf("%lf", &ans) != EOF)
	{
		while (ans > 18)
			ans /= 18;
		if (ans <= 9)
			printf("Stan wins.\n");
		else
			printf("Ollie wins.\n");
	}
	return 0;
}