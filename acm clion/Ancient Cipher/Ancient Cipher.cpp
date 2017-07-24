//
// Created by 孙启龙 on 2017/3/22.
//

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 110
#define maxl 26
char str1[maxn], str2[maxn];
int s1[maxl], s2[maxl];
int main()
{

    while(scanf("%s",str1) == 1)
    {
        scanf("%s",str2);
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));

        for(int i = 0; str1[i] != '\0'; i++)
        {
            s1[str1[i] - 'A']++;
            s2[str2[i] - 'A']++;
        }

        sort(s1,s1+maxl);
        sort(s2,s2+maxl);

        bool flag = true;
        for(int i = 0; i < maxl; i++)
        {
            if(s1[i] != s2[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}