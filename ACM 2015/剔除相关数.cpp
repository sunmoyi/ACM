#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<string>  
#include<cstdio>  
#include<cstring>  
#include<cctype>  
using namespace std;
map<string, int> cnt;
vector<string> w;

string repr(string &s)
{
	string ans = s;
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{
	int t, i;
	string s;
	while (scanf("%d", &t), t)
	{
		while (t--)
		{
			cin >> s;
			w.push_back(s); //将数据存入数组w  
			string r = repr(s); // 排下数字的顺序  
			if (!cnt.count(r))
				cnt[r] = 0;
			cnt[r]++;
		}
		vector<string> ans;
		int k = w.size();

		for (i = 0; i < k; i++)
			if (cnt[repr(w[i])] == 1)
				ans.push_back(w[i]);
		sort(ans.begin(), ans.end());
		k = ans.size();
		if (k == 0)//判断ans数组是否为空  
			printf("None\n");
		else
		{
			//按要求输出  
			cout << ans[0];
			for (i = 1; i < k; i++)
				cout << " " << ans[i];
			cout << endl;
		}
		ans.clear(); //数组和关联容器清空  
		w.clear();

	}
	return 0;
}