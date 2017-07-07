#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;
const ll mod = 2147493647;

struct matrix{
   ll arr[7][7];
   matrix operator* (matrix b)
   {
         matrix ans;
         ll tmp;
          for(int i = 0;i < 7;i++)
              for(int j = 0;j < 7;j++)
          {
                ans.arr[i][j] = 0;
                  for(int k = 0;k < 7;k++)
                  {
                      tmp = (arr[i][k]* b.arr[k][j])%mod;
                      ans.arr[i][j] = (ans.arr[i][j] + tmp)%mod;
                  }
          }
          return ans;
   }

};

matrix quick_pow(matrix a , ll N)
{
      matrix ans;
      memset(ans.arr , 0 , sizeof(ans.arr));
      for(int i = 0;i < 7;i++)
             ans.arr[i][i] = 1;

      while(N)
      {
            if(N&1)
                  ans = ans*a;
            a = a*a;
            N /= 2;
      }

      return ans;
}

int main(){

    matrix a;
    memset(a.arr,0,sizeof(a.arr));
    a.arr[0][1] = 1;
    a.arr[1][1] = a.arr[1][2] = a.arr[1][6] = 1;
    a.arr[2][2] = a.arr[2][6] = 1;
    a.arr[1][0] = 2; a.arr[1][3] = a.arr[1][5] = a.arr[2][3] = a.arr[2][5] = 4;
    a.arr[1][4] = a.arr[2][4] = 6;
    a.arr[3][3] = a.arr[4][4] = a.arr[5][5] = a.arr[6][6] = 1;
    a.arr[3][6] = a.arr[4][6] = a.arr[5][6] = 1;
    a.arr[3][4] = a.arr[3][5] = 3;
    a.arr[4][5] = 2;
    int T;
    scanf("%d",&T);
    ll N,aa,bb;
    while(T--){
        scanf("%I64d %I64d %I64d",&N,&aa,&bb);
        if(N==1)
            printf("%I64d\n",aa);
        else if(N==2)
            printf("%I64d\n",bb);
        else{
            matrix ans = quick_pow(a,N-2);
            ll ANS = 0;
            ANS = (ANS+ans.arr[1][0]*aa)%mod;
            ANS = (ANS+ans.arr[1][1]*bb)%mod;
            ANS = (ANS+ans.arr[1][2]*16)%mod;
            ANS = (ANS+ans.arr[1][3]*8)%mod;
            ANS = (ANS+ans.arr[1][4]*4)%mod;
            ANS = (ANS+ans.arr[1][5]*2)%mod;
            ANS = (ANS+ans.arr[1][6]*1)%mod;
            printf("%I64d\n",ANS);
        }
    }
    return 0;
}
