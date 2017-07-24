//
// Created by 孙启龙 on 2017/2/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 1030

using namespace std;

int n, num;
char a[maxn][maxn];

int main (void)
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 1; i <= n; i++)
            scanf("%s", a[i] + 1);
        vector<int> win, lose;
        for(int i = 2; i <= n; i++)
        {
            if(a[1][i] == '1')
                win.push_back(i);
            else
                lose.push_back(i);
        }
        num = n;
        while(num > 1)
        {
            vector<int>win2, lose2, final;
            for(int i = 0; i < lose.size(); i++)
            {
                int tlose = lose[i];
                bool matched = false;
                for(int j = 0; j < win.size(); j++)
                {
                    int &twin = win[j];
                    if(twin > 0 && a[twin][tlose] == '1')
                    {
                        printf("%d %d\n", twin, tlose);
                        win2.push_back(twin);
                        twin = 0;
                        matched = true;
                        break;
                    }
                }
                if(!matched)
                    final.push_back(tlose);
            }
            bool first = true;
            for(int i = 0; i < win.size(); i++)
            {
                int twin = win[i];
                if(twin > 0)
                {
                    if(first)
                    {
                        printf("1 %d\n", twin);
                        first = false;
                    }
                    else
                        final.push_back(twin);
                }
            }
            for(int i = 0; i < final.size(); i += 2)
            {
                printf("%d %d\n", final[i], final[i + 1]);
                int keep = final[i];
                if(a[final[i + 1]][keep] == '1')
                    keep = final[i + 1];
                if(a[1][keep] == '1')
                    win2.push_back(keep);
                else
                    lose2.push_back(keep);
            }
            win = win2;
            lose = lose2;
            num >>= 1;
        }
    }
    return 0;
}