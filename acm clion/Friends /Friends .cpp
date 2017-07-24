//
// Created by 孙启龙 on 2017/4/29.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool check(int i, int j)
{
    for(int k = 0; k <= 10; k++)
    {
        if( ((j & (1 << k)) == 1)  &&  ((i & (1 << k)) == 0) )
            return false;
    }
    return true;
}

int main (void)
{
    for(int t = 0; t <= 2; t++)
    {
        long long ans = 0;
        for(int c = 0; c < (1 << t); c++)
        {
            for(int f = 0; f < (1 << t); f++)
            {
                for(int i = 0; i < (1 << t); i++)
                {
                    for(int b = 0;  b < (1 << t); b++)
                    {
                        if(!check(b, c))
                            continue;
                        for(int h = 0; h < (1 << t); h++)
                        {
                            if(!check(h, i))
                                continue;
                            for(int g = 0; g < (1 << t); g++)
                            {
                                if(!check(g, b))
                                    continue;
                                if(!check(g, f))
                                    continue;
                                if(!check(g, h))
                                    continue;
                                for(int e = 0; e < (1 << t); e++)
                                {
                                    if(!check(e, c))
                                        continue;
                                    if(!check(e, f))
                                        continue;
                                    for(int a = 0; a < (1 << t); a++)
                                    {
                                        if(!check(a, b))
                                            continue;
                                        if(!check(a, e))
                                            continue;
                                        for(int d = 0; d < (1 << t) ; d++)
                                        {
                                            if(!check(d, e))
                                                continue;
                                            if(!check(d, g))
                                                continue;
                                            printf("c:%d f:%d i:%d b:%d e:%d g:%d a:%d d:%d\n", c, f, i, b, e, g, a, d);
                                            ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
}