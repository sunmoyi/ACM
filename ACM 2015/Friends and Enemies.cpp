#include<iostream>
#include<cstring>
using namespace std;
int root[100000005];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, count = 0, x;
		long long k;
		int a[100005];
		memset(root, 0, sizeof(root));
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int father, child;
		for (int i = 1; i <= n - 1; i++) {
			cin >> father >> child;
			root[child] = father;
		}

		for (int i = 1; i <= n; i++) {
			int query = a[i];
			while (root[query] != 0) {//Ϊ0����û�и��ڵ��� 
				int query_root = root[query];//�õ����ĸ��ڵ� 
				if (query_root*query <= k) {
					count++;
				}
				query = query_root;
			}
		}
		cout << count << endl;
	}
	return 0;
}