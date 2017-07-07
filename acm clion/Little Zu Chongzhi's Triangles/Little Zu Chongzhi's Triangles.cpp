//
//Created by 孙启龙 2016/11/06
//

#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n,kase = 0,vis[1<<13];
double a[13],d[1<<13];

bool issan(double a, double b, double c)
{
    if(a + b > c && a + c > b && b + c > a)
        return true;
    return false;
}

double Sa(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    double ans = sqrt((a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))/4.0;
    return ans;
}

double dp(int S)
{
    double& ans = d[S];
    if(vis[S] == kase)
        return ans;
    vis[S] = kase;
    ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(i!=j && i!=k && j!=k && issan(a[i],a[j],a[k]))
                {
                    if((S & (1<<i)) && (S & (1<<j)) && (S & (1<<k)) )
                    {
                        int s = S ^ (1<<i);
                        s = s ^ (1<<j);
                        s = s ^ (1<<k);
                        ans = max(ans,dp(s)+Sa(a[i],a[j],a[k]));
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        for(int i = 0;i < n; i++)
            scanf("%lf",&a[i]);
        ++kase;
        double ans = dp((1<<n) - 1);
        printf("%.2f\n",ans);
    }
    return 0;
}