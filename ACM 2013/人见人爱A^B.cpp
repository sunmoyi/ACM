#include <stdio.h>

int main (void){
	int a, b, n, i, j, k, t = 1;
	while(scanf("%d%d", &a,&b) == 2 && (a != 0||b != 0)){
		t = 1;
		for(i = 1; i <= b; i++){
			t = t * a;
			t = t % 1000;
		}
		printf("%d\n",t);
	}
	return 0;
}