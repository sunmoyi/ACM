//
// Created by 孙启龙 on 2016/10/30.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int n, Case = 0;
    char buf[100];
    while(scanf("%d", &n) == 1 && n)
    {
        int cnt = 0;
        if(Case++)
            printf("\n");
        for(int fghij = 1234; ; fghij++)
        {
            int abcde = fghij * n;
            sprintf(buf, "%05d%05d", abcde, fghij);
            if(strlen(buf) > 10)
                break;
            sort(buf, buf + 10);
            bool ok = true;
            for(int i = 0; i < 10; i++)
                if(buf[i] != '0' + i)
                    ok = false;
            if(ok)
            {
                cnt++;
                printf("%05d / %05d = %d\n", abcde, fghij, n);
            }
        }
        if(!cnt)
            printf("There are no solutions for %d.\n", n);
    }
    return 0;
}