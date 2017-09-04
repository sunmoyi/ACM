//
// Created by 孙启龙 on 2017/8/8.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 1000000007

using namespace std;

struct Matrix{
    int r, c;
    long long matrix[16][16];
    Matrix(int r = 0, int c = 0): r(r), c(c){memset(matrix, 0, sizeof(matrix));}

    friend Matrix operator * (Matrix A, Matrix B){
        Matrix C(A.r, A.c);
        for(int i = 1; i <= A.r; i++)
            for(int j = 1; j <= B.c; j++)
                for(int k = 1; k <= A.c; k++)
                    (C.matrix[i][j] += (A.matrix[i][k] * B.matrix[k][j])%mod)%= mod;
        return C;
    }

    friend Matrix operator ^ (Matrix A, long long m)
    {
        Matrix ans(A.r, A.c);
        for(int i = 1; i <= A.r; i++)
            ans.matrix[i][i] = 1;
        while(m)
        {
            if(m & 1)
                ans = ans * A;
            m /= 2;
            A = A * A;
        }
        return ans;
    }
};
long long C[15][15];

void GetC()
{
    C[0][0] = 1;
    for(int i = 1; i <= 13; i++)
        for(int j = 0; j <= i; j++)
            C[i][j] = (j == 0)? 1: (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}

long long pow(long long n, long long m) {
    long long ans = 1;
    n %= mod;
    while(m)
    {
        if(m & 1)
            ans = ((ans * n) % mod);
        m /= 2;
        n = (n * n) % mod;
    }
    return ans;
}

int main (void)
{
    GetC();
    long long n, k;
    scanf("%lld %lld", &n, &k);
    if(n == 1)
    {
        printf("1\n");
        return 0;
    }

    Matrix A(k + 2, k + 2);
    A.matrix[1][1] = 2;
    for (int i = 2; i <= A.c; i++)
        A.matrix[2][i] = A.matrix[1][i] = C[k][i - 2];
    for (int i = 3; i <= A.r; i++)
        for (int j = i; j <= A.c; j++)
            A.matrix[i][j] = C[A.r - i][j - i];

    Matrix x2(A.r, 1), xn;
    for(int i = 1; i <= x2.r; i++)
        x2.matrix[i][1] = 1;
    xn = (A ^ (n - 2)) * x2;
    long long ans = xn.matrix[1][1] + pow(n, k);
    printf("%lld\n", ans % mod);
}