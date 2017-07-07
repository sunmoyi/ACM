#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<time.h>
#include <windows.h>

const double PI = 3.14159265358979;

using namespace std;

int main(void)
{
	double j = 0;
	for (;;)
	{
		j += 0.1;
		long long sum = sin(j - ((int)(j / PI)) * PI) * 1e8;
		for (long long i = 0; i <= sum; i++);
		Sleep((1e8 - sum) / 1e8 * 100);
	}
	return 0;
}