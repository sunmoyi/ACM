#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Vex{
	int vex;
	int lenth;
	int price;
};

vector<Vex> G[10];

int main(void)
{
	int N, M;
	int v1;
	Vex v;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &v1, &v.vex, &v.lenth, &v.price);
		G[v1].push_back(v);
	}
	for (int i = 1; i <= N; i++)
	{
		printf("G[%d]:\n", i);
		for (int j = 0; j < G[i].size(); j++)
			printf("%d %d %d\n", G[i][j].vex, G[i][j].lenth, G[i][j].price);
		printf("\n");
	}
	return 0;
}