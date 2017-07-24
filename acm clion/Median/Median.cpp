//
// Created by 孙启龙 on 2017/4/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int num[100010];
pair<int, int>l, r;
int n, m;
int T;

int main (void)
{
    while(scanf("%d", &T) != EOF)
    {
        while(T--)
        {
            scanf("%d %d", &n, &m);
            for(int i = 1; i<= n; i++)
                scanf("%d", &num[i]);
            while(m--) {
                scanf("%d %d %d %d", &l.first, &l.second, &r.first, &r.second);

                if (l.first > l.second)
                    swap(l.first, l.second);
                if (r.first > r.second)
                    swap(r.first, r.second);
                if (l.first > r.first)
                    swap(l, r);

                int len1 = l.second - l.first + 1;
                int len2 = r.second - r.first + 1;
                //l.first < r.first;  |__l__|     |____r__|
                if (l.second < r.first)
                {
                    //cout << 1 << endl;
                    if ((len1 + len2) % 2)
                    {
                        int mid = (len1 + len2) / 2 + 1;
                        if (len1 < mid)
                            printf("%.1lf\n", num[r.first + mid - len1 - 1] * 1.0);
                        else
                            printf("%.1lf\n", num[l.first + mid - 1] * 1.0);
                    }
                    else
                    {
                        int left = (len1 + len2) / 2;
                        int right = left + 1;
                        int ans = 0;
                        if (left <= len1)
                            ans += num[l.first + left - 1];
                        else
                            ans += num[r.first + left - len1 - 1];

                        if (right <= len1)
                            ans += num[l.first + right - 1];
                        else
                            ans += num[r.first + right - len1 - 1];
                        printf("%.1lf\n", (ans * 1.0) / 2);
                    }
                }
                    // |___l___|____r___|
                else if (l.second == r.first)
                {
                    //cout << 2 << endl;
                    if ((len1 + len2) % 2)
                    {
                        int mid = (len1 + len2) / 2 + 1;
                        if (mid <= len1)
                            printf("%.1lf\n", num[l.first + mid - 1] * 1.0);
                        else if (mid == len1 + 1)
                            printf("%.1lf\n", num[r.first] * 1.0);
                        else
                            printf("%.1lf\n", num[r.first + 1 + mid - len1 - 2] * 1.0);
                    }
                    else
                    {
                        int left = (len1 + len2) >> 1;
                        int right = left + 1;
                        int ans = 0;
                        if (left <= len1)
                            ans += num[l.first + left - 1];
                        else if (left == len1 + 1)
                            ans += num[r.first];
                        else
                            ans += num[r.first + 1 + left - len1 - 2];

                        if (right <= len1)
                            ans += num[l.first + right - 1];
                        else if (right == len1 + 1)
                            ans += num[r.first];
                        else
                            ans += num[r.first + 1 + right - len1 - 2];
                        printf("%.1lf\n", (ans * 1.0) / 2);
                    }
                }
                else if (l.first <= r.first && r.second >= l.second && r.first < l.second && l.second < r.second)
                {
                    //cout << 3 << endl;
                    int llen = r.first - l.first;
                    int rlen = r.second - l.second;
                    int midlen = l.second - r.first + 1;
                    if ((len1 + len2) % 2)
                    {
                        int mid = (len1 + len2) / 2 + 1;
                        if (mid <= llen)
                            printf("%.1lf\n", num[l.first + mid - 1] * 1.0);
                        else if (mid <= llen + midlen * 2 && (mid - llen) % 2)
                            printf("%.1lf\n", num[l.first + llen + (mid - llen + 1) / 2 - 1] * 1.0);
                        else if ((mid <= llen + midlen * 2 && ((mid - llen) % 2) == 0))
                            printf("%.1lf\n", num[l.first + llen + (mid - llen) / 2 - 1] * 1.0);
                        else
                            printf("%.1lf\n", num[l.second + (mid - llen - midlen * 2)] * 1.0);
                    }
                    else
                    {
                        int left = (len1 + len2) / 2;
                        int right = left + 1;
                        int ans = 0;
                        if (left <= llen)
                            ans += num[l.first + left - 1];
                        else if (left <= llen + midlen * 2 && (left - llen) % 2)
                            ans += num[l.first + llen + (left - llen + 1) / 2 - 1];
                        else if ((left <= llen + midlen * 2 && ((left - llen) % 2) == 0))
                            ans += num[l.first + llen + (left - llen) / 2 - 1];
                        else
                            ans += num[l.second + (left - llen - midlen * 2)];

                        if (right <= llen)
                            ans += num[l.first + right - 1];
                        else if (right <= llen + midlen * 2 && (right - llen) % 2)
                            ans += num[l.first + llen + (right - llen + 1) / 2 - 1];
                        else if ((right <= llen + midlen * 2 && ((right - llen) % 2) == 0))
                            ans += num[l.first + llen + (right - llen) / 2 - 1];
                        else
                            ans += num[l.second + (right - llen - midlen * 2)];
                        printf("%.1lf\n", (ans * 1.0) / 2);
                    }
                }
                    //|__l___|___r__|__l__|
                else if (l.first <= r.first && l.second >= r.second)
                {
                    //cout << 4 << endl;
                    int llen = r.first - l.first;
                    int rlen = l.second - r.second;
                    int midlen = r.second - r.first + 1;
                    if ((len1 + len2) % 2)
                    {
                        int mid = (len1 + len2) / 2 + 1;
                        if (mid <= llen)
                            printf("%.1lf\n", num[l.first + mid - 1] * 1.0);
                        else if (mid <= llen + midlen * 2 && (mid - llen) % 2)
                            printf("%.1lf\n", num[r.first + (mid - llen + 1) / 2 - 1] * 1.0);
                        else if (mid <= llen + midlen * 2 && ((mid - llen) % 2) == 0)
                            printf("%.1lf\n", num[r.first + (mid - llen) / 2 - 1] * 1.0);
                        else
                            printf("%.1lf\n", num[r.second + (mid - llen - midlen * 2)] * 1.0);
                    }
                    else
                    {
                        int left = (len1 + len2) / 2;
                        int right = left + 1;
                        int ans = 0;
                        if (left <= llen)
                            ans += num[l.first + left - 1];
                        else if (left <= llen + midlen * 2 && (left - llen) % 2)
                            ans += num[r.first + (left - llen + 1) / 2 - 1];
                        else if (left <= llen + midlen * 2 && ((left - llen) % 2) == 0)
                            ans += num[r.first + (left - llen) / 2 - 1];
                        else
                            ans += num[r.second + (left - llen - midlen * 2)];
                        //printf("%d %d\n", left, ans);
                        if (right <= llen)
                            ans += num[l.first + right - 1];
                        else if (right <= llen + midlen * 2 && (right - llen) % 2)
                            ans += num[r.first + (right - llen + 1) / 2 - 1];
                        else if (right <= llen + midlen * 2 && ((right - llen) % 2) == 0)
                            ans += num[r.first + (right - llen) / 2 - 1];
                        else
                            ans += num[r.second + (right - llen - midlen * 2)];
                        //printf("%d %d\n", right, ans);
                        printf("%.1lf\n", (ans * 1.0) / 2);
                    }
                }
            }
        }
    }
    return 0;
}