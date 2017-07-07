/*
Ьтвт
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

typedef long long ll;

char str[25];
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        scanf("%s",str);
        int sum = 0;
        for(int i = 0;str[i] != '\0';i++)
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
