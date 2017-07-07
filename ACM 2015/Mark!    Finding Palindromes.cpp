//http://blog.csdn.net/pi9nc/article/details/12524647
#include<stdio.h>  
#include<algorithm>  
#include<string.h>  
#define ll __int64  
#include<vector>  
using namespace std;

const int maxn = 2222222;
char vec[maxn];
int g[maxn], nxt[maxn];
bool li[maxn];
int ok[maxn], p[maxn];
void get_p(const char *T) {
	int len = strlen(T), a = 0;
	int i, k;
	p[0] = len;
	while (a<len - 1 && T[a] == T[a + 1]) a++;
	p[1] = a;
	a = 1;
	for (k = 2; k<len; k++) {
		int fuck = a + p[a] - 1, L = p[k - a];
		if ((k - 1) + L >= fuck) {
			int j = (fuck - k + 1)>0 ? (fuck - k + 1) : 0;
			while (k + j<len && T[k + j] == T[j]) j++;
			p[k] = j;
			a = k;
		}
		else p[k] = L;
	}
}

void match(char *s, char *s1) {
	int len = strlen(s), len1 = strlen(s1);
	int i = 0, k, j = 0, a;
	while (i < len && j < len1 && s[i] == s1[j]) i++, j++;
	ok[0] = j;
	a = 0;
	for (k = 1; k < len; k++) {
		int fuck = a + ok[a] - 1, l = p[k - a];
		if (k + l - 1 >= fuck) {
			int j = (fuck - k + 1) > 0 ? (fuck - k + 1) : 0;
			while (k + j < len && j < len1 && s[k + j] == s1[j]) j++;
			ok[k] = j;
			a = k;
		}
		else ok[k] = l;
	}
}

int tot = 0, c[26][maxn], cnt[maxn], val[maxn];

int new_node() {
	int i;
	for (i = 0; i < 26; i++) c[i][tot] = 0;
	cnt[tot] = val[tot] = 0;
	return tot++;
}

void insert(char *s) {
	int len = strlen(s), i, now = 0;
	for (i = 0; i < len; i++) {
		int k = s[i] - 'a';
		if (!c[k][now]) c[k][now] = new_node();
		now = c[k][now];
		if (i + 1 < len && ok[i + 1] == len - i - 1) {
			cnt[now] ++;
		}
	}
	cnt[now] ++;
	val[now] ++;
}

ll ans = 0;

void cal(int len) {
	int j, i, now = 0;
	li[len + 1] = 1;
	//  printf ( "len = %d\n" , len ) ;  
	//  for ( i = 1 ; i <= len ; i ++ ) printf ( "%d " , nxt[i] ) ; puts ( "" ) ;  
	for (j = 1; j <= len; j++) {
		//  printf ( "j = %d , ans = %I64d\n" , j , ans ) ;  
		if (li[j]) now = 0;
		int k = vec[j] - 'a';
		if (!c[k][now]) {
			now = 0;
			//      printf ( "nxt[%d] = %d\n" , j , nxt[j] ) ;  
			j = nxt[j] - 1;
			continue;
		}
		now = c[k][now];
		if (!li[j + 1] && g[j + 1]) ans += (ll)val[now];
		//      printf ( "j = %d , now = %d\n" , j , now ) ;  
		if (li[j + 1]) {
			//      if ( j == 10 ) printf ( "cnt[%d] = %d\n" , now , cnt[now] ) ;  
			ans += (ll)cnt[now];
			now = 0;
		}
	}
}

char s1[maxn], s[maxn];

int main() {
	int n, i, j, k;
	while (scanf("%d", &n) != EOF) {
		tot = 0;
		new_node();
		int t = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d%s", &j, s);
			strcpy(s1, s);
			int len = strlen(s);
			reverse(s1, s1 + len);
			get_p(s1);
			match(s, s1);
			insert(s);
			get_p(s);
			match(s1, s);
			li[t + 1] = 1;
			for (j = 0; j < len; j++) {
				if (ok[j] == len - j) g[++t] = 1;
				else g[++t] = 0;
				vec[t] = s1[j];
				if (j) li[t] = 0;
			}
		}
		//    for ( i = 1 ; i < t ; i ++ ) printf ( "%d " , cnt[i] ) ; puts ( "" ) ;  
		int last = t + 1;
		//  for ( i = 1 ; i <= t ; i ++ ) printf ( "%d " , li[i] ) ; puts ( "" ) ;  
		for (i = t; i >= 1; i--) {
			nxt[i] = last;
			if (li[i]) last = i;
		}
		//      for ( i = 1 ; i <= t ; i ++ ) printf ( "%d " , nxt[i] ) ; puts ( "" ) ;  
		ans = 0;
		cal(t);
		printf("%I64d\n", ans);
	}
}