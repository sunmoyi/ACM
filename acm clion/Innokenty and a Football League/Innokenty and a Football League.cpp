//
// Created by 孙启龙 on 2017/3/6.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#define maxn 1010

using namespace std;

struct Name{
    string fst, sec, ans;
    int idx;
}src[maxn];
int n;
map<string, int>cntFst, cntSec, sht;

bool cmp(Name a, Name b)
{
    return cntFst[a.fst] > cntFst[b.fst];
}

bool cmp_sht(Name a, Name b)
{
    return sht[a.fst] > sht[b.fst];
}

bool cmp_idx(Name a, Name b)
{
    return a.idx < b.idx;
}

int round(int idx)
{
    sort(src+idx, src+n, cmp_sht);
    if(sht[src[idx].fst] == 0)
        return idx;
    for(;idx<n;idx++)
    {
        if(sht[src[idx].fst] == 1)
        {
            if(sht[ src[idx].sec ] == 1)
                return -1;
            src[idx].ans = src[idx].sec;
            sht[ src[idx].ans ] = 1;
        }
        else
            break;
    }
    return round(idx);
}

bool solve()
{
    int idx;
    for(idx = 0;idx<n;idx++)
    {
        if(cntFst[src[idx].fst] > 1)
        {
            if(cntSec[src[idx].sec] == 1)
                return false;
            else
                src[idx].ans = src[idx].sec,
                cntSec[ src[idx].ans ] = 1,
                sht[ src[idx].ans ] = 1;
        }
        else
            break;
    }
    idx = round(idx);
    if(idx == -1)
        return false;
    for(;idx < n;idx++)
        src[idx].ans = src[idx].fst;
    return true;
}

int main (void)
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> src[i].fst >> src[i].sec;
        src[i].idx = i;
        src[i].sec = src[i].fst.substr(0, 2) + src[i].sec[0];
        src[i].fst = src[i].fst.substr(0, 3);
        cntFst[src[i].fst]++;
    }
    sort(src, src + n, cmp);

    bool flag = solve();
    printf("%s\n", flag? "YES": "NO");
    if(flag)
    {
        sort(src, src + n, cmp_idx);
        for(int i = 0; i < n; i++)
            cout << src[i].ans << endl;
    }
    return 0;
}