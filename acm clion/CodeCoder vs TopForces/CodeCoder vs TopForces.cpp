//
// Created by 孙启龙 on 2016/11/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int hang[1000100];
int lie[1000100];
int sum[1000100];
int ans[1000100];
int n;
struct node{
    int x, y, z;
}people[1000100];

bool cmp(node &a, node &b)
{
    if(a.y != b.y)
        return a.y < b.y;
    else
        return a.x < b.x;
}

int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int s)
{
    while(x < 1000010)
    {
        sum[x] += s;
        x += lowbit(x);
    }
}

int summ(int x)
{
    int rank = 0;
    while(x > 0)
    {
        rank += sum[x];
        x -= lowbit(x);
    }
    return rank;
}

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        memset(hang, 0, sizeof(hang));
        memset(lie, 0, sizeof(lie));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &people[i].x, &people[i].y);
            people[i].z = i;
            hang[people[i].x]++;
            lie[people[i].y]++;
        }
        sort(people + 1, people + n + 1, cmp);
        for(int i = 1; i <= 1000000; i++)
        {
            hang[i] += hang[i - 1];
            lie[i] += lie[i - 1];
        }
        /*
        for(int i = 1; i <= 5; i++)
            printf("%d ", hang[i]);
        printf("\n");
        for(int i = 1; i <= 5; i++)
            printf("%d ", lie[i]);
        printf("\n");
        */
        for(int i = 1; i <= n; i++)
        {
            int k = summ(people[i].x);
            //printf("%d %d\n", people[i].z, k);
            k = hang[people[i].x] + lie[people[i].y] - k - 2;
            ans[people[i].z] = k;
            add(people[i].x, 1);
        }
        for(int i = 1; i <= n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}