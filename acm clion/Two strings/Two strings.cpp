//
// Created by 孙启龙 on 2017/2/16.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

char a[maxn], b[maxn];
int lena, lenb, L, R;
int needh[maxn], needl[maxn];

int main (void)
{
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    lena = strlen(a + 1);
    lenb = strlen(b + 1);
    for(int i = 1; i <= lenb; i++)
        needh[i] = needl[i] = lena + 1;
    int pos = 1;
    L = lenb;
    R = 1;
    for(int i = 1; i <= lenb; i++)
    {
        while(pos <= lena && a[pos] != b[i])
            ++pos;
        if(pos <= lena)
            needh[i] = pos;
        else
        {
            L = i - 1;
            break;
        }
        ++pos;
    }

    pos = lena;
    for(int i = lenb; i >= 1; i--)
    {
        while(pos >= 1 && a[pos] != b[i])
            --pos;
        if(pos >= 1)
            needl[i] = lena - pos + 1;
        else
        {
            R = i + 1;
            break;
        }
        --pos;
    }
    if(L < 1 && R > lenb)
        printf("-\n");
    else if (L == lenb || R == 1)
        printf("%s\n", b + 1);
    else
    {
        int len, left, right;
        if(L > lenb - R + 1)
        {
            len = L;
            left = L;
            right = lenb + 1;
        }
        else
        {
            len = lenb - R + 1;
            left = 0;
            right = R;
        }
        for(int i = R; i <= lenb; i++)
        {
            int p = upper_bound(needh + 1, needh + L + 1, lena - needl[i]) - needh - 1;
            if(p <= L && p + lenb - i + 1 > len)
            {
                len = p + lenb - i + 1;
                left = p;
                right = i;
            }
        }
        for(int i = 1; i <= left; i++)
            printf("%c", b[i]);
        for(int i = right; i <= lenb; i++)
            printf("%c", b[i]);
        printf("\n");
    }
    return 0;
}