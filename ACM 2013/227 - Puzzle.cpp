#include <cstdio>  
#include <algorithm>  
using namespace std;

int x, y;
char s[6][6];

void output() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j < 5; j++)
			printf("%c ", s[i][j]);
		printf("%c\n", s[i][5]);
	}
}

int ok(char ch) {
	switch (ch) {
	case 'A':
		if (x == 1) return 0; else x--;
		swap(s[x][y], s[x + 1][y]); break;
	case 'B':
		if (x == 5) return 0; else x++;
		swap(s[x][y], s[x - 1][y]); break;
	case 'L':
		if (y == 1) return 0; else y--;
		swap(s[x][y], s[x][y + 1]); break;
	case 'R':
		if (y == 5) return 0; else y++;
		swap(s[x][y], s[x][y - 1]); break;
	}
	return 1;
}

int test() {
	char ch;
	int i, j;
	for (i = 1; i <= 5; i++) for (j = 1; j <= 5; j++)
		if (s[i][j] == ' ') x = i, y = j;

	while ((ch = getchar()) != '0') {
		if (ch == '\n') continue;
		if (!ok(ch)) {   
			while (getchar() != '0');
			return 0;
		}
	}

	return 1;
}

int main() {
	int kase, i, j;

	for (kase = 1;; kase++) {
		gets(&s[1][1]);
		if (s[1][1] == 0) { kase--; continue; }   // 注意此处读到空串，要忽略读入continue  
		if (s[1][1] == 'Z' && s[1][2] == 0) break;

		if (kase != 1) putchar('\n');
		printf("Puzzle #%d:\n", kase);
		for (i = 2; i <= 5; i++) gets(&s[i][1]);
		if (test()) output();
		else printf("This puzzle has no final configuration.\n");
	}
	return 0;
}