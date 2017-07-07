#include <iostream>   
using namespace std;   
struct Line{      
	int left, right, count;      
	Line *leftChild, *rightChild;      
	Line(int l, int r): left(l), right(r) {}   
};       
//建立一棵空线段树   
void createTree(Line *root) 
{     
	int left = root->left;     
	int right = root->right;     
	if (left < right) 
	{        
		int mid = (left + right) / 2;        
		Line *lc =  new Line(left, mid);        
		Line *rc =  new Line(mid + 1, right);       
		root->leftChild = lc;       
		root->rightChild = rc;       
		createTree(lc);       
		createTree(rc);     
	}    
}       
//将线段[l, r]分割    
void insertLine(Line *root, int l, int r) 
{     
	cout << l << " " << r << endl;      
	cout << root->left << " " << root->right << endl << endl;     
	if (l == root->left && r == root->right) 
	{      
		root->count += 1;     
	} 
	else if (l <= r) 
	{        
		int rmid = (root->left + root->right) / 2;  
		if (r <= rmid) 
		{          
			insertLine(root->leftChild, l, r);       
		}
		else if (l >= rmid + 1) 
		{          
			insertLine(root->rightChild, l, r);       
		} 
		else 
		{          
			int mid = (l + r) / 2;          
			insertLine(root->leftChild, l, mid);         
			insertLine(root->rightChild, mid + 1, r);       
		}     
	}    
}    
//树的中序遍历（测试用）   
void inOrder(Line* root) 
{     
	if (root != NULL) 
	{        
		inOrder(root->leftChild);       
		printf("[%d, %d], %d\n", root->left, root->right, root->count);       
		inOrder(root->rightChild);     
	}   
}        
//获取值n在线段上出现的次数   
int getCount(Line* root, int n) 
{     
	int c = 0;      
	if (root->left <= n&&n <= root->right)      
		c += root->count;     
	if (root->left == root->right)       
		return c;      
	int mid = (root->left + root->right) / 2;     
	if (n <= mid)        
		c += getCount(root->leftChild, n);     
	else       
		c += getCount(root->rightChild, n);     
	return c;   
}  

int main() 
{      
	int l[3] = {2, 4, 0};     
	int r[3] = {5, 6, 7};     
	int MIN = l[0];     
	int MAX = r[0];     
	for (int i = 1; i < 3; ++i) 
	{       
		if (MIN > l[i]) MIN = l[i];       
		if (MAX < r[i]) MAX = r[i];     
	}      
	Line *root = new Line(MIN, MAX); 
	createTree(root);      
	for (int i = 0; i < 3; ++i) 
	{ 
		insertLine(root, l[i], r[i]); 
	}      
	inOrder(root);     
	int N;      
	while (cin >> N) 
	{ 
		cout << getCount(root, N) << endl; 
	}     
	return 0;
}