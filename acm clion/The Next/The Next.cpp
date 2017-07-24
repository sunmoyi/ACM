//
// Created by 孙启龙 on 2017/7/21.
//

#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    int t,T=1,s1,s2;
    ll d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d %d",&d,&s1,&s2);
        d++;
        while(true)
        {
            ll m=d;
            int num=0,cnt=0,bri[35];
            while(m)
            {
                if(m%2)
                {
                    bri[num++]=1;
                    cnt++;
                }
                else bri[num++]=0;
                m/=2;
            }
            if(cnt<s1)
            {
                int i=0;
                for(;i<num;i++)
                    if(bri[i]==0) break;
                d=d+(1<<i);
            }
            else if(cnt>s2)
            {
                int i=0;
                for(;i<num;i++)
                    if(bri[i]==1) break;
                d=d+(1<<i);
            }
            else break;
        }
        printf("Case #%d: %lld\n",T++,d);
    }
    return 0;
}