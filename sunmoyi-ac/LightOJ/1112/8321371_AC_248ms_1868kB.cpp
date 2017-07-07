//
// Created by 孙启龙 on 2017/3/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int N;
int c[maxn << 1];

int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int num)
{
    while(x <= N)
    {
        c[x] += num;
        x += lowbit(x);
    }
}

int get_sum(int x)
{
    int sum = 0;

    while(x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    int T, P, a;
    int i, j;
    int l, m, n;
    int k = 1;

    scanf("%d", &T);
    while(T--)
    {
        memset(c, 0, sizeof(c));

        scanf("%d%d", &N, &P);

        for(i = 1; i <= N; i++)
        {
            scanf("%d", &a);
            update(i, a);
        }

        printf("Case %d:\n", k++);
        for(i = 0; i < P; i++)
        {
            scanf("%d", &l);
            if(l == 1)
            {
                scanf("%d", &m);
                m++;
                printf("%d\n", get_sum(m) - get_sum(m - 1));
                update(m, -(get_sum(m) - get_sum(m - 1)));

            }
            else if(l == 2)
            {
                scanf("%d%d", &m, &n);
                m++;
                update(m, n);
            }
            else if(l == 3)
            {
                scanf("%d%d", &m, &n);
                m++;
                n++;
                printf("%d\n", get_sum(n) - get_sum(m - 1));
            }

        }
    }
    return 0;
}