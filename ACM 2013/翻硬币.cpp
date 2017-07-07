#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		char s1[1000];
		char s2[1000];
		int cr[1000];    //记录两个字符串的比较结果。0为相同，1为不同。
		cin >> s1;
		cin >> s2;
		int l;
		for (l = 0; s1[l] != '\0'; l++);    //计算长度
		for (int i = 0; i < l; i++){    //比较两个字符串，并记录结果
			if (s1[i] == s2[i])
				cr[i] = 0;
			else
				cr[i] = 1;
		}
		int f = -1;    //记录标记位
		int _count = 0;
		for (int i = 0; i < l; i++){
			if (cr[i] == 1){    //检测到一个 1
				if (f == -1){    //如果前面没有记录的1的下标，记录当前1的下标
					f = i;
				}
				else{    //如果前面有一个1了
					_count += i - f;
					f = -1;
				}
			}
		}
		cout << _count << endl;
	}
	return 0;
}
