//
// Created by 孙启龙 on 2017/3/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 5000

using namespace std;

int father[maxn];
int n, m, flag;

void init()
{
    flag = 0;
    memset(father, -1, sizeof(father));
}

int find(int x)
{
    if(father[x] == -1)
        return x;
    return father[x] = find(father[x]);
}

void unoin(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y)
    {
        father[x] = y;
    }
}

int main (void)
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        printf("Scenario #%d:\n",Case);
        scanf("%d %d", &n, &m);
        init();
        int a, b;
        while(m--)
        {
            scanf("%d %d", &a, &b);
            if(find(a) != find(b))
            {
                unoin(a, b + n);
                unoin(b, a + n);
            }
            else
                flag = 1;
        }
        if(flag){
            puts("Suspicious bugs found!\n");
        }else
            puts("No suspicious bugs found!\n");
    }
}