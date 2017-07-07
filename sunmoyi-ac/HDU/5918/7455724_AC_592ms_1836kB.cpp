#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
int a[N],b[N];
int main()
{
    int t,n;
    cin >> t;
    for(int ca = 1;ca <= t;ca++)
    {
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        for(int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i <= m;i++)
            scanf("%d",&b[i]);
        printf("Case #%d: ",ca);
        bool flag = false;
        int sum = 0;
        for(int i = 1;i+(m-1)*p <= n;i++)
        {
            if(a[i] == b[1])
            {
                flag = true;
                for(int j = 2;j <= m;j++)
                {
                    if(b[j] != a[i+p*(j-1)])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
            {
                sum++;
                flag = false;
            }
        }

        //if(flag)
        printf("%d\n",sum);

    }
    return 0;
}
