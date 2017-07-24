//
// Created by 孙启龙 on 2017/5/5.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int num[10] = {0, 22, 24, 24, 16, 24, 21, 23, 22};
int ans1, ans2;

int main (void)
{
    srand((int)time(0));
    while(!ans1)
        ans1 = rand() % 9;
    while(!ans2)
        ans2 = rand() % num[ans1];
    printf("%d %d\n", ans1, ans2);
    return 0;
}