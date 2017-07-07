//
// Created by 孙启龙 on 2016/11/3.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
struct node{
    int year;
    int day;
    int month;
    bool friend operator < (const node &a, const node &b)
    {
        if(a.year != b.year)
            return a.year > b.year;
        else if(a.month != b.month)
            return a.month > b.month;
        else
            return a.day > b.day;
    }
}now, son[1000], son1[1000];

bool check (const node &a, const node &b)
{
    return a.year == b.year && a.month == b.month && a.day == b.day;
}

int main (void)
{
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);
    while(scanf("%d %d %d", &now.day, &now.month, &now.year) != EOF)
    {
        scanf("%d", &n);
        now.year -= 18;
        for(int i = 1; i <= n; i++)
            scanf("%d %d %d",  &son[i].day, &son[i].month, &son[i].year);
        for(int i = 1; i <= n; i++)
            son1[i] = son[i];
        sort(son + 1, son + n + 1);
        int i;
        for(i = 1; i <= n; i++)
        {
            //printf("%d %d\n", i, n);
            if(son[i] < now)
                ;
            else
            {
                break;
            }
        }
        if(i == n + 1)
            printf("-1\n");
        else
        {
            for(int j = 1; j <= n; j++)
            {
                if(check(son1[j], son[i]))
                {
                    printf("%d\n", j);
                    break;
                }
            }
        }
    }
    return 0;
}