#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,a,b;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d%d%d",&n,&a,&b);
            int sum1,sum2;
            sum1=abs(n-a);
            sum2=abs(n-b);
            if(sum1<sum2)
                printf("A\n");
            else
                printf("B\n");
        }
    }
    return 0;
}
