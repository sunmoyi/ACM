#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 15
using namespace std;

struct Matrix{
	int map[N][N];
};
int ans, k, m;
Matrix A;

Matrix Mul(Matrix &a, Matrix &b)
{
	Matrix c;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			c.map[i][j] = 0;
			for (int k = 0; k < m; k++)
				c.map[i][j] += a.map[i][k] * b.map[k][j];
			c.map[i][j] %= 9973;
		}
	}
	return c;
}

Matrix pow(int n)
{
	Matrix t;
	if (n == 1)
		return A;
	if (n & 1)
		return Mul(A, pow(n - 1));
	else
	{
		Matrix temp = pow(n >> 1);
		return Mul(temp, temp);
	}
}

int main(void)
{
	while (scanf_s("%d", &ans) != EOF)
	{
		while (ans--)
		{
			scanf_s("%d %d", &m, &k);
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < m; j++)
					scanf_s("%d", &A.map[i][j]);
			}

			Matrix temp = pow(k);
			int ss = 0;
			for (int i = 0; i < m; i++)
			{
				ss += temp.map[i][i];
				ss %= 9973;
			}
			printf("%d\n", ss);
		}
	}
	return 0;
}