//
//Created by 孙启龙 on 06/11/16
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100010;
int ans[N], a[N];

int main(void)
{
    int Case;
    scanf("%d",&Case);
    while(Case--)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d", &a[i]);
        //*********************************************************
        int len=1, flag1=0, flag2=0;
        ans[1] = a[1];
        for(int i=2;i<=n;i++)
        {
            if(a[i] >= ans[len])
            {
                len++;
                ans[len]=a[i];
            }
            else
            {
                int pos=upper_bound(ans+1,ans+len,a[i])-ans;
                ans[pos]=a[i];
            }
        }
        if(len>=n-1)
            flag1=1;
        //*********************************************************
        len=1;
        ans[1]=a[n];
        for(int i = n-1;i >= 1;i--)
        {
            if(a[i] >= ans[len])
            {
                len++;
                ans[len]=a[i];
            }
            else
            {
                int pos = upper_bound(ans+1,ans+len,a[i])-ans;
                ans[pos]=a[i];
            }
        }
        if(len >= n-1)
            flag2 = 1;
        //*********************************************************
        if(flag1 || flag2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}