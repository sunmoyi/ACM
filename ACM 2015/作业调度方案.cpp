#include <stdio.h>
#define max(a, b) ((a)>(b)?(a):(b))
int order[361];
int mch[19][19];
int time[19][19];
int count[19];
int cpu[19][400];
int used[19];
int ans;

int main(void)
{
	int i, j, k, c, l;
	int m, n, t, s;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m * n; i++) {
		scanf("%d", &order[i]);
		order[i]--;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//把n写成了m         
			scanf("%d", &mch[i][j]);
			mch[i][j]--;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			//把n写成了m         
			scanf("%d", &time[i][j]);
		}
	}
	for (i = 0; i < m * n; i++) {
		t = order[i];
		s = count[t]++;
		k = used[t];
		while (1) {
			while (cpu[mch[t][s]][k]) {
				k++;
			}
			c = 0;
			while (cpu[mch[t][s]][k + c] == 0 && c < time[t][s]) {
				c++;
			}
			if (c == time[t][s]) {
				c = 0;
				while (c < time[t][s]) {
					cpu[mch[t][s]][k + c] = 1;
					c++;
				}
				break;
			}
			k += c;
		}
		used[t] = k + time[t][s];
		ans = max(ans, used[t]);
	}
	printf("%d\n", ans);
	return 0;
}