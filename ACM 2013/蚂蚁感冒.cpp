#include <cstdio>
#include <algorithm>

using namespace std;
struct Node
{
	int x;
	int dis;
	int num;
};
Node a[100];
int comp(Node a1, Node a2)
{
	if (a1.x != a2.x)
		return a1.x<a2.x;
}
int main(){
	int T;
	scanf_s("%d", &T);
	int n, x;
	while (T--){
		scanf_s("%d", &n);
		for (int i = 0; i<n; i++){
			scanf_s("%d", &x);
			a[i].dis = x<0 ? -1 : 1;
			a[i].x = abs(x);
			a[i].num = i + 1;//  用来表示初始蚂蚁的位置
		}
		sort(a, a + n, comp);  //排序
		int tmp = 0, left = 0, right = 0, ans = 0;
		for (int i = 0; i<n; i++){  //左边向右走的
			if (a[i].num == 1){
				tmp = i; break;// 找到第一只感冒的蚂蚁
			}
			if (a[i].dis == 1)
				left++;
		}
		for (int i = tmp + 1; i<n; i++){ //右边向左走的
			if (a[i].dis == -1)
				right++;
		}
		if (a[tmp].dis == 1 && right == 0 || a[tmp].dis == -1 && left == 0)
			ans = 1;
		else
			ans = left + right + 1;
		printf("%d\n", ans);
	}
	return 0;
}
