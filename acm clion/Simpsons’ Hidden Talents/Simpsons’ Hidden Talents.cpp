//
// Created by 孙启龙 on 2017/4/1.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50010

using namespace std;

char str1[maxn];
char str2[maxn];
int nextt[maxn << 1], len, len1, len2;
char str[maxn << 1];

void make_next()
{
    int i = 0, j = -1;
    nextt[0] = -1;
    while(i < len)
    {
        if(j == -1 || str[i] == str[j])
        {
            i++;
            j++;
            nextt[i] = j;
        }
        else
            j = nextt[j];
    }
}

int main (void)
{
    while(scanf("%s", str1) != EOF)
    {
        scanf("%s", str2);
        strcpy(str, str1);
        strcat(str, str2);
        len = strlen(str);
        len1 = strlen(str1);
        len2 = strlen(str2);

        make_next();
        if(nextt[len] <= 0)
            printf("0\n");
        else
        {
            int ans = min(len1, len2);
            ans = min(ans, nextt[len]);
            for(int i = 0; i < ans; i++)
                printf("%c", str1[i]);
            printf(" %d\n", ans);
        }
    }
    return 0;
}