//
// Created by 孙启龙 on 2017/7/29.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    int a[1010],l,r;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int q;
        scanf("%d",&q);
        while (q--)
        {
            int Max=0;
            scanf("%d%d",&l,&r);
            for (int i=l; i<=r; i++)
            {
                if (a[i]>Max)
                    Max=a[i];
            }
            cout<<Max<<endl;
        }
    }
    return 0;
}