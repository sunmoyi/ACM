//
// Created by 孙启龙 on 2017/4/2.
//

#include<cstdio>
#include<cstring>
#include<vector>
#define LL long long
#define maxn 2000005
using namespace std;
struct node{
    int sum,son[26],cnt;//cnt 为前缀
}no[maxn];
struct str{
    int start,en;
    str(int s,int e):start(s),en(e){};
    str(){};
};
vector<str>ve;
int fla[maxn][2],nexta[maxn],tot = 0,n,pre,l;
char s[maxn],t[maxn];
void getNext(char *a,int la)
{
    int i=0,j=-1;
    nexta[0] = -1;
    while(i<la)
    {
        if(j==-1||a[i]==a[j])
        {
            i++;
            j++;
            nexta[i] = j;
        }
        else j = nexta[j];
    }
}
void kmp(int flag,char *a,char *b,int la,int start)//0前缀 1后缀
{
    int i=0,j=0;
    while(i<la)
    {
        if(j==-1||a[j]==b[i])
        {
            i++;
            j++;
        }
        else j = nexta[j];
    }
    if(flag==0)//前缀
    {
        int pre = j;
        while(pre)
        {
            fla[start+pre-1][0] = 1;
            pre = nexta[pre];
        }
    }
    else
    {  //后缀
        int pre = j;
        while(pre)
        {
            fla[start+l-pre][1] = 1;
            pre = nexta[pre];
        }
    }
}
void insertTire(int pre,char *a,int start,int la)//储存前缀
{
    for(int i=0;i<l;i++)
    {
        if(!no[pre].son[a[i]-'a'])
        {
            tot++;
            no[pre].son[a[i]-'a'] = tot;
            pre = tot;
        }
        else pre = no[pre].son[a[i]-'a'];
        if(i+1<la)no[pre].cnt+=fla[start+i+1][1];
    }
    no[pre].sum++;
}
LL findTire(int start,int en,int pre)
{
    int sym = true;
    LL ans = 0;
    int l = en-start;
    for(int i=start;i<en;i++)
    {
        if(no[pre].son[t[i]-'a'])
        {
            pre = no[pre].son[t[i]-'a'] ;
            if(fla[start+l-(i-start+1)-1][0]||i==en-1)
            {
                ans+=no[pre].sum;
            }
        }
        else
        {
            sym = false;
            break;
        }
    }
    if(sym)ans+=no[pre].cnt;
    return ans;
}
int main()
{
    pre = 0;
    scanf("%d",&n);
    LL ans = 0;
    while(n--)
    {
        scanf("%d %s",&l,s+pre);
        ve.push_back(str(pre,pre+l));
        for(int i=pre;i<pre+l;i++)
        {
            t[i] = s[pre+l-(i-pre+1)];
        }
        getNext(s+pre,l);
        kmp(0,s+pre,t+pre,l,pre);
        getNext(t+pre,l);
        kmp(1,t+pre,s+pre,l,pre);
        insertTire(0,s+pre,pre,l);
        pre+=l;
    }
    for(int i=0;i<ve.size();i++)
        ans+=findTire(ve[i].start,ve[i].en,0);
    printf("%I64d\n",ans);
}