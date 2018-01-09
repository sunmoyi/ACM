#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

string s[105];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 0;i < n;i++)
            cin >> s[i];
        puts("NO");
        for(int i = 1,j;i < n;i++)
        {
            for(j = 0;j < i;j++)
            {
                if(s[i] == s[j])
                {
                    puts("YES");
                    break;
                }
            }
            if(j == i)
                puts("NO");
        }
    }
    return 0;
}
