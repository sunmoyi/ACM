//
// Created by 孙启龙 on 2016/11/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>

using namespace std;

int Q[100000];

int main (void)
{
    int n;
    while(cin >> n && n)
    {
        for(int i = 0; i <= n; i++)
            Q[i] = i;
        int head = 1, tail = n, first = 1;
        printf("Discarded cards:");
        while(head < tail)
        {
            if(!first)
                printf(",");
            printf(" %d", Q[head++]);
            Q[++tail] = Q[head++];
            first = 0;
        }
        printf("\nRemaining card: %d\n",Q[head]);
    }
    return 0;
}