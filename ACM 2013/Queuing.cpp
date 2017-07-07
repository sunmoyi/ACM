#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Matrix{
	long long map[6][6];
};
Matrix matrix, b;
int n, k;

Matrix mul(Matrix &a, Matrix &b)
{
	Matrix c;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			c.map[i][j] = 0;
			for (int s = 0; s < 4; s++)
				c.map[i][j] += a.map[i][s] * b.map[s][j];
			c.map[i][j] %= k;
		}
	}
	return c;
}

Matrix pow(int n)
{
	if (n == 1)
		return matrix;
	if (n & 1)
		return mul(matrix, pow(n - 1));
	else
	{
		Matrix temp = pow(n >> 1);
		return mul(temp, temp);
	}
}

int main(void)
{
	memset(b.map, 0, sizeof(b.map));
	b.map[0][0] = 9; b.map[1][0] = 6; b.map[2][0] = 4; b.map[3][0] = 2;
	while (scanf_s("%d %d", &n, &k) != EOF)
	{
		memset(matrix.map, 0, sizeof(matrix.map));
		matrix.map[0][0] = 1;
		matrix.map[0][2] = 1;
		matrix.map[0][3] = 1;
		matrix.map[1][0] = 1;
		matrix.map[2][1] = 1;
		matrix.map[3][2] = 1;

		if (n == 0)
			printf("0\n");
		else if (n <= 4)
			printf("%lld\n", b.map[4 - n][0] % k);
		else
		{
			Matrix temp = pow(n - 4);
			temp = mul(temp, b);
			printf("%lld\n", temp.map[0][0] % k);
		}
	}
	return 0;
}