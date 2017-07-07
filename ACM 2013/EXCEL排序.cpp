#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct stu
{
	string no;
	string name;
	short grade;
};
bool sort1(const stu&, const stu&);
bool sort2(const stu&, const stu&);
bool sort3(const stu&, const stu&);
int main()
{
	int n, c, s = 1;
	while (cin >> n&&n != 0)
	{
		cin >> c;
		vector<stu> v;
		stu temp;
		while (n--)
		{
			cin >> temp.no >> temp.name >> temp.grade;
			v.push_back(temp);
		}
		if (c == 1)
			sort(v.begin(), v.end(), sort1);
		else if (c == 2)
			sort(v.begin(), v.end(), sort2);
		else
			sort(v.begin(), v.end(), sort3);
		cout << "Case " << s << ":\n";
		for (int i = 0; i != v.size(); ++i)
			cout << v[i].no << " " << v[i].name << " " << v[i].grade << endl;
		++s;
	}
	return 0;
}
bool sort1(const stu& s1, const stu& s2)
{
	return s1.no<s2.no ? true : false;
}
bool sort2(const stu& s1, const stu& s2)
{
	if (s1.name != s2.name)
		return s1.name<s2.name ? true : false;
	else
		return s1.no<s2.no ? true : false;
}
bool sort3(const stu& s1, const stu& s2)
{
	if (s1.grade != s2.grade)
		return s1.grade<s2.grade ? true : false;
	else
		return s1.no<s2.no ? true : false;
}