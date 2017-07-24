//
// Created by 孙启龙 on 2017/7/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3010

using namespace std;

int s;
char op[5];
int k, A, B;
int l, b, r, t;
int n, m;

struct tree{
    long long num[2][2][maxn][maxn];
    int lowbit(int x)
    {
        return x & (-x);
    }
    void add(int x, int y, long long a)
    {
        for(int i = x; i <= s; i += lowbit(i))
            for(int j = y; j <= s; j += lowbit(j))
                num[x & 1][y & 1][i][j] ^= a;
    }
    long long query(int x, int y)
    {
        long long  ans = 0;
        for (int i = x; i > 0; i -= lowbit(i))
            for (int j = y; j > 0; j -= lowbit(j))
                ans ^= num[x & 1][y & 1][i][j];
        return ans;
    }
};

tree tp;

int main (void)
{
    scanf("%d %d", &n, &m);
    s = n;
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", op);
        scanf("%d %d %d %d", &l, &b, &r, &t);
        if(op[0] == 'P')
        {
            scanf("%d", &k);
            long long val = 0;
            while(k--)
            {
                scanf("%d %d", &A, &B);
                A--;
                if(B & 1)
                    val ^= 1LL << A;
            }
            tp.add(l, b, val);
            tp.add(r + 1, b, val);
            tp.add(l, t + 1, val);
            tp.add(r + 1, t + 1, val);
        }
        else
        {
            long long ret = tp.query(r, t);
            ret ^= tp.query(l - 1, t);
            ret ^= tp.query(r, b - 1);
            ret ^= tp.query(l - 1, b - 1);
            for (int j = 0; j < 50; j++)
            {
                if ((1LL << j) & ret)
                    printf("2 ");
                else
                    printf("1 ");
            }
            printf("\n");
        }
    }
    return 0;
}