//
// Created by 孙启龙 on 2017/2/26.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000010

using namespace std;

int da[maxn], db[maxn];

int main (void)
{
    int T, n, cas = 0;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &da[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &db[i]);
        memcpy(da + n, da, sizeof(int) * n);
        memcpy(db + n, db, sizeof(int) * n);
        int l, r, ans = -1;
        for(l = 0; l < n; l = r)
        {
            int sum = 0, num = 0; r = l;
            while(ans == -1 && (num += (da[r] - db[r++])) >= 0)
                if(++sum == n)
                    ans = l;
            if(ans != -1)
                break;
        }
        if(ans == -1)
            printf("Case %d: Not possible\n", ++cas);
        else
            printf("Case %d: Possible from station %d\n", ++cas, ans + 1);
    }
    return 0;
}