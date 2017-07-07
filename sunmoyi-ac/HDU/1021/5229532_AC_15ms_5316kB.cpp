#include<cstdio>

using namespace std;

int fin[1000005];

int main (void)
{
	fin[0] = 1;
	fin[1] = 2;
	for(int i = 2; i <= 1000000; i++)
	{
		fin[i] = (fin[i - 1] + fin[i - 2]) % 3;
	}
	int num;
	while(scanf("%d", &num) != EOF)
	{
		if(fin[num] == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}