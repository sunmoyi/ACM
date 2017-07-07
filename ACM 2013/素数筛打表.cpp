#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
#define N 100000000
bool isprimer[N];
int pri[N], nprimer;

void doprime()
{
	long long i, j;
	nprimer = 0;
	memset(isprimer, true, sizeof(isprimer));
	isprimer[1] = 0; 
	for (i = 2; i < N; i++)
	{
		if (isprimer[i])
		{
			pri[++nprimer] = i;
			for (j = i * i; j < N; j += i)
				isprimer[j] = false;
		}
	}
}

int main(void)
{	
	return 0;
}