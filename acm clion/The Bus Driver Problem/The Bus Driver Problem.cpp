//
// Created by 孙启龙 on 2017/3/25.
//

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int morni[101];
int after[101];

int cmp1(int a, int b){ return a < b; }
int cmp2(int a, int b){ return a > b; }

int main()
{
    int n,d,r;
    while (~scanf("%d%d%d",&n,&d,&r) && n) {
        for (int i = 0 ; i < n ; ++ i)
            scanf("%d",&morni[i]);
        for (int i = 0 ; i < n ; ++ i)
            scanf("%d",&after[i]);
        sort(morni, morni+n, cmp1);
        sort(after, after+n, cmp2);
        int sum = 0;
        for (int i = 0 ; i < n ; ++ i)
            if (morni[i]+after[i] > d)
                sum += r*(morni[i]+after[i]-d);

        printf("%d\n",sum);
    }
    return 0;
}