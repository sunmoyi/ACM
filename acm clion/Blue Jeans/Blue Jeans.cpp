//
// Created by 孙启龙 on 2017/4/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 66

using namespace std;

char test[10][maxn], pat[maxn];
int n, ma, lenp, nextt[maxn];

void make_next()
{
    int i = 0, j = -1;
    nextt[0] = -1;
    while(i < lenp)
    {
        if(j == -1 || pat[i] == pat[j])
        {
            i++;
            j++;
            nextt[i] = j;
        }
        else
            j = nextt[j];
    }
}

void KMP()
{
    int k, m, i, j;
    make_next();
    ma = 100;
    for (k = 1; k < n; k++)
    {
        i = 0; j = 0; m = 0;
        while (i < 60 && j < lenp)
        {
            if (j == -1 || test[k][i] == pat[j])
                i++, j++;
            else
                j = nextt[j];
            if (j > m)
                m = j;
        }
        if (m < ma)
            ma = m;
    }
}

int main(void)
{
    int T;
    char result[maxn];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", test[i]);
        int ans = 0;
        for(int i = 0; i < 57; i++)
        {
            strcpy(pat, test[0] + i);
            lenp = 60 - i;
            KMP();
            if(ans < ma)
            {
                ans = ma;
                strncpy(result, test[0] + i, ans);
                result[ans] = 0;
            }
            else if (ans == ma)
            {
                char temp[maxn];
                strncpy(temp, test[0] + i, ans);
                temp[ans] = 0;
                if(strcmp(temp, result) < 0)
                    strcpy(result, temp);
            }
        }
        if(ans >= 3)
            printf("%s\n", result);
        else
            printf("no significant commonalities\n");
    }
    return 0;
}