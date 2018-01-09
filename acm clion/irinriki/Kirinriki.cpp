    //
    // Created by 孙启龙 on 2017/10/1.
    //

    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    #define abs(x) ((x) >= 0? (x): (-(x)))

    #define maxn 100010

    using namespace std;

    char str[maxn];
    int m;
    int len, ans;

    void run(int x, int y)
    {
        int dis = 0, l = 0, r = 0;
        while(y + r < len && x - r >= 0)
        {
            if((dis + abs(str[x - r] - str[y + r])) <= m)
            {
                dis += abs(str[x - r] - str[y + r]);
                r++;
                ans = max(ans, r - l);
            }
            else
            {
                dis -= abs(str[x - l] - str[y + l]);
                l++;
            }
        }
    }

    int main (void)
    {
        int Case;
        scanf("%d", &Case);
        while(Case--)
        {
            scanf("%d", &m);
            ans = 0;
            scanf("%s", str);
            len = strlen(str);
            for(int i = 0; i < len; i++)
            {
                run(i - 1, i + 1);
                run(i, i + 1);
            }
            printf("%d\n", ans);
        }
        return 0;
    }