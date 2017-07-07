//
// Created by 孙启龙 on 2017/1/24.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 30

using namespace std;

char str1[maxn], str2[maxn];

void exchange(int p1, int p2, int q1, int q2)
{
    if(p1 > p2)
        return ;
    int root  = 0;
    for(root = q1; str2[root] != str1[p1]; root++);
    exchange(p1 + 1, p1 + root - q1, q1, root - 1);
    exchange(p1 + root - q1 + 1, p2, root + 1, q2);
    printf("%c", str2[root]);
}

int main (void)
{
    while(scanf("%s %s", str1, str2) != EOF)
    {
        int len = strlen(str1) - 1;
        exchange(0, len, 0, len);
        printf("\n");
    }
    return 0;
}