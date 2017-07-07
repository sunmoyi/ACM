#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    char str[30];
    int t;
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%s",str);
            for(int i=0;i<strlen(str);i++)
                if(str[i]>='0'&&str[i]<='9')
                    continue;
                else
                    printf("%c",str[i]);
            printf("\n");
        }
    }
}
