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
			w.push_back(s); //�����ݴ�������w  
			string r = repr(s); // �������ֵ�˳��  
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
		if (k == 0)//�ж�ans�����Ƿ�Ϊ��  
			printf("None\n");
		else
		{
			//��Ҫ�����  
			cout << ans[0];
			for (i = 1; i < k; i++)
				cout << " " << ans[i];
			cout << endl;
		}
		ans.clear(); //����͹����������  
		w.clear();

	}
	return 0;
}