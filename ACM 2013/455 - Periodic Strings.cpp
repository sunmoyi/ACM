#include <stdio.h>  
#include <string.h>  

int isTthePeriod(char s[], int T) {
	for (int i = 0; i < T; i++) {
		for (int j = i + T; j < strlen(s); j += T)
			if (s[i] != s[j]) 
				return 0;
	}
	return 1;
}

int main() {
	int T, kase, len, i;
	scanf("%d", &T);

	for (kase = 1; kase <= T; kase++)
	{
		char s[100];
		while (scanf("%s", s), len = strlen(s), !len);

		for (i = 1; i <= len; i++)
			if (len%i == 0 && isTthePeriod(s, i)) break;
		if (kase != 1) putchar('\n');
		printf("%d\n", i);
	}
	return 0;
}