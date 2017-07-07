//
// Created by 孙启龙 on 2017/4/2.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
typedef long long  ll;
using namespace std;

string sentences[589]={
 "pron.v.",
 "pron.vi.",
 "pron.adv.v.",
 "pron.adv.vi.",
 "art.n.v.",
 "art.n.vi.",
 "art.n.adv.v.",
 "art.n.adv.vi.",
 "art.adj.n.v.",
 "art.adj.n.vi.",
 "art.adj.n.adv.v.",
 "art.adj.n.adv.vi.",
 "prep.pron.pron.v.",
 "prep.pron.pron.vi.",
 "prep.pron.pron.adv.v.",
 "prep.pron.pron.adv.vi.",
 "prep.pron.art.n.v.",
 "prep.pron.art.n.vi.",
 "prep.pron.art.n.adv.v.",
 "prep.pron.art.n.adv.vi.",
 "prep.pron.art.adj.n.v.",
 "prep.pron.art.adj.n.vi.",
 "prep.pron.art.adj.n.adv.v.",
 "prep.pron.art.adj.n.adv.vi.",
 "prep.art.n.pron.v.",
 "prep.art.n.pron.vi.",
 "prep.art.n.pron.adv.v.",
 "prep.art.n.pron.adv.vi.",
 "prep.art.n.art.n.v.",
 "prep.art.n.art.n.vi.",
 "prep.art.n.art.n.adv.v.",
 "prep.art.n.art.n.adv.vi.",
 "prep.art.n.art.adj.n.v.",
 "prep.art.n.art.adj.n.vi.",
 "prep.art.n.art.adj.n.adv.v.",
 "prep.art.n.art.adj.n.adv.vi.",
 "prep.art.adj.n.pron.v.",
 "prep.art.adj.n.pron.vi.",
 "prep.art.adj.n.pron.adv.v.",
 "prep.art.adj.n.pron.adv.vi.",
 "prep.art.adj.n.art.n.v.",
 "prep.art.adj.n.art.n.vi.",
 "prep.art.adj.n.art.n.adv.v.",
 "prep.art.adj.n.art.n.adv.vi.",
 "prep.art.adj.n.art.adj.n.v.",
 "prep.art.adj.n.art.adj.n.vi.",
 "prep.art.adj.n.art.adj.n.adv.v.",
 "prep.art.adj.n.art.adj.n.adv.vi.",
 "pron.prep.pron.v.",
 "pron.prep.pron.vi.",
 "pron.prep.pron.adv.v.",
 "pron.prep.pron.adv.vi.",
 "pron.prep.art.n.v.",
 "pron.prep.art.n.vi.",
 "pron.prep.art.n.adv.v.",
 "pron.prep.art.n.adv.vi.",
 "pron.prep.art.adj.n.v.",
 "pron.prep.art.adj.n.vi.",
 "pron.prep.art.adj.n.adv.v.",
 "pron.prep.art.adj.n.adv.vi.",
 "art.n.prep.pron.v.",
 "art.n.prep.pron.vi.",
 "art.n.prep.pron.adv.v.",
 "art.n.prep.pron.adv.vi.",
 "art.n.prep.art.n.v.",
 "art.n.prep.art.n.vi.",
 "art.n.prep.art.n.adv.v.",
 "art.n.prep.art.n.adv.vi.",
 "art.n.prep.art.adj.n.v.",
 "art.n.prep.art.adj.n.vi.",
 "art.n.prep.art.adj.n.adv.v.",
 "art.n.prep.art.adj.n.adv.vi.",
 "art.adj.n.prep.pron.v.",
 "art.adj.n.prep.pron.vi.",
 "art.adj.n.prep.pron.adv.v.",
 "art.adj.n.prep.pron.adv.vi.",
 "art.adj.n.prep.art.n.v.",
 "art.adj.n.prep.art.n.vi.",
 "art.adj.n.prep.art.n.adv.v.",
 "art.adj.n.prep.art.n.adv.vi.",
 "art.adj.n.prep.art.adj.n.v.",
 "art.adj.n.prep.art.adj.n.vi.",
 "art.adj.n.prep.art.adj.n.adv.v.",
 "art.adj.n.prep.art.adj.n.adv.vi.",
 "pron.v.prep.pron.",
 "pron.v.prep.art.n.",
 "pron.v.prep.art.adj.n.",
 "pron.vi.prep.pron.",
 "pron.vi.prep.art.n.",
 "pron.vi.prep.art.adj.n.",
 "pron.adv.v.prep.pron.",
 "pron.adv.v.prep.art.n.",
 "pron.adv.v.prep.art.adj.n.",
 "pron.adv.vi.prep.pron.",
 "pron.adv.vi.prep.art.n.",
 "pron.adv.vi.prep.art.adj.n.",
 "art.n.v.prep.pron.",
 "art.n.v.prep.art.n.",
 "art.n.v.prep.art.adj.n.",
 "art.n.vi.prep.pron.",
 "art.n.vi.prep.art.n.",
 "art.n.vi.prep.art.adj.n.",
 "art.n.adv.v.prep.pron.",
 "art.n.adv.v.prep.art.n.",
 "art.n.adv.v.prep.art.adj.n.",
 "art.n.adv.vi.prep.pron.",
 "art.n.adv.vi.prep.art.n.",
 "art.n.adv.vi.prep.art.adj.n.",
 "art.adj.n.v.prep.pron.",
 "art.adj.n.v.prep.art.n.",
 "art.adj.n.v.prep.art.adj.n.",
 "art.adj.n.vi.prep.pron.",
 "art.adj.n.vi.prep.art.n.",
 "art.adj.n.vi.prep.art.adj.n.",
 "art.adj.n.adv.v.prep.pron.",
 "art.adj.n.adv.v.prep.art.n.",
 "art.adj.n.adv.v.prep.art.adj.n.",
 "art.adj.n.adv.vi.prep.pron.",
 "art.adj.n.adv.vi.prep.art.n.",
 "art.adj.n.adv.vi.prep.art.adj.n.",
 "pron.v.pron.",
 "pron.v.art.n.",
 "pron.v.art.adj.n.",
 "pron.vt.pron.",
 "pron.vt.art.n.",
 "pron.vt.art.adj.n.",
 "pron.adv.v.pron.",
 "pron.adv.v.art.n.",
 "pron.adv.v.art.adj.n.",
 "pron.adv.vt.pron.",
 "pron.adv.vt.art.n.",
 "pron.adv.vt.art.adj.n.",
 "art.n.v.pron.",
 "art.n.v.art.n.",
 "art.n.v.art.adj.n.",
 "art.n.vt.pron.",
 "art.n.vt.art.n.",
 "art.n.vt.art.adj.n.",
 "art.n.adv.v.pron.",
 "art.n.adv.v.art.n.",
 "art.n.adv.v.art.adj.n.",
 "art.n.adv.vt.pron.",
 "art.n.adv.vt.art.n.",
 "art.n.adv.vt.art.adj.n.",
 "art.adj.n.v.pron.",
 "art.adj.n.v.art.n.",
 "art.adj.n.v.art.adj.n.",
 "art.adj.n.vt.pron.",
 "art.adj.n.vt.art.n.",
 "art.adj.n.vt.art.adj.n.",
 "art.adj.n.adv.v.pron.",
 "art.adj.n.adv.v.art.n.",
 "art.adj.n.adv.v.art.adj.n.",
 "art.adj.n.adv.vt.pron.",
 "art.adj.n.adv.vt.art.n.",
 "art.adj.n.adv.vt.art.adj.n.",
 "prep.pron.pron.v.pron.",
 "prep.pron.pron.v.art.n.",
 "prep.pron.pron.v.art.adj.n.",
 "prep.pron.pron.vt.pron.",
 "prep.pron.pron.vt.art.n.",
 "prep.pron.pron.vt.art.adj.n.",
 "prep.pron.pron.adv.v.pron.",
 "prep.pron.pron.adv.v.art.n.",
 "prep.pron.pron.adv.v.art.adj.n.",
 "prep.pron.pron.adv.vt.pron.",
 "prep.pron.pron.adv.vt.art.n.",
 "prep.pron.pron.adv.vt.art.adj.n.",
 "prep.pron.art.n.v.pron.",
 "prep.pron.art.n.v.art.n.",
 "prep.pron.art.n.v.art.adj.n.",
 "prep.pron.art.n.vt.pron.",
 "prep.pron.art.n.vt.art.n.",
 "prep.pron.art.n.vt.art.adj.n.",
 "prep.pron.art.n.adv.v.pron.",
 "prep.pron.art.n.adv.v.art.n.",
 "prep.pron.art.n.adv.v.art.adj.n.",
 "prep.pron.art.n.adv.vt.pron.",
 "prep.pron.art.n.adv.vt.art.n.",
 "prep.pron.art.n.adv.vt.art.adj.n.",
 "prep.pron.art.adj.n.v.pron.",
 "prep.pron.art.adj.n.v.art.n.",
 "prep.pron.art.adj.n.v.art.adj.n.",
 "prep.pron.art.adj.n.vt.pron.",
 "prep.pron.art.adj.n.vt.art.n.",
 "prep.pron.art.adj.n.vt.art.adj.n.",
 "prep.pron.art.adj.n.adv.v.pron.",
 "prep.pron.art.adj.n.adv.v.art.n.",
 "prep.pron.art.adj.n.adv.v.art.adj.n.",
 "prep.pron.art.adj.n.adv.vt.pron.",
 "prep.pron.art.adj.n.adv.vt.art.n.",
 "prep.pron.art.adj.n.adv.vt.art.adj.n.",
 "prep.art.n.pron.v.pron.",
 "prep.art.n.pron.v.art.n.",
 "prep.art.n.pron.v.art.adj.n.",
 "prep.art.n.pron.vt.pron.",
 "prep.art.n.pron.vt.art.n.",
 "prep.art.n.pron.vt.art.adj.n.",
 "prep.art.n.pron.adv.v.pron.",
 "prep.art.n.pron.adv.v.art.n.",
 "prep.art.n.pron.adv.v.art.adj.n.",
 "prep.art.n.pron.adv.vt.pron.",
 "prep.art.n.pron.adv.vt.art.n.",
 "prep.art.n.pron.adv.vt.art.adj.n.",
 "prep.art.n.art.n.v.pron.",
 "prep.art.n.art.n.v.art.n.",
 "prep.art.n.art.n.v.art.adj.n.",
 "prep.art.n.art.n.vt.pron.",
 "prep.art.n.art.n.vt.art.n.",
 "prep.art.n.art.n.vt.art.adj.n.",
 "prep.art.n.art.n.adv.v.pron.",
 "prep.art.n.art.n.adv.v.art.n.",
 "prep.art.n.art.n.adv.v.art.adj.n.",
 "prep.art.n.art.n.adv.vt.pron.",
 "prep.art.n.art.n.adv.vt.art.n.",
 "prep.art.n.art.n.adv.vt.art.adj.n.",
 "prep.art.n.art.adj.n.v.pron.",
 "prep.art.n.art.adj.n.v.art.n.",
 "prep.art.n.art.adj.n.v.art.adj.n.",
 "prep.art.n.art.adj.n.vt.pron.",
 "prep.art.n.art.adj.n.vt.art.n.",
 "prep.art.n.art.adj.n.vt.art.adj.n.",
 "prep.art.n.art.adj.n.adv.v.pron.",
 "prep.art.n.art.adj.n.adv.v.art.n.",
 "prep.art.n.art.adj.n.adv.v.art.adj.n.",
 "prep.art.n.art.adj.n.adv.vt.pron.",
 "prep.art.n.art.adj.n.adv.vt.art.n.",
 "prep.art.n.art.adj.n.adv.vt.art.adj.n.",
 "prep.art.adj.n.pron.v.pron.",
 "prep.art.adj.n.pron.v.art.n.",
 "prep.art.adj.n.pron.v.art.adj.n.",
 "prep.art.adj.n.pron.vt.pron.",
 "prep.art.adj.n.pron.vt.art.n.",
 "prep.art.adj.n.pron.vt.art.adj.n.",
 "prep.art.adj.n.pron.adv.v.pron.",
 "prep.art.adj.n.pron.adv.v.art.n.",
 "prep.art.adj.n.pron.adv.v.art.adj.n.",
 "prep.art.adj.n.pron.adv.vt.pron.",
 "prep.art.adj.n.pron.adv.vt.art.n.",
 "prep.art.adj.n.pron.adv.vt.art.adj.n.",
 "prep.art.adj.n.art.n.v.pron.",
 "prep.art.adj.n.art.n.v.art.n.",
 "prep.art.adj.n.art.n.v.art.adj.n.",
 "prep.art.adj.n.art.n.vt.pron.",
 "prep.art.adj.n.art.n.vt.art.n.",
 "prep.art.adj.n.art.n.vt.art.adj.n.",
 "prep.art.adj.n.art.n.adv.v.pron.",
 "prep.art.adj.n.art.n.adv.v.art.n.",
 "prep.art.adj.n.art.n.adv.v.art.adj.n.",
 "prep.art.adj.n.art.n.adv.vt.pron.",
 "prep.art.adj.n.art.n.adv.vt.art.n.",
 "prep.art.adj.n.art.n.adv.vt.art.adj.n.",
 "prep.art.adj.n.art.adj.n.v.pron.",
 "prep.art.adj.n.art.adj.n.v.art.n.",
 "prep.art.adj.n.art.adj.n.v.art.adj.n.",
 "prep.art.adj.n.art.adj.n.vt.pron.",
 "prep.art.adj.n.art.adj.n.vt.art.n.",
 "prep.art.adj.n.art.adj.n.vt.art.adj.n.",
 "prep.art.adj.n.art.adj.n.adv.v.pron.",
 "prep.art.adj.n.art.adj.n.adv.v.art.n.",
 "prep.art.adj.n.art.adj.n.adv.v.art.adj.n.",
 "prep.art.adj.n.art.adj.n.adv.vt.pron.",
 "prep.art.adj.n.art.adj.n.adv.vt.art.n.",
 "prep.art.adj.n.art.adj.n.adv.vt.art.adj.n.",
 "pron.prep.pron.v.pron.",
 "pron.prep.pron.v.art.n.",
 "pron.prep.pron.v.art.adj.n.",
 "pron.prep.pron.vt.pron.",
 "pron.prep.pron.vt.art.n.",
 "pron.prep.pron.vt.art.adj.n.",
 "pron.prep.pron.adv.v.pron.",
 "pron.prep.pron.adv.v.art.n.",
 "pron.prep.pron.adv.v.art.adj.n.",
 "pron.prep.pron.adv.vt.pron.",
 "pron.prep.pron.adv.vt.art.n.",
 "pron.prep.pron.adv.vt.art.adj.n.",
 "pron.prep.art.n.v.pron.",
 "pron.prep.art.n.v.art.n.",
 "pron.prep.art.n.v.art.adj.n.",
 "pron.prep.art.n.vt.pron.",
 "pron.prep.art.n.vt.art.n.",
 "pron.prep.art.n.vt.art.adj.n.",
 "pron.prep.art.n.adv.v.pron.",
 "pron.prep.art.n.adv.v.art.n.",
 "pron.prep.art.n.adv.v.art.adj.n.",
 "pron.prep.art.n.adv.vt.pron.",
 "pron.prep.art.n.adv.vt.art.n.",
 "pron.prep.art.n.adv.vt.art.adj.n.",
 "pron.prep.art.adj.n.v.pron.",
 "pron.prep.art.adj.n.v.art.n.",
 "pron.prep.art.adj.n.v.art.adj.n.",
 "pron.prep.art.adj.n.vt.pron.",
 "pron.prep.art.adj.n.vt.art.n.",
 "pron.prep.art.adj.n.vt.art.adj.n.",
 "pron.prep.art.adj.n.adv.v.pron.",
 "pron.prep.art.adj.n.adv.v.art.n.",
 "pron.prep.art.adj.n.adv.v.art.adj.n.",
 "pron.prep.art.adj.n.adv.vt.pron.",
 "pron.prep.art.adj.n.adv.vt.art.n.",
 "pron.prep.art.adj.n.adv.vt.art.adj.n.",
 "art.n.prep.pron.v.pron.",
 "art.n.prep.pron.v.art.n.",
 "art.n.prep.pron.v.art.adj.n.",
 "art.n.prep.pron.vt.pron.",
 "art.n.prep.pron.vt.art.n.",
 "art.n.prep.pron.vt.art.adj.n.",
 "art.n.prep.pron.adv.v.pron.",
 "art.n.prep.pron.adv.v.art.n.",
 "art.n.prep.pron.adv.v.art.adj.n.",
 "art.n.prep.pron.adv.vt.pron.",
 "art.n.prep.pron.adv.vt.art.n.",
 "art.n.prep.pron.adv.vt.art.adj.n.",
 "art.n.prep.art.n.v.pron.",
 "art.n.prep.art.n.v.art.n.",
 "art.n.prep.art.n.v.art.adj.n.",
 "art.n.prep.art.n.vt.pron.",
 "art.n.prep.art.n.vt.art.n.",
 "art.n.prep.art.n.vt.art.adj.n.",
 "art.n.prep.art.n.adv.v.pron.",
 "art.n.prep.art.n.adv.v.art.n.",
 "art.n.prep.art.n.adv.v.art.adj.n.",
 "art.n.prep.art.n.adv.vt.pron.",
 "art.n.prep.art.n.adv.vt.art.n.",
 "art.n.prep.art.n.adv.vt.art.adj.n.",
 "art.n.prep.art.adj.n.v.pron.",
 "art.n.prep.art.adj.n.v.art.n.",
 "art.n.prep.art.adj.n.v.art.adj.n.",
 "art.n.prep.art.adj.n.vt.pron.",
 "art.n.prep.art.adj.n.vt.art.n.",
 "art.n.prep.art.adj.n.vt.art.adj.n.",
 "art.n.prep.art.adj.n.adv.v.pron.",
 "art.n.prep.art.adj.n.adv.v.art.n.",
 "art.n.prep.art.adj.n.adv.v.art.adj.n.",
 "art.n.prep.art.adj.n.adv.vt.pron.",
 "art.n.prep.art.adj.n.adv.vt.art.n.",
 "art.n.prep.art.adj.n.adv.vt.art.adj.n.",
 "art.adj.n.prep.pron.v.pron.",
 "art.adj.n.prep.pron.v.art.n.",
 "art.adj.n.prep.pron.v.art.adj.n.",
 "art.adj.n.prep.pron.vt.pron.",
 "art.adj.n.prep.pron.vt.art.n.",
 "art.adj.n.prep.pron.vt.art.adj.n.",
 "art.adj.n.prep.pron.adv.v.pron.",
 "art.adj.n.prep.pron.adv.v.art.n.",
 "art.adj.n.prep.pron.adv.v.art.adj.n.",
 "art.adj.n.prep.pron.adv.vt.pron.",
 "art.adj.n.prep.pron.adv.vt.art.n.",
 "art.adj.n.prep.pron.adv.vt.art.adj.n.",
 "art.adj.n.prep.art.n.v.pron.",
 "art.adj.n.prep.art.n.v.art.n.",
 "art.adj.n.prep.art.n.v.art.adj.n.",
 "art.adj.n.prep.art.n.vt.pron.",
 "art.adj.n.prep.art.n.vt.art.n.",
 "art.adj.n.prep.art.n.vt.art.adj.n.",
 "art.adj.n.prep.art.n.adv.v.pron.",
 "art.adj.n.prep.art.n.adv.v.art.n.",
 "art.adj.n.prep.art.n.adv.v.art.adj.n.",
 "art.adj.n.prep.art.n.adv.vt.pron.",
 "art.adj.n.prep.art.n.adv.vt.art.n.",
 "art.adj.n.prep.art.n.adv.vt.art.adj.n.",
 "art.adj.n.prep.art.adj.n.v.pron.",
 "art.adj.n.prep.art.adj.n.v.art.n.",
 "art.adj.n.prep.art.adj.n.v.art.adj.n.",
 "art.adj.n.prep.art.adj.n.vt.pron.",
 "art.adj.n.prep.art.adj.n.vt.art.n.",
 "art.adj.n.prep.art.adj.n.vt.art.adj.n.",
 "art.adj.n.prep.art.adj.n.adv.v.pron.",
 "art.adj.n.prep.art.adj.n.adv.v.art.n.",
 "art.adj.n.prep.art.adj.n.adv.v.art.adj.n.",
 "art.adj.n.prep.art.adj.n.adv.vt.pron.",
 "art.adj.n.prep.art.adj.n.adv.vt.art.n.",
 "art.adj.n.prep.art.adj.n.adv.vt.art.adj.n.",
 "pron.v.prep.pron.pron.",
 "pron.v.prep.pron.art.n.",
 "pron.v.prep.pron.art.adj.n.",
 "pron.v.prep.art.n.pron.",
 "pron.v.prep.art.n.art.n.",
 "pron.v.prep.art.n.art.adj.n.",
 "pron.v.prep.art.adj.n.pron.",
 "pron.v.prep.art.adj.n.art.n.",
 "pron.v.prep.art.adj.n.art.adj.n.",
 "pron.vt.prep.pron.pron.",
 "pron.vt.prep.pron.art.n.",
 "pron.vt.prep.pron.art.adj.n.",
 "pron.vt.prep.art.n.pron.",
 "pron.vt.prep.art.n.art.n.",
 "pron.vt.prep.art.n.art.adj.n.",
 "pron.vt.prep.art.adj.n.pron.",
 "pron.vt.prep.art.adj.n.art.n.",
 "pron.vt.prep.art.adj.n.art.adj.n.",
 "pron.adv.v.prep.pron.pron.",
 "pron.adv.v.prep.pron.art.n.",
 "pron.adv.v.prep.pron.art.adj.n.",
 "pron.adv.v.prep.art.n.pron.",
 "pron.adv.v.prep.art.n.art.n.",
 "pron.adv.v.prep.art.n.art.adj.n.",
 "pron.adv.v.prep.art.adj.n.pron.",
 "pron.adv.v.prep.art.adj.n.art.n.",
 "pron.adv.v.prep.art.adj.n.art.adj.n.",
 "pron.adv.vt.prep.pron.pron.",
 "pron.adv.vt.prep.pron.art.n.",
 "pron.adv.vt.prep.pron.art.adj.n.",
 "pron.adv.vt.prep.art.n.pron.",
 "pron.adv.vt.prep.art.n.art.n.",
 "pron.adv.vt.prep.art.n.art.adj.n.",
 "pron.adv.vt.prep.art.adj.n.pron.",
 "pron.adv.vt.prep.art.adj.n.art.n.",
 "pron.adv.vt.prep.art.adj.n.art.adj.n.",
 "art.n.v.prep.pron.pron.",
 "art.n.v.prep.pron.art.n.",
 "art.n.v.prep.pron.art.adj.n.",
 "art.n.v.prep.art.n.pron.",
 "art.n.v.prep.art.n.art.n.",
 "art.n.v.prep.art.n.art.adj.n.",
 "art.n.v.prep.art.adj.n.pron.",
 "art.n.v.prep.art.adj.n.art.n.",
 "art.n.v.prep.art.adj.n.art.adj.n.",
 "art.n.vt.prep.pron.pron.",
 "art.n.vt.prep.pron.art.n.",
 "art.n.vt.prep.pron.art.adj.n.",
 "art.n.vt.prep.art.n.pron.",
 "art.n.vt.prep.art.n.art.n.",
 "art.n.vt.prep.art.n.art.adj.n.",
 "art.n.vt.prep.art.adj.n.pron.",
 "art.n.vt.prep.art.adj.n.art.n.",
 "art.n.vt.prep.art.adj.n.art.adj.n.",
 "art.n.adv.v.prep.pron.pron.",
 "art.n.adv.v.prep.pron.art.n.",
 "art.n.adv.v.prep.pron.art.adj.n.",
 "art.n.adv.v.prep.art.n.pron.",
 "art.n.adv.v.prep.art.n.art.n.",
 "art.n.adv.v.prep.art.n.art.adj.n.",
 "art.n.adv.v.prep.art.adj.n.pron.",
 "art.n.adv.v.prep.art.adj.n.art.n.",
 "art.n.adv.v.prep.art.adj.n.art.adj.n.",
 "art.n.adv.vt.prep.pron.pron.",
 "art.n.adv.vt.prep.pron.art.n.",
 "art.n.adv.vt.prep.pron.art.adj.n.",
 "art.n.adv.vt.prep.art.n.pron.",
 "art.n.adv.vt.prep.art.n.art.n.",
 "art.n.adv.vt.prep.art.n.art.adj.n.",
 "art.n.adv.vt.prep.art.adj.n.pron.",
 "art.n.adv.vt.prep.art.adj.n.art.n.",
 "art.n.adv.vt.prep.art.adj.n.art.adj.n.",
 "art.adj.n.v.prep.pron.pron.",
 "art.adj.n.v.prep.pron.art.n.",
 "art.adj.n.v.prep.pron.art.adj.n.",
 "art.adj.n.v.prep.art.n.pron.",
 "art.adj.n.v.prep.art.n.art.n.",
 "art.adj.n.v.prep.art.n.art.adj.n.",
 "art.adj.n.v.prep.art.adj.n.pron.",
 "art.adj.n.v.prep.art.adj.n.art.n.",
 "art.adj.n.v.prep.art.adj.n.art.adj.n.",
 "art.adj.n.vt.prep.pron.pron.",
 "art.adj.n.vt.prep.pron.art.n.",
 "art.adj.n.vt.prep.pron.art.adj.n.",
 "art.adj.n.vt.prep.art.n.pron.",
 "art.adj.n.vt.prep.art.n.art.n.",
 "art.adj.n.vt.prep.art.n.art.adj.n.",
 "art.adj.n.vt.prep.art.adj.n.pron.",
 "art.adj.n.vt.prep.art.adj.n.art.n.",
 "art.adj.n.vt.prep.art.adj.n.art.adj.n.",
 "art.adj.n.adv.v.prep.pron.pron.",
 "art.adj.n.adv.v.prep.pron.art.n.",
 "art.adj.n.adv.v.prep.pron.art.adj.n.",
 "art.adj.n.adv.v.prep.art.n.pron.",
 "art.adj.n.adv.v.prep.art.n.art.n.",
 "art.adj.n.adv.v.prep.art.n.art.adj.n.",
 "art.adj.n.adv.v.prep.art.adj.n.pron.",
 "art.adj.n.adv.v.prep.art.adj.n.art.n.",
 "art.adj.n.adv.v.prep.art.adj.n.art.adj.n.",
 "art.adj.n.adv.vt.prep.pron.pron.",
 "art.adj.n.adv.vt.prep.pron.art.n.",
 "art.adj.n.adv.vt.prep.pron.art.adj.n.",
 "art.adj.n.adv.vt.prep.art.n.pron.",
 "art.adj.n.adv.vt.prep.art.n.art.n.",
 "art.adj.n.adv.vt.prep.art.n.art.adj.n.",
 "art.adj.n.adv.vt.prep.art.adj.n.pron.",
 "art.adj.n.adv.vt.prep.art.adj.n.art.n.",
 "art.adj.n.adv.vt.prep.art.adj.n.art.adj.n.",
 "pron.v.pron.prep.pron.",
 "pron.v.pron.prep.art.n.",
 "pron.v.pron.prep.art.adj.n.",
 "pron.v.art.n.prep.pron.",
 "pron.v.art.n.prep.art.n.",
 "pron.v.art.n.prep.art.adj.n.",
 "pron.v.art.adj.n.prep.pron.",
 "pron.v.art.adj.n.prep.art.n.",
 "pron.v.art.adj.n.prep.art.adj.n.",
 "pron.vt.pron.prep.pron.",
 "pron.vt.pron.prep.art.n.",
 "pron.vt.pron.prep.art.adj.n.",
 "pron.vt.art.n.prep.pron.",
 "pron.vt.art.n.prep.art.n.",
 "pron.vt.art.n.prep.art.adj.n.",
 "pron.vt.art.adj.n.prep.pron.",
 "pron.vt.art.adj.n.prep.art.n.",
 "pron.vt.art.adj.n.prep.art.adj.n.",
 "pron.adv.v.pron.prep.pron.",
 "pron.adv.v.pron.prep.art.n.",
 "pron.adv.v.pron.prep.art.adj.n.",
 "pron.adv.v.art.n.prep.pron.",
 "pron.adv.v.art.n.prep.art.n.",
 "pron.adv.v.art.n.prep.art.adj.n.",
 "pron.adv.v.art.adj.n.prep.pron.",
 "pron.adv.v.art.adj.n.prep.art.n.",
 "pron.adv.v.art.adj.n.prep.art.adj.n.",
 "pron.adv.vt.pron.prep.pron.",
 "pron.adv.vt.pron.prep.art.n.",
 "pron.adv.vt.pron.prep.art.adj.n.",
 "pron.adv.vt.art.n.prep.pron.",
 "pron.adv.vt.art.n.prep.art.n.",
 "pron.adv.vt.art.n.prep.art.adj.n.",
 "pron.adv.vt.art.adj.n.prep.pron.",
 "pron.adv.vt.art.adj.n.prep.art.n.",
 "pron.adv.vt.art.adj.n.prep.art.adj.n.",
 "art.n.v.pron.prep.pron.",
 "art.n.v.pron.prep.art.n.",
 "art.n.v.pron.prep.art.adj.n.",
 "art.n.v.art.n.prep.pron.",
 "art.n.v.art.n.prep.art.n.",
 "art.n.v.art.n.prep.art.adj.n.",
 "art.n.v.art.adj.n.prep.pron.",
 "art.n.v.art.adj.n.prep.art.n.",
 "art.n.v.art.adj.n.prep.art.adj.n.",
 "art.n.vt.pron.prep.pron.",
 "art.n.vt.pron.prep.art.n.",
 "art.n.vt.pron.prep.art.adj.n.",
 "art.n.vt.art.n.prep.pron.",
 "art.n.vt.art.n.prep.art.n.",
 "art.n.vt.art.n.prep.art.adj.n.",
 "art.n.vt.art.adj.n.prep.pron.",
 "art.n.vt.art.adj.n.prep.art.n.",
 "art.n.vt.art.adj.n.prep.art.adj.n.",
 "art.n.adv.v.pron.prep.pron.",
 "art.n.adv.v.pron.prep.art.n.",
 "art.n.adv.v.pron.prep.art.adj.n.",
 "art.n.adv.v.art.n.prep.pron.",
 "art.n.adv.v.art.n.prep.art.n.",
 "art.n.adv.v.art.n.prep.art.adj.n.",
 "art.n.adv.v.art.adj.n.prep.pron.",
 "art.n.adv.v.art.adj.n.prep.art.n.",
 "art.n.adv.v.art.adj.n.prep.art.adj.n.",
 "art.n.adv.vt.pron.prep.pron.",
 "art.n.adv.vt.pron.prep.art.n.",
 "art.n.adv.vt.pron.prep.art.adj.n.",
 "art.n.adv.vt.art.n.prep.pron.",
 "art.n.adv.vt.art.n.prep.art.n.",
 "art.n.adv.vt.art.n.prep.art.adj.n.",
 "art.n.adv.vt.art.adj.n.prep.pron.",
 "art.n.adv.vt.art.adj.n.prep.art.n.",
 "art.n.adv.vt.art.adj.n.prep.art.adj.n.",
 "art.adj.n.v.pron.prep.pron.",
 "art.adj.n.v.pron.prep.art.n.",
 "art.adj.n.v.pron.prep.art.adj.n.",
 "art.adj.n.v.art.n.prep.pron.",
 "art.adj.n.v.art.n.prep.art.n.",
 "art.adj.n.v.art.n.prep.art.adj.n.",
 "art.adj.n.v.art.adj.n.prep.pron.",
 "art.adj.n.v.art.adj.n.prep.art.n.",
 "art.adj.n.v.art.adj.n.prep.art.adj.n.",
 "art.adj.n.vt.pron.prep.pron.",
 "art.adj.n.vt.pron.prep.art.n.",
 "art.adj.n.vt.pron.prep.art.adj.n.",
 "art.adj.n.vt.art.n.prep.pron.",
 "art.adj.n.vt.art.n.prep.art.n.",
 "art.adj.n.vt.art.n.prep.art.adj.n.",
 "art.adj.n.vt.art.adj.n.prep.pron.",
 "art.adj.n.vt.art.adj.n.prep.art.n.",
 "art.adj.n.vt.art.adj.n.prep.art.adj.n.",
 "art.adj.n.adv.v.pron.prep.pron.",
 "art.adj.n.adv.v.pron.prep.art.n.",
 "art.adj.n.adv.v.pron.prep.art.adj.n.",
 "art.adj.n.adv.v.art.n.prep.pron.",
 "art.adj.n.adv.v.art.n.prep.art.n.",
 "art.adj.n.adv.v.art.n.prep.art.adj.n.",
 "art.adj.n.adv.v.art.adj.n.prep.pron.",
 "art.adj.n.adv.v.art.adj.n.prep.art.n.",
 "art.adj.n.adv.v.art.adj.n.prep.art.adj.n.",
 "art.adj.n.adv.vt.pron.prep.pron.",
 "art.adj.n.adv.vt.pron.prep.art.n.",
 "art.adj.n.adv.vt.pron.prep.art.adj.n.",
 "art.adj.n.adv.vt.art.n.prep.pron.",
 "art.adj.n.adv.vt.art.n.prep.art.n.",
 "art.adj.n.adv.vt.art.n.prep.art.adj.n.",
 "art.adj.n.adv.vt.art.adj.n.prep.pron.",
 "art.adj.n.adv.vt.art.adj.n.prep.art.n.",
 "art.adj.n.adv.vt.art.adj.n.prep.art.adj.n."
 "prep.art.n."
 };

set<string> st;
void init() {
    rep(i,0,587) st.insert(sentences[i]);
}

int n,m;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    while(SII(n,m)==2) {
        map<string,string> mp;
        rep(i,1,n) {
            string s,t;
            cin >> s >> t;
            mp[s]=t;
            // cout << s <<' ' <<  mp[s] << endl;
        }
        string s;
        string tt;
        while (cin >> s) {
            // cout << s << endl;
            rep(i,0,s.size()-1) if (s[i]>='A' && s[i]<='Z') s[i]+=32;
            int flag=0;
            if (s[s.size()-1]=='.') flag=1;
            else if (s[s.size()-1]==',') flag=2;
            if (flag) {
                string t;
                rep(i,0,s.size()-2) t+=s[i];
                s=t;
            }
            tt+=mp[s];
            if (flag==1) {
                // cout << tt << endl;
                if (st.count(tt)) puts("YES");
                else puts("NO");
                tt.clear();
            }
        }
    }
    return 0;
}