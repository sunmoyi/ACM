//
// Created by 孙启龙 on 2017/7/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;

struct Matrix
{
    int e[2][2];
    int* operator[](int p){
        return e[p];
    }
};

ll Mod;
Matrix operator *(Matrix &A, Matrix &B)
{
    Matrix R;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            R[i][j] = 0;
            for(int k = 0; k < 2; k++){
                R[i][j] = (R[i][j] + (ll)A[i][k]*B[k][j]+Mod)%Mod;
            }
        }
    }
    return R;
}

Matrix Matrix_pow(Matrix A,ll p)
{
    Matrix R;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            R[i][j] = i==j?1:0;
        }
    }
    while(p){
        if(p&1) R = R*A;
        A = A*A;
        p>>=1;
    }
    return R;
}

ll qPow(ll a,ll p,ll mod)
{
    ll ret = 1;
    while(p){
        if(p&1) ret = (ret*a)%mod;
        a = (a*a)%mod;
        p >>= 1;
    }
    return ret;
}

const int maxm = 46337+5;
int r[maxm],f[maxm];

int main()
{
    //freopen("in.txt","r",stdin);
    int T, kas = 0; scanf("%d",&T);
    while(T--){
        ll x; scanf("%I64d%I64d",&x,&Mod);
        if(!r[Mod]){
            f[0] = 2; f[1] = 10;
            for(int i = 2; ;i++){
                f[i] = (10LL*f[i-1]-f[i-2]+Mod)%Mod;
                if(f[i] == f[1] && f[i-1] == f[0]){ r[Mod] = i-1; break; }
            }
        }
        Matrix A;
        A[0][0] = 10%Mod; A[0][1] = Mod-1; A[1][0] = 1; A[1][1] = 0;
        auto ans = Matrix_pow(A,(qPow(2,x,r[Mod])+1)%r[Mod]);
        printf("Case #%d: %d\n",++kas,(ans[0][0]+ans[1][1]+Mod-1)%Mod);
    }
    return 0;
}