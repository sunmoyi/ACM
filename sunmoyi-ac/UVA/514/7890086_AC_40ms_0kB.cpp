//
// Created by 孙启龙 on 2017/1/15.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define maxn 1010

using namespace std;

int n, target[maxn];

int main (void)
{
    while(scanf("%d", &n) == 1 && n)
    {
        while(scanf("%d", &target[1]) && target[1])
        {
            stack<int> s;
            int A = 1, B = 1;
            for (int i = 2; i <= n; i++)
                scanf("%d", &target[i]);
            int ok = 1;
            while (B <= n)
            {
                if (A == target[B])
                    A++, B++;
                else if (!s.empty() && s.top() == target[B])
                    s.pop(), B++;
                else if (A <= n)
                    s.push(A++);
                else
                {
                    ok = 0;
                    break;
                }
            }
            printf("%s\n", ok ? "Yes" : "No");
        }
        printf("\n");
    }
    return 0;
}