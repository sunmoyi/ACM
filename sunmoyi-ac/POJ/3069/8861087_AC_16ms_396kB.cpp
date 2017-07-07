//
// Created by 孙启龙 on 2017/4/21.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1100

using namespace std;

int num[maxn], n, r;

int main (void)
{
    while(scanf("%d %d", &r, &n) != EOF && (r != -1 || n != -1))
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        sort(num, num + n);
        int l, index = 0, ans = 0;
        while(index < n)
        {
            l = num[index] + r;
            while(index < n && num[index] <= l)
                index++;
            int p = num[index - 1] + r;
            while(index < n && num[index] <= p)
                index++;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}