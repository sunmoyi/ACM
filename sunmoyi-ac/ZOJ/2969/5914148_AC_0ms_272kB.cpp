#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    long long t,n,a[1005];
    while(~scanf("%lld",&t))
    {
        while(t--)
        {
            scanf("%lld",&n);
            if(!n)
            {
                scanf("%d",&a[0]);
                printf("0\n");
                continue;
            }
            for(int i=0;i<=n;i++)//输入n+1
            {
                scanf("%d",&a[i]);
            }
            int t=n;
            while(n)
            {
                if(t==n)
                    printf("%lld",n*a[t-n]);
                else
                    printf(" %lld",n*a[t-n]);
                n--;
            }
            printf("\n");
        }
    }
    return 0;
}
