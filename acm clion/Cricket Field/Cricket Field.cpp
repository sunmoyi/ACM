//
// Created by 孙启龙 on 2017/3/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 110

using namespace std;

struct XY{
    int x, y;
    bool operator < (const XY &a)const{
        return(x < a.x || (x == a.x && y < a.y));
    }
}xy[maxn];
int d[maxn], n, w, h;

void solve()
{
    sort(xy+1,xy+n+1);
    sort(d,d+n+2);
    int ans=0,ansx,ansy;
    for(int i=0;i<=n+1;++i)
    {
        for(int j = i + 1; j <= n + 1; ++j)
        {
            int high=d[j],low=d[i],temp=0,r=d[j]-d[i],c;
            for(int k=1;k<=n;++k)
            {
                if(xy[k].y<=low||xy[k].y>=high)
                    continue;
                c=xy[k].x-temp;
                if(ans<min(r,c))
                {
                    ans=min(r,c);
                    ansx=temp,ansy=low;
                }
                temp=xy[k].x;
            }
            c=w-temp;
            if(ans<min(r,c)){
                ans=min(r,c);
                ansx=temp,ansy=low;
            }
        }
    }
    printf("%d %d %d\n",ansx,ansy,ans);
}

int main (void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &w, &h);
        d[0] = 0, d[n + 1] = h;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &xy[i].x, &xy[i].y);
            d[i] = xy[i].y;
        }
        solve();
        if(T)
            printf("\n");
    }
    return 0;
}