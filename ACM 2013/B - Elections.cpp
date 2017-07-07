#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int main(void)
{
	int from[9], goal[9];
	for (int i = 0; i < 9; i++)
		scanf_s("%d", &from[i]);
	for (int i = 0; i < 9; i++)
		scanf_s("%d", &goal[i]);
	int k =memcmp(from, goal,  sizeof(from));
	//printf("%d", sizeof(int));
	printf("%d",k);
	return 0;
}