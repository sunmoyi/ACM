#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char str[15];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%s",str);
        int len = strlen(str);
        int sum = 0;
        for(int i = 0;i < len;i++)
        {
            if(str[i] == 'H')
                sum += 1;
            else if(str[i] == 'C')
                sum += 12;
            else if(str[i] == 'O')
                sum += 16;
        }
        printf("%d\n",sum);
    }
}
