#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

char str[1000000];
char normal[100] = "Bulbasaur";
int num[100];

int main (void)
{
    while(scanf("%s", str) != EOF)
    {
        memset(num, 0, sizeof(num));
        int lenn = strlen(str);
        for(int i = 0; i < lenn; i++)
        {
            if(islower(str[i]))
                num[str[i] - 'a']++;
            else
                num[str[i] - 'A' + 30]++;
        }
        int minn = num[0] / 2;
        minn = min(minn, num['u' - 'a'] / 2);
        for(int i = 0; i <= 8; i++)
        {
            if(islower(normal[i]))
                minn = min(minn, num[normal[i] - 'a']);
            else
                minn = min(minn, num[normal[i] - 'A' + 30]);
        }
        printf("%d\n", minn);
    }
    return 0;
}