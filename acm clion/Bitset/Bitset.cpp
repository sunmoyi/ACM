//
// Created by 孙启龙 on 2017/4/17.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

stack<int>ans;
int num;

int main (void)
{
    while(scanf("%d", &num) != EOF)
    {
        if(num == 0)
        {
            printf("0\n");
            continue;
        }
        while(!ans.empty())
            ans.pop();

        while(num > 0)
        {
            ans.push(num % 2);
            num /= 2;
        }

        while(!ans.empty())
        {
            printf("%d", ans.top());
            ans.pop();
        }
        printf("\n");
    }
    return 0;
}