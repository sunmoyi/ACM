//
// Created by 孙启龙 on 2017/4/22.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int T;
int num;
int ans1, ans2, temp;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            ans1 = ans2 = 0;
            scanf("%d", &num);
            for(int i = 1; i <= num; i++)
            {
                scanf("%d", &temp);
                if(temp == 1)
                    ans1++;
                else if (temp == 2)
                    ans2++;
                else if (temp == 3)
                    ans1++, ans2++;
                else if (temp == 4)
                    ans1--, ans2--;
            }
            if(ans1 > ans2)
                printf("Kobayashi\n");
            else if (ans1 < ans2)
                printf("Tohru\n");
            else
                printf("Draw\n");
        }
    }
    return 0;
}