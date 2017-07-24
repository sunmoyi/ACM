//
// Created by 孙启龙 on 2017/4/10.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 4400

using namespace std;

struct node{
    int l, r;
    double len;
    int covers;
    int mid()
    {
        return (l + r) >> 1;
    }
}trees[maxn];

struct Line{
    double x, y1, y2;
    bool bl;
    bool friend operator < (const Line &a, const Line&b)
    {
        return a.x < b.x;
    }
}line[210];

double y[210];

int bin_search(int l, int r, double val)
{
    int mid;
    --r;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (!(y[mid] > val || y[mid] < val))
            return mid;
        else if (y[mid] < val)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}

void insert(int root, int l, int r)
{
    if (trees[root].l == l && trees[root].r == r)
    {
        trees[root].len = y[r + 1] - y[l];
        ++trees[root].covers;
        return;
    }
    int mid = trees[root].mid();
    if (r <= mid)
        insert(root * 2, l, r);
    else if (l > mid)
        insert(root * 2 + 1, l, r);
    else
    {
        insert(root * 2, l, mid);
        insert(root * 2 + 1, mid + 1, r);
    }
    if (trees[root].covers == 0)
        trees[root].len = trees[root * 2].len + trees[root * 2 + 1].len;

}

void Delete(int root, int l, int r)
{
    if (trees[root].l == l && trees[root].r == r)
    {
        --trees[root].covers;
        if (trees[root].covers == 0)
        {
            if (trees[root].l == trees[root].r)
                trees[root].len = 0;
            else
                trees[root].len = trees[root * 2].len + trees[root * 2 + 1].len;
        }
        return;
    }

    int mid = trees[root].mid();
    if (r <= mid)
        Delete(root * 2, l, r);
    else if (l > mid)
        Delete(root * 2 + 1, l, r);
    else
    {
        Delete(root * 2, l, mid);
        Delete(root * 2 + 1, mid + 1, r);
    }
    if (trees[root].covers == 0)
        trees[root].len = trees[root * 2].len + trees[root * 2 + 1].len;

}

void buildtree(int root, int l, int r)
{
    trees[root].l = l;
    trees[root].r = r;
    trees[root].len = 0;
    trees[root].covers = 0;
    if (l == r)
        return;
    buildtree(root * 2, l, (l + r) >> 1);
    buildtree(root * 2 + 1, ((l + r) >> 1) + 1, r);
}

int main (void)
{
    int n;
    double x1, x2, y1, y2;
    int yc, lc;
    int t = 0;
    while(scanf("%d", &n) && n)
    {
        t++;
        yc = lc = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            y[yc++] = y1;
            y[yc++] = y2;
            line[lc].x = x1;
            line[lc].y1 = y1;
            line[lc].y2 = y2;
            line[lc++].bl = true;
            line[lc].x = x2;
            line[lc].y1 = y1;
            line[lc].y2 = y2;
            line[lc++].bl = false;
        }
        sort(y, y + yc);
        yc = unique(y, y + yc) - y;
        buildtree(1, 0, yc - 1 - 1);

        sort(line, line + lc);
        double Area = 0;
        for(int i = 0; i < lc - 1; i++)
        {
            int l = bin_search(0, yc, line[i].y1);
            int r = bin_search(0, yc, line[i].y2);
            if(line[i].bl)
                insert(1, l, r - 1);
            else
                Delete(1, l, r - 1);
            Area += trees[1].len * (line[i + 1].x - line[i].x);
        }
        printf("Test case #%d\n", t);
        printf("Total explored area: %.2lf\n", Area);
        printf("\n");
    }
    return 0;
}