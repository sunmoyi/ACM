#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,a[2010];
    string str;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            cin>>str;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
            sort(a,a+n);
            if(str=="Faster")
                printf("%d\n",a[0]);
            else
                printf("%d\n",a[n-1]);
        }
    }
    return 0;
}
