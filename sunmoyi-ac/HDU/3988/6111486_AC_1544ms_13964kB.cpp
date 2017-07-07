#include<iostream>
#include<cstdio>
const int maxn = 10000000 + 5;
using namespace std;
bool flag[maxn];
int cnt=0,prime[maxn];
void Init()
{
	for(int i=2;i<=maxn;i++)
    {
		if(flag[i])
			continue;

        prime[cnt++]=i;
		for(int j=2;j*i<=10000000;j++)
			flag[i*j]=true;
	}

}
long long  get(long long n,long long p)
{
	long long ret=0;
	while(n)
    {
		n/=p;
		ret+=n;
	}
	return ret;
}
int main()
{
	int t,tt = 0;
	scanf("%d",&t);
	Init();
	while(t--)
    {
		long long n,k;
		scanf("%I64d %I64d",&n,&k);
		if(k==1)
		{
			printf("Case %d: inf\n",++tt);
			continue;
		}
		long long imax=-1;
		for(int i=0;i<cnt&&prime[i]<=k;i++)
		{
			if(k%prime[i]==0)
			{
				int ek=0;
				while(k%prime[i]==0)
				{
					ek++;
					k /= prime[i];
				}
                long long en = get(n,prime[i]);
				long long  tmp=en/ek;
				if(imax==-1)
					imax=tmp;
				else
					imax=min(imax,tmp);
			}
		}
		if(k>1)
        {
			long long en= get(n,k);
            int ek = 1;
             long long tmp = en/ek;
			if(imax==-1)
				imax=tmp;
			else
				imax=min(imax,tmp);
		}
		printf("Case %d: %I64u\n",++tt,imax);
	}
	return 0;
}

