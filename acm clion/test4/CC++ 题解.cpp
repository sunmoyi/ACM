//
// Created by moyicoder on 2017/4/13.
// because of the coding format I can't use chinese in the code, sorry

// A    note: water problem
/*
#include<cstdio>

using namespace std;

int main (void)
{
    double cost = 0, price, rate;
    for(int i = 1; i <= 50; i++)
        scanf("%lf %lf", &price, &rate), cost += price * rate / 100;
    printf("%d\n", int(price + 99.9999999)/ 100);
}
*/

// B    note: prime-test
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10000000
using namespace std;

bool isprime[maxn];

//prime2()
int mindiv[maxn];
int prime_count;
int prime[maxn];

void prime1()
{
    memset(isprime, true, sizeof(isprime));
    for(int i = 2; i < maxn; i++)
    {
        if(isprime[i])
        {
            for(int j = 2; i * j < maxn; j++)
                isprime[i * j] = false;
        }
    }
    isprime[1] = false;
}

void prime2()
{
    memset(isprime, false, sizeof(isprime));
    for (int i = 2; i < maxn; i++)
    {
        if (mindiv[i] == 0)
        {
            prime[prime_count++] = i;
            isprime[i] = true;
        }
        for (int j = 0; j < prime_count && i * prime[j] < maxn; j++)
        {
            mindiv[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main (void)
{
    //the time complexity of first function is O(NlogN)
    //the second one is O(N) but it's hard to understand
    //you can choose anyone to calculate the primer array

    prime1();
    //prime2();

    for(int start = 2; start < 1000; start++)
    {
        for(int step = 1; step < 10000; step++)
        {
            bool flag = true;
            for(int i = 0; i < 10; i++)
            {
                if(!isprime[start + step * i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                printf("%d\n", start);
                return 0;
            }
        }
    }
    return 0;
}
*/

// C    note: tree
/*
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

double map[50][50];

int main (void)
{
    for(int i = 1; i <= 29; i++)
        for(int j = 1; j <= i; j++)
            scanf("%lf", &map[i][j]);

    for(int i = 2; i <= 30; i++)
        for(int j = 1; j <= i; j++)
            map[i][j] += (map[i - 1][j - 1] + map[i - 1][j]) / 2;

    double minn = min(map[30][1], map[30][30]);
    double maxx = -1;
    for(int i = 1; i <= 30; i++)
        maxx = max(maxx, map[30][i]);
    double rate = 2086458231.0 / minn;
    printf("%lf\n", maxx * rate);
    return 0;
}
*/

// D    note: search
/*
 * ans is 503
 */

// E    note: recursive
/*
 * f(x / 10, k)
 */

// F    note: dynamic programming (LCS)
/*
 * dp[i][j] = dp[i - 1][j - 1] + 1;
 */

// G     note: water problem
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int month1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a, b, c;
vector<int>ans[4];
int num = 0;

void check1()
{
    int newa = a < 60 ? 1900 + a: 2000 + a, newb = b, newc = c;
    if(((newa % 4 == 0 && newa % 100 != 0) || (newa % 400 == 0)) && newb <= 12 && newc <= month2[newb])
        ans[num][0] = newa, ans[num][1] = newb, ans[num++][2] = newc;
    if(!((newa % 4 == 0 && newa % 100 != 0) || (newa % 400 == 0)) && newb <= 12 && newc <= month1[newb])
        ans[num][0] = newa, ans[num][1] = newb, ans[num++][2] = newc;
}

void check2()
{
    int newa = c < 60 ? 1900 + c: 2000 + c, newb = a, newc = b;
    if(((newa % 4 == 0 && newa % 100 != 0) || (newa % 400 == 0)) && newb <= 12 && newc <= month2[newb])
        ans[num][0] = newa, ans[num][1] = newb, ans[num++][2] = newc;
    if(!((newa % 4 == 0 && newa % 100 != 0) || (newa % 400 == 0)) && newb <= 12 && newc <= month1[newb])
        ans[num][0] = newa, ans[num][1] = newb, ans[num++][2] = newc;
}

void check3()
{
    int newa = c < 60 ? 1900 + c: 2000 + c, newb = b, newc = a;
    if(((newa % 4 == 0 && newa % 100 != 0) || (newa % 400 == 0)) && newb <= 12 && newc <= month2[newb])
        ans[num][0] = newa, ans[num][1] = newb, ans[num++][2] = newc;
    if(!((newa % 4 == 0 && newa % 100 != 0) || (newa % 400 == 0)) && newb <= 12 && newc <= month1[newb])
        ans[num][0] = newa, ans[num][1] = newb, ans[num++][2] = newc;
}

int main (void)
{
    scanf("%d%*c%d%*c%d", &a, &b, &c);
    check1();
    check2();
    check3();
    sort(ans, ans + num);
    for(int i = 0; i < num; i++)
    {
        printf("%d-%d-%d-n", ans[i][0], ans[i][1], ans[i][2]);
        if(ans[i] == ans[i + 1])
            i++;
    }
    return 0;
}
*/

// H    note: dynamic programming (bag problem) &&  Goldbach conjecture
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000

using namespace std;

int dp[maxn];
int a[200],n,i,j,res,mark;

bool judge(int x,int y)
{
    return (y == 0)? ((x == 1)? true: false): judge(y, x % y);
}
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(judge(a[i], a[j]))
                {
                    mark = 1;
                    break;
                }
            }
            if(mark == 1)
                break;
        }
        if(mark != 1)
        {
            printf("INF\n");
            continue;
        }
        dp[0] = 1;
        for(i = 1; i <= n; i++)
        {
            for(j = a[i]; j < 10000; j++)
            {
                if(dp[j-a[i]] == 1)
                    dp[j] = 1;
            }
        }
        for(i = 0; i < 10000; i++)
        {
            if(dp[i] != 1)
                res++;
        }
        printf("%d\n", res);
    }
    return 0;
}
*/

// I    note: binary search!!!!!!!   We shoule know that the speed for our cpu is about 10^9 IPOS (one core, -O1 majorization)
//      special for this problem, the time complexity of your code should lower than O(NlongN) or equal.
/*
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

pair<int, int>rectangle[100000];
int n, k, maxx = -1;

bool check(int x)
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        int a = rectangle[i].first / x;
        int b = rectangle[i].second / x;
        sum += a * b;
    }
    return sum >= k;
}

int main (void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &rectangle[i].first, &rectangle[i].second), maxx = max(maxx, min(rectangle[i].first, rectangle[i].second));

    int left = 1, right = maxx, ans = left;
    while(left <= right)
    {
        int mid = (left + right) + 1;
        if(check(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }
    printf("%d\n", ans);
}
*/

// J    note: dynamic programming(line DP)!!!!!  focus on the time complexity;
//      I will use three ways to solve this question, each one has different time complexity
//      because of the time limit, only the last one can pass the final test!!!!!!

// first way   O(N^3)
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn];
int n, k, ans;

int main (void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d\n", &num[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; i++)
        {
            int temp = 0;
            for(int k = i; k <= j; k++)
            {
                temp += num[k];
            }
            if(temp % k == 0)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
*/

//second way O(N^2)
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int num[maxn];
int sum[maxn];
int n, k, ans;

int main (void)
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d\n", &num[i]), sum[i] = sum[i - 1] + num[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; i++)
        {
            int temp = sum[j] - sum[i - 1];
            if(temp % k == 0)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
*/

//third way  O(N)
// note:Pigeonhole principle   or     dynamic programming
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100010

using namespace std;

int mod[maxn];
int num[maxn];
int sum[maxn];
int n, k, ans;

int main (void)
{
    sum[0] = 1;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        mod[i] = (mod[i - 1] + num[i]) % k;
        ans += sum[mod[i]];
        sum[mod[i]]++;
    }
    printf("%d\n", ans);
    return 0;
}
*/


//because of the coding format I can't use chinese in the code, sorry again.
