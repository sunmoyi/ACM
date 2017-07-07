#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod (long long)1e9 + 7

using namespace std;

struct Matrix {
	long long a[4][4];
	void clear()
	{
		memset(a, 0, sizeof(a));
	}
	Matrix friend operator * (Matrix A, Matrix B)
	{
		Matrix C;
		C.clear();
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]);
					C.a[i][j] %= mod;
					//	C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
				}
			}
		}
		return C;
	}
	Matrix operator ^ (int n)
	{
		if (n == 1)
			return *this;
		Matrix ret = (*this) ^ (n / 2);
		ret = ret * ret;
		if (n & 1)
			ret = ret * (*this);
		return ret;
	}
};

int main (void)
{
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("0\n");
		return 0;
	}
	Matrix A;
	A.clear();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			A.a[i][j] = (i != j);
	Matrix B = A ^ (n);
	printf("%lld\n", B.a[0][0]);
}