#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

int N, M;
int minArea = 1 << 30;
int area = 0;
int minV[30];
int minA[30];
int minNRH[30][30][30];

int MaxVforNRH(int n, int r, int h)
{
	int v = 0;
	for (int i = 0; i < n; ++i)
		v += (r - i) *(r - i) * (h - i);
	return v;
}

int dfs(int v, int n, int r, int h)
{
	if (n == 0) 
	{
		if (v) 
			return 0;
		else 
		{
			minArea = min(minArea, area);
			return 0;
		}
	}
	if (v <= 0)
		return 0;
	if (minV[n] > v) //��֦3
		return 0;
	if (area + minA[n] >= minArea) //��֦1
		return 0;
	if (h < n || r < n) //��֦2
		return 0;
	if (MaxVforNRH(n, r, h) < v) 
		//��֦4 //�����֦��ǿ��û�еĻ���5�붼��ʱ���еĻ���10ms���� 
		return -1; 
	//for( int rr = n; rr <= r; ++ rr ) ����д���ȴӴ�С��5�� 
	for( int rr = r; rr >=n; -- rr ) 
	{ 
		if( n == M ) //����� 
			area = rr * rr; 
		for( int hh = h; hh >= n ; --hh ) 
		{ 
			int a;
			area += 2 * rr * hh; 
			a = dfs(v - rr*rr*hh, n - 1, rr - 1, hh - 1);
			area -= 2 * rr * hh; 
			if (a == -1)
				break;
		} 
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	minV[0] = 0;
	minA[0] = 0;
	for (int i = 1; i <= M; i++)
	{
		minV[i] = minV[i - 1] + i * i * i;
		minA[i] = minA[i - 1] + 2 * i * i;
	}
	if (minV[M] > N)
		printf("0\n");
	else
	{
		int maxH = (N - minV[M - 1]) / (M * M) + 1;
		int maxR = sqrt((N - minV[M - 1]) / M * 1.0) + 1;
		area = 0;
		minArea = 1 << 30;
		dfs(N, M, maxR, maxH);
		if (minArea == 1 << 30)
			printf("0\n");
		else
			printf("%d\n", minArea);
	}
	return 0;
}