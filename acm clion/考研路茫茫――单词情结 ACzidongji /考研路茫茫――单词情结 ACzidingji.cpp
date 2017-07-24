//
// Created by 孙启龙 on 2017/4/5.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
struct Matrix
{
    unsigned long long mat[40][40];
    int n;
    Matrix(){}
    Matrix(int _n)
    {
        n=_n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j] = 0;
    }

    Matrix operator *(const Matrix &b)const
    {
        Matrix ret = Matrix(n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    ret.mat[i][j]+=mat[i][k]*b.mat[k][j];
        return ret;
    }
};
unsigned long long pow_m(unsigned long long a,int n)
{
    unsigned long long ret=1;
    unsigned long long tmp = a;
    while(n)
    {
        if(n&1)ret*=tmp;
        tmp*=tmp;
        n>>=1;
    }
    return ret;
}
Matrix pow_M(Matrix a,int n)
{
    Matrix ret = Matrix(a.n);
    for(int i=0;i<a.n;i++)
        ret.mat[i][i] = 1;
    Matrix tmp = a;
    while(n)
    {
        if(n&1)ret=ret*tmp;
        tmp=tmp*tmp;
        n>>=1;
    }
    return ret;
}
struct ACAutoMachine
{
    int next[40][26],fail[40];
    bool end[40];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = false;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][buf[i]-'a'] == -1)
                next[now][buf[i]-'a'] = newnode();
            now = next[now][buf[i]-'a'];
        }
        end[now] = true;
    }
    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if(end[fail[now]])
				end[now]=true;
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }

    Matrix getMatrix()
    {
        Matrix ret = Matrix(L+1);
        for(int i = 0;i < L;i++)
            for(int j = 0;j < 26;j++)
                if(!end[next[i][j]])
                    ret.mat[i][next[i][j]] ++;
        for(int i = 0;i < L+1;i++)
            ret.mat[i][L] = 1;
        return ret;
    }
};

char buf[10];
ACAutoMachine ac;

int main()
{
    int n,L;
    while(scanf("%d %d",&n, &L)==2)
    {
        ac.init();
        for(int i = 0;i < n;i++)
        {
            scanf("%s",buf);
            ac.insert(buf);
        }
        ac.build();
        Matrix a = ac.getMatrix();
        a = pow_M(a,L);
        unsigned long long res = 0;
        for(int i = 0;i < a.n;i++)
            res += a.mat[0][i];
        res--;

        /*
         * f[n]=1 + 26^1 + 26^2 +...26^n
         * f[n]=26*f[n-1]+1
         * {f[n] 1} = {f[n-1] 1}[26 0;1 1]
         * 数是f[L]-1;
         * 此题的L<2^31.矩阵的幂不能是L+1次，否则就超时了
         */
        a = Matrix(2);
        a.mat[0][0]=26;
        a.mat[1][0] = a.mat[1][1] = 1;
        a=pow_M(a,L);
        unsigned long long ans=a.mat[1][0]+a.mat[0][0];
        ans--;
        ans-=res;
        cout<<ans<<endl;
    }
    return 0;
}
