#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		char s1[1000];
		char s2[1000];
		int cr[1000];    //��¼�����ַ����ıȽϽ����0Ϊ��ͬ��1Ϊ��ͬ��
		cin >> s1;
		cin >> s2;
		int l;
		for (l = 0; s1[l] != '\0'; l++);    //���㳤��
		for (int i = 0; i < l; i++){    //�Ƚ������ַ���������¼���
			if (s1[i] == s2[i])
				cr[i] = 0;
			else
				cr[i] = 1;
		}
		int f = -1;    //��¼���λ
		int _count = 0;
		for (int i = 0; i < l; i++){
			if (cr[i] == 1){    //��⵽һ�� 1
				if (f == -1){    //���ǰ��û�м�¼��1���±꣬��¼��ǰ1���±�
					f = i;
				}
				else{    //���ǰ����һ��1��
					_count += i - f;
					f = -1;
				}
			}
		}
		cout << _count << endl;
	}
	return 0;
}
