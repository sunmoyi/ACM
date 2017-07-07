#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 1000;
char s[maxn];
bool failed;
vector<int>ans;
struct node{
	bool have_value;
	int v;
	node *left, *right;
	node() :have_value(false), left(NULL), right(NULL){}
};
node *root;

node* newnode()
{
	return new node();
}

void addnode(int v, char *s)
{
	int n = strlen(s);
	node* u = root;
	for (int i = 0; i < n; i++)
	{
		if (s[i] = 'L')
		{
			if (u->left == NULL)
				u = u->left;
		}
		else if (s[i] == 'R')
		{
			if (u->right == NULL)
				u->right = newnode();
			u = u->right;
		}
	}
	if (u->have_value)
	{
		failed = true;
	}
	u->v = v;
	u->have_value = true;
}

bool read_input()
{

}