//
// Created by 孙启龙 on 2017/3/10.
//

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define maxn (100010)
#define left lleft
#define right rright

using namespace std;

typedef long long lint;

int a[maxn], _top, left[maxn], right[maxn];
pair<int, int> _stack[maxn];
lint sum[maxn];

int main()
{
    int n, first = 1;
    while(cin >> n)
    {
        if(first) first = 0;
        else cout << endl;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sum[0] = 0;
        for(int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        _top = 0;
        for(int i = 1; i <= n; i++)
        {
            while(_top > 0)
            {
                if(_stack[_top].first < a[i])
                    break;
                _top--;
            }
            if(!_top)
                left[i] = 0;
            else
                left[i] = _stack[_top].second;
            ++_top;
            _stack[_top] = make_pair(a[i], i);
        }
        _top = 0;
        for(int i = n; i >= 1; i--)
        {
            while(_top > 0)
            {
                if(_stack[_top].first < a[i])
                    break;
                _top--;
            }
            if(!_top)
                right[i] = n + 1;
            else
                right[i] = _stack[_top].second;
            ++_top;
            _stack[_top] = make_pair(a[i], i);
        }
        lint o = -1, cmp;
        int l, r;
        for(int i = 1; i <= n; i++)
        {
            cmp = (sum[right[i] - 1] - sum[left[i]]) * a[i];
            if(cmp > o)
            {
                o = cmp;
                l = left[i] + 1;
                r = right[i] - 1;
            }
        }
        cout << o << endl;
        cout << l << " " << r << endl;
    }
    return 0;
}