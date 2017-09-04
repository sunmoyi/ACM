//
// Created by 孙启龙 on 2017/8/7.
//

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct node{
    long long x, y, z, d;
}start, endd;
long long num[3];

void run(node &u)
{
    num[0] = u.x; num[1] = u.y; num[2] = u.z;
    sort(num, num + 3);
    u.x = num[0]; u.y = num[1]; u.z = num[2];
}

bool equal(node u, node v)
{
    if (u.x == v.x && u.y == v.y && u.z == v.z)
        return true;
    return false;
}

node getroot(node &u)
{
    node t = u;
    long long p, q, r;
    p = t.y - t.x;
    q = t.z - t.y;
    while (p != q)
    {
        if (q > p)
        {
            r = (q - 1) / p;
            t.x += r * p;
            t.y += r * p;
        } else
        {
            r = (p - 1) / q;
            t.z -= r * q;
            t.y -= r * q;
        }
        u.d += r;
        run(t);
        p = t.y - t.x;
        q = t.z - t.y;
    }
    return t;
}

node getpre(node &u, long long step)
{
    node t = u;
    long long p, q, r;
    while (step > 0)
    {
        p = t.y - t.x;
        q = t.z - t.y;
        if (q > p)
        {
            r = (q - 1) / p;
            if (r > step)
                r = step;
            t.x += r * p;
            t.y += r * p;
        }
        else
        {
            r = (p - 1) / q;
            if (r > step)
                r = step;
            t.z -= r * q;
            t.y -= r * q;
        }
        step -= r;
        run(t);
    }
    return t;
}

int main (void)
{
    int a, b, c, x, y, z;
    long long l, r, mid;

    while(scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z) != EOF)
    {
        start.x = a, start.y = b, start.z = c, start.d = 0;
        endd.x = x, endd.y = y, endd.z = z, endd.d = 0;

        run(start);
        run(endd);

        if(!equal(getroot(start), getroot(endd)))
            printf("NO\n");
        else
        {
            long long len = start.d > endd.d? start.d - endd.d: endd.d - start.d;
            if(start.d > endd.d)
                start = getpre(start, len);
            else
                endd = getpre(endd, len);
            l = 0, r = min(start.d, endd.d);
            while(l != r)
            {
                mid = (l + r) >> 1;
                if(equal(getpre(start, mid), getpre(endd, mid)))
                    r = mid;
                else
                    l = mid + 1;
            }
            printf("YES\n");
            printf("%lld\n", 2 * l + len);
        }
    }
    return 0;
}