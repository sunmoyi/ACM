//
// Created by 孙启龙 on 2017/4/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>

using namespace std;

int v[10][10];
int num[10];
char str[10][10];

int main (void)
{
    v[1][1] = v[1][4] = v[1][5] = v[1][6] = v[1][7] = 1;
    v[2][3] = v[2][6] = 1;
    v[3][5] = v[3][6] = 1;
    v[4][1] = v[4][4] = v[4][5] = 1;
    v[5][2] = v[5][5] = 1;
    v[6][2] = 1;
    v[7][4] = v[7][5] = v[7][6]= v[7][7] = 1;
    v[9][5] = 1;


    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d %s", &num[i], str[i]);

        map<int, int>mp1, mp2;
        mp1.clear(), mp2.clear();

        for(int i = 0; i < 7; i++)
        {
            int temp1 = 0, temp2 = 0;
            for(int j = 1; j <= n; j++)
            {
                temp1 = temp1 * 10 + str[j][i] - '0';
                temp2 = temp2 * 10 + v[num[j]][i + 1];
            }
            mp1[temp1]++;
            mp2[temp2]++;
        }
        if(mp1 == mp2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}