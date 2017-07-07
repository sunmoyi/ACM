#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;
struct node
{
    string s;
    int num;
    int ma,mi;
}p[205];


bool cmp(node a,node b)
{
    ///if(a.num == a.num)
      //  return a.s < b.s;
    //else
    if(a.num != b.num)
        return a.num > b.num;
    else
        return a.s < b.s;
}
int main()
{
    ios_base::sync_with_stdio(0);//关掉同步
    int n,m;
    while(~scanf("%d",&n) && n)
    {
        for(int i = 0;i < n;i++)
            cin >> p[i].s >> p[i].num;
        sort(p,p+n,cmp);
        for(int i = 0;i < n;i++)
            cout<<p[i].s <<" " <<p[i].num<<endl;

        for(int i = 0;i < n;i++)
        {
            if(i == 0)
                p[i].ma = 1,p[i].mi = 1;
            else
            {
                int pos = i-1;
                while(p[i].num >= p[pos].num && pos >= 0)
                    pos--;
                if(pos == i-1)
                    p[i].ma = i+1;
                else
                    p[i].ma = pos+2;
                pos = i-1;
                p[i].mi = 1;
                while(pos >= 0 && p[i].num == p[pos--].num)
                     p[i].mi++;
            }
        }

        cin >> m;
        string str;
        while(m--)
        {
            cin >> str;
            for(int j = 0;j < n;j++)
            {
                if(p[j].s == str)
                {
                    cout<<p[j].ma;
                    if(p[j].mi != 1)
                        cout<<" "<<p[j].mi<<endl;
                    else
                        cout<<endl;
                    break;
                }
            }
        }

    }
    return 0;
}
