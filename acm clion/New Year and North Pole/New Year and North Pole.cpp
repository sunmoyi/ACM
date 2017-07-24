//
// Created by 孙启龙 on 2017/1/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char str[10];

int main (void)
{
    int T, N, cut = 0, ok = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %s", &N ,str);
        if((cut == 0 && str[0] != 'S') || (cut == 20000 && str[0] != 'N'))
            ok = 0;
        if(str[0] == 'S')
            cut += N;
        else if (str[0] == 'N')
            cut -= N;
        if(cut < 0 || cut > 20000)
            ok = 0;
    }
    if(!ok || cut != 0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}