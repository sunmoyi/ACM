#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
	double x;
	double y;
}line[110];
bool cmp(struct node a, struct node b){
	return atan2(a.y, a.x)<atan2(b.y, b.x);
}
int main(){
	int n, i;
	while (cin >> n)
	{
		if (n<0)
			break;
		if (n == 0)
			continue;
		for (i = 0; i<n; i++)
			cin >> line[i].x >> line[i].y;
		sort(line, line + n, cmp);
		printf("%.1lf %.1lf", line[0].x, line[0].y);
		for (i = 1; i<n; i++)
			printf(" %.1lf %.1lf", line[i].x, line[i].y);
		cout << endl;
	}
	return  0;
}