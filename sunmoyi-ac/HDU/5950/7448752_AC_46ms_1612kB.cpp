#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int maxn = 20;
typedef long long Matrix[maxn][maxn];
typedef long long Vector[maxn];

int sz ;
long long mod = 2147493647;
void matrix_mul(Matrix A , Matrix B , Matrix res)//矩阵A*B = C , O(n^3).矩阵均为同阶方阵
{
     Matrix C;
     memset(C , 0 , sizeof(C));
     for(int i = 0;i < sz;i++)
          for(int j = 0;j < sz; j++)
             for(int k = 0;k < sz; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j])%mod;

     memcpy(res , C , sizeof(C));
}
void matrix_pow(Matrix A , int n , Matrix res)//矩阵快速幂O(logn)
{
    Matrix a , r;
    memcpy(a , A , sizeof(a));
    memset(r , 0 , sizeof(r));
    for(int i = 0;i < sz;i++)  r[i][i] = 1;//单位矩阵
    while(n){
        if(n&1)  matrix_mul(r , a , r);
        n >>= 1;
        matrix_mul(a , a , a);
    }
    memcpy(res , r , sizeof(r));
}

void Transform(Vector d , Matrix A , Vector res)//计算完A^(n-d)之后，这个函数计算A*d = res
{
     Vector r;
     memset(r , 0 , sizeof(r));
     for(int i = 0;i < sz;i++)
          for(int j = 0;j < sz;j++)
              r[i]  = (r[i] + d[j] * A[i][j])%mod;

     memcpy(res , r , sizeof(r));
}

int main()
{
    long long n , a , b;

     int t;
     cin>>t;
    while(t--)
    {
       cin>>n>>a>>b;
      sz = 7;             //矩阵A的规模是sz
      Vector  f;
      if(n == 1) {cout<<a<<endl;continue;}
      if(n == 2) {cout<<b<<endl;continue;}
         f[0] = b;f[1] = a;
         f[2] = 16;f[3] = 8;f[4] = 4;f[5] = 2;f[6] = 1;

     Matrix A;
     memset(A , 0 , sizeof(A));//注意每次矩阵A的参数都要初始化.
     A[0][0] = 1;A[0][1] = 2;A[0][2] = 1;A[0][3] = 4;A[0][4] = 6;A[0][5] = 4;A[0][6] = 1;
     A[1][0] = 1;
     A[2][2] = 1;A[2][3] = 4;A[2][4] = 6;A[2][5] = 4;A[2][6] = 1;
     A[3][3] = 1;A[3][4] = 3;A[3][5] = 3;A[3][6] = 1;
     A[4][4] = 1;A[4][5] = 2;A[4][6] = 1;
     A[5][5] = 1;A[5][6] = 1;
     A[6][6] = 1;

         matrix_pow(A , n - 2 , A);
         Transform(f , A , f);

         cout << f[0] << endl;
    }
    return 0;
}
