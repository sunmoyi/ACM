//
// Created by 孙启龙 on 2016/11/2.
//


#include <cstdio>
#include<cstring>

using namespace std;

typedef long long ll;
const int N = 7;
const ll MOD = 2147493647;

struct Matrix{
    ll ary[N][N];
    void init(){memset(ary,0,sizeof(ary));}
    Matrix(){init();}
};

Matrix multi(Matrix a,Matrix b){
    Matrix tmp;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                tmp.ary[i][j] = (tmp.ary[i][j]+a.ary[i][k]*b.ary[k][j])%MOD;
            }
        }
    }
    return tmp;
}

Matrix quick_pow(ll cnt){
    Matrix ans,base;
    base.ary[0][0] = 1;base.ary[0][1] = 2;base.ary[0][2] = 1;base.ary[0][3] = 4;base.ary[0][4] = 6;base.ary[0][5] = 4;base.ary[0][6] = 1;
    base.ary[1][0] = 1;base.ary[1][1] = 0;base.ary[1][2] = 0;base.ary[1][3] = 0;base.ary[1][4] = 0;base.ary[1][5] = 0;base.ary[1][6] = 0;
    base.ary[2][0] = 0;base.ary[2][1] = 0;base.ary[2][2] = 1;base.ary[2][3] = 4;base.ary[2][4] = 6;base.ary[2][5] = 4;base.ary[2][6] = 1;
    base.ary[3][0] = 0;base.ary[3][1] = 0;base.ary[3][2] = 0;base.ary[3][3] = 1;base.ary[3][4] = 3;base.ary[3][5] = 3;base.ary[3][6] = 1;
    base.ary[4][0] = 0;base.ary[4][1] = 0;base.ary[4][2] = 0;base.ary[4][3] = 0;base.ary[4][4] = 1;base.ary[4][5] = 2;base.ary[4][6] = 1;
    base.ary[5][0] = 0;base.ary[5][1] = 0;base.ary[5][2] = 0;base.ary[5][3] = 0;base.ary[5][4] = 0;base.ary[5][5] = 1;base.ary[5][6] = 1;
    base.ary[6][0] = 0;base.ary[6][1] = 0;base.ary[6][2] = 0;base.ary[6][3] = 0;base.ary[6][4] = 0;base.ary[6][5] = 0;base.ary[6][6] = 1;

    for(int i = 0; i < N; ++i)
        ans.ary[i][i] = 1;
    while(cnt){
        if(cnt&1)
            ans = multi(ans,base);
        cnt >>= 1;
        base = multi(base,base);
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n,a,b;
        scanf("%lld%lld%lld",&n,&a,&b);
        if(n == 1){
            printf("%lld\n",a);
            continue;
        }
        if(n == 2){
            printf("%lld\n",b);
            continue;
        }
        Matrix res;
        res.ary[0][0] = b;res.ary[1][0] = a;res.ary[2][0] = 16;res.ary[3][0] = 8;res.ary[4][0] = 4;res.ary[5][0] = 2;res.ary[6][0] = 1;
        Matrix ans = quick_pow(n-2);
        ans = multi(ans,res);
        printf("%lld\n",ans.ary[0][0]);
    }
    return 0;
}