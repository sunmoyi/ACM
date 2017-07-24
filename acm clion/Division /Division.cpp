//
// Created by 孙启龙 on 2017/2/2.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int n, Case = 0;
    char buff[100];
    while(scanf("%d", &n) != EOF && n)
    {
        int cnt = 0;
        if(Case++)
            printf("\n");
        for(int fghij = 1234; ; fghij++)
        {
            int abcde = fghij * n;
            sprintf(buff, "%05d%05d", abcde, fghij);
            if(strlen(buff) > 10)
                break;
            sort(buff, buff + 10);
            bool ok = true;
            for(int i = 0; i < 10; i++)
                if(buff[i] != '0' + i)
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