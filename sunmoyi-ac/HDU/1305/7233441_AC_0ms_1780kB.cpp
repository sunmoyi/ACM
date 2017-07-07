#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#define maxn 100000

using namespace std;

string str;
struct node {
	node *son[2];
	bool over = false;
	node()
	{
		son[0] = NULL;
		son[1] = NULL;
		over = false;
	}
}root;
bool flag = true;

void build(string a)
{
	node * rot = &root;
	for (int i = 0; i < a.length(); i++)
	{
		int m = a[i] - '0';
		if (rot->son[m] == NULL)
		{
			rot->son[m] = new (node);
			rot = rot->son[m];
		}
		else
		{
			rot = rot->son[m];
			if (i == a.length() - 1 || rot->over == true)
			{
				flag = false;
				break;
			}
		}
	}
	rot->over = true;
}

void Delete(node* root)
{
	if (root != NULL)
	{
		for (int i = 0; i <= 1; i++)
			if (root->son[i] != NULL)
				Delete(root->son[i]);
		delete(root);
	}
}

int main(void)
{
	int Case = 0;
	while (cin >> str)
	{
		if (str == "9")
			break;
		flag = true;
		build(str);
		while (cin >> str && str != "9")
		{
			if (flag)
				build(str);
		}
		if (flag)
			cout << "Set " << ++Case << " is immediately decodable" << endl;
		else
			cout << "Set " << ++Case << " is not immediately decodable" << endl;
		Delete(root.son[0]);
		Delete(root.son[1]);
		root.son[0] = root.son[1] = NULL;
	}
	return 0;
}