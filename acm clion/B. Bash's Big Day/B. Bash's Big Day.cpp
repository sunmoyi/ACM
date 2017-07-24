//
// Created by 孙启龙 on 2017/1/14.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int sum, a;
int num[10000000];
int used[10000000];
int ans[10000000];

int cal(void)
{
    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    for(int i = 2; i <= 100010; i++)
    {
        if(num[i] == 0)
        {
            if(used[i])
                ans[i] += used[i];
            for(int j = i * 2; j <= 100010; j += i)
            {
                ans[i] += used[j];
                num[j] = 1;
            }
        }
    }
}

int main (void)
{
   while(scanf("%d", &sum) != EOF)
   {
       memset(used, 0, sizeof(used));
       for(int i = 1; i <= sum; i++)
       {
           scanf("%d", &a);
           used[a]++;
       }

       cal();

       int maxx = 1;
       for(int i = 2; i <= 100010; i++)
           maxx = max(maxx, ans[i]);
       printf("%d\n", maxx);
   }
}