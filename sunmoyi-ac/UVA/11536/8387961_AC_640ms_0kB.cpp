//
// Created by 孙启龙 on 2017/3/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 1000010
#define INF 0x3f3f3f3f

using namespace std;

int n, m, k;
int arr[maxn];
int cnt[maxn];

void init()
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i = 4; i <= n; i++)
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]) % m + 1;
    memset(cnt, 0, sizeof(cnt));
}

int main (void)
{
    int nCase, Case = 1;
    scanf("%d", &nCase);

    while(nCase--)
    {
        scanf("%d %d %d", &n, &m, &k);
        init();
        int minx = INF;
        int count = 0;

        queue<int>Q;
        for(int i = 1; i <= n; i++)
        {
            if(arr[i] >= 1 && arr[i] <= k)
            {
                Q.push(i);
                if(cnt[arr[i]] ++ == 0)
                    ++count;
                while(count == k)
                {
                    int temp = i - Q.front() + 1;
                    minx = min(minx, temp);
                    int val = arr[Q.front()];
                    if(--cnt[val] == 0)
                        --count;
                    Q.pop();
                }
            }
        }
        printf("Case %d: ", Case++);
        if(minx == INF)
            printf("sequence nai\n");
        else
            printf("%d\n", minx);
    }
    return 0;
}