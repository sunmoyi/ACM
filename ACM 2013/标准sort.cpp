#include <cstdio>
#include <time.h>
#include<algorithm>
#include<Windows.h>

using namespace std;

int num1[10000010], num2[10000010], num3[10000010], num4[10000010], num5[10000010];

int main()
{
	DWORD start, stop;
	for (int i = 0; i < 10000000; i++)
	{
		num1[i] = (10000000 - i);
		num2[i] = (10000000 - i);
		num3[i] = (10000000 - i);
		num4[i] = (10000000 - i);
		num5[i] = (10000000 - i);
	}
	start = GetTickCount();
	sort(num1, num1 + 10000000);
	stop = GetTickCount();
	printf("time: %d ms\n", stop - start);

	start = GetTickCount();
	sort(num2, num2 + 10000000);
	stop = GetTickCount();
	printf("time: %d ms\n", stop - start);

	start = GetTickCount();
	sort(num3, num3 + 10000000);
	stop = GetTickCount();
	printf("time: %d ms\n", stop - start);

	start = GetTickCount();
	sort(num4, num4 + 10000000);
	stop = GetTickCount();
	printf("time: %d ms\n", stop - start);

	start = GetTickCount();
	sort(num5, num5 + 10000000);
	stop = GetTickCount();
	printf("time: %d ms\n", stop - start);

	return 0;
}
