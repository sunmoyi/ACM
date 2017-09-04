//
// Created by 孙启龙 on 2017/8/12.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, y, m, d;

int main (void)
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d-%d-%d", &y, &m, &d);
        int sum = 0;
        bool flag = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);

        if(m == 2 && d == 29)
        {
            int i = y;
            while(++i)
            {
                if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                    sum += 2;
                else
                    sum++;

                if((sum % 7 == 0) && ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)))
                    break;
            }
            printf("%d\n", i);
        }
        else if(m == 1 || (m == 2 && d <= 28))
        {
            int i = y;
            while(++i)
            {
                if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                {
                    flag = true;
                    sum++;
                }
                else if (flag)
                {
                    flag = false;
                    sum += 2;
                }
                else
                    sum++;

                if(sum % 7 == 0)
                    break;
            }
            printf("%d\n", i);
        }
        else
        {
            int i = y;
            while(++i)
            {
                if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
                    sum += 2;
                else
                    sum++;

                if(sum % 7 == 0)
                    break;
            }
            printf("%d\n", i);
        }
    }
    return 0;
}