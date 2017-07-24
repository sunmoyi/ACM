//
// Created by 孙启龙 on 2017/5/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    int n;
    while(scanf("%d", &n) != EOF && n)
    {
        if(n <= 2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}