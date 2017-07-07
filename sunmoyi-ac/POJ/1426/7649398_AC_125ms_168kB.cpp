#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool found;
int n;

void DFS(unsigned __int64 t, int k)
{
	if (found)
		return;
	if (t%n == 0)
	{
		printf("%I64u\n", t);
		found = true;
		return;
	}
	if (k == 19)
		return;
	DFS(t * 10, k + 1);    
	DFS(t * 10 + 1, k + 1);    
}
int main()
{
	while (scanf_s("%d", &n) != EOF && n)
	{
		found = false;
		DFS(1, 0);    
	}
	return 0;
}