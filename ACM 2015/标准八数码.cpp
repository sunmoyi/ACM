#include <iostream>
#include <bitset>
#include <cstring>
#include <set>

using namespace std;

const int DIGIT_NUM = 9;
int const NODES = 362880 + 20;
int nGoalStatus; //目标状态

struct Node {
	int status; int f; int g; int h;
	int parent; // parent代表一个状态，而不是状态的索引
	char move; //经由何种动作到达本状态
};

bool operator < (const Node & n1, const Node & n2)
{
	return n1.f < n2.f;
}

multiset<Node > open;
multiset<Node > closed;//也许用vector也可以。用multiset只是在从 closed表里删除元素时快些。其实closed表就是一个 362880元素的数组，可能更快
bitset<NODES> inOpen;
bitset<NODES> inClosed;
multiset<Node>::iterator openIdx[NODES]; // openIdx[i] 就是状态 i 在open表里的地址
multiset<Node>::iterator closedIdx[NODES];
char szResult[NODES]; //结果
char szMoves[NODES]; //移动步骤 ： u/d/r/l
char sz4Moves[] = "udrl";//四种动作

template< class T>
unsigned int GetPermutationNum(T * first, T * permutation, int len)
{ //permutation编号从0开始算, [first,first+len) 里面放着第0号 permutation，排列的每个元素都不一样 //返回排列的编号 
	unsigned int factorial[21] = { 1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,1932053504,1278945280, 2004310016,2004189184,4006445056,3396534272,109641728,2192834560 };
	bool used[21] = { 0 };
	int perInt[21]; //要转换成 [0,len-1] 的整数的排列 
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
		{
			if (*(permutation + i) == *(first + j))
			{
				perInt[i] = j;
				break;
			}
		}
	unsigned int num = 0;
	for (int i = 0; i < len; ++i)
	{
		unsigned int n = 0;
		for (int j = 0; j < perInt[i]; ++j)
		{
			if (!used[j])
				++n;
		}
		num += n * factorial[len - i - 1];
		used[perInt[i]] = true;
	}
	return num;
}

template <class T>
void GenPermutationByNum(T * first, T * permutation, int len, unsigned int No)
//根据排列编号，生成排列
{ //[first,first+len) 里面放着第0号 permutation,，排列的每个元素都不一样
	unsigned int factorial[21] = { 1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,1932053504,1278945280, 2004310016,2004189184,4006445056,3396534272,109641728,2192834560 };
	bool used[21] = { 0 };
	int perInt[21]; //要转换成 [0,len-1] 的整数的排列
	for (int i = 0; i < len; ++i)
	{
		unsigned int tmp;
		int n = 0;
		int j;
		for (j = 0; j < len; ++j)
		{
			if (!used[j])
			{
				if (factorial[len - i - 1] >= No + 1)
					break;
				else
					No -= factorial[len - i - 1];
			}
		}
		perInt[i] = j;
		used[j] = true;
	}
	for (int i = 0; i < len; ++i)
		* (permutation + i) = *(first + perInt[i]);
}

int StrStatusToIntStatus(const char * strStatus)
{
	return GetPermutationNum("012345678", strStatus, 9);
}

void IntStatusToStrStatus(int n, char * strStatus)
{
	GenPermutationByNum((char*)"012345678", strStatus, 9, n);
}

int MyAbs(int a)
{
	return a >= 0 ? a : -a;
}

int h(char * status)
{//h的值是不在位的数字到它该呆的位置的曼哈顿距离之和 
	int sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		if (status[i] != '0')
		{
			int rightx = (status[i] - '1') / 3;
			int righty = (status[i] - '1') % 3;
			int nowx = i / 3;
			int nowy = i % 3;
			sum += MyAbs(rightx - nowx) + MyAbs(righty - nowy);
		}
	}
	return sum;
}
int NewStatus(int nStatus, char cMove)
{ //求从nStatus经过 cMove 移动后得到的新状态。若移动不可行则返回-1 
	char szTmp[20];
	int nZeroPos;
	IntStatusToStrStatus(nStatus, szTmp);
	for (int i = 0; i < 9; ++i)
		if (szTmp[i] == '0')
		{
			nZeroPos = i;
			break;
		} //返回空格的位置

	switch (cMove)
	{
	case 'u':
		if (nZeroPos - 3 < 0)
			return -1; //空格在第一行
		else
		{
			szTmp[nZeroPos] = szTmp[nZeroPos - 3];
			szTmp[nZeroPos - 3] = '0';
		}
		break;
	case 'd':
		if (nZeroPos + 3 > 8)
			return -1; //空格在第三行
		else
		{
			szTmp[nZeroPos] = szTmp[nZeroPos + 3];
			szTmp[nZeroPos + 3] = '0';
		}
		break;
	case 'l':
		if (nZeroPos % 3 == 0)
			return -1; //空格在第一列
		else
		{
			szTmp[nZeroPos] = szTmp[nZeroPos - 1];
			szTmp[nZeroPos - 1] = '0';
		}
		break;
	case 'r':
		if (nZeroPos % 3 == 2)
			return -1; //空格在第三列
		else
		{
			szTmp[nZeroPos] = szTmp[nZeroPos + 1];
			szTmp[nZeroPos + 1] = '0';
		}
		break;
	}
	return StrStatusToIntStatus(szTmp);
}

Node AStar(int nStatus)
{
	open.clear();
	closed.clear();
	inOpen.reset();
	inClosed.reset();
	char strStatus[20];
	IntStatusToStrStatus(nStatus, strStatus);
	Node nd;
	nd.status = nStatus;
	nd.parent = -1;
	nd.g = 0;
	nd.move = -1;
	nd.h = h(strStatus);
	nd.f = nd.g + nd.h;
	open.insert(nd);
	inOpen.set(nStatus, true);
	openIdx[nStatus] = open.begin();
	while (!open.empty())
	{ //队列不为空
		nd = *open.begin();
		open.erase(open.begin());
		inOpen.set(nd.status, false);
		multiset<Node>::iterator p = closed.insert(nd);
		inClosed.set(nd.status, true);
		closedIdx[nd.status] = p;
		if (nd.status == nGoalStatus)
			return nd;
		for (int i = 0; i < 4; i++)
		{ //尝试4种移动
			Node newNd;
			newNd.status = NewStatus(nd.status, sz4Moves[i]);
			if (newNd.status == -1)
				continue; //不可移，试下一种
			IntStatusToStrStatus(newNd.status, strStatus);
			newNd.g = nd.g + 1;
			newNd.h = h(strStatus);
			newNd.f = newNd.g + newNd.h;
			newNd.parent = nd.status;
			newNd.move = sz4Moves[i];
			if (inOpen[newNd.status])
			{
				Node tmp = *openIdx[newNd.status];
				if (tmp.f > newNd.f)
				{
					open.erase(openIdx[newNd.status]);
					p = open.insert(newNd);
					openIdx[newNd.status] = p;
				}
			}
			else if (inClosed[newNd.status])
			{
				Node tmp = *closedIdx[newNd.status];
				if (tmp.f > newNd.f)
				{
					closed.erase(closedIdx[newNd.status]);
					inClosed.set(newNd.status, false);
					p = open.insert(newNd);
					openIdx[newNd.status] = p;
					inOpen.set(newNd.status, true);
				}
			}
			else
			{
				p = open.insert(newNd);
				openIdx[newNd.status] = p;
				inOpen.set(newNd.status, true);
			}
		}
	}
	nd.status = -1;
	return nd;
}

int main()
{
	nGoalStatus = StrStatusToIntStatus("123456780");
	char szLine[50];
	char szLine2[20];
	while (cin.getline(szLine, 48))
	{
		int i, j;
		for (i = 0, j = 0; szLine[i]; i++)
		{
			if (szLine[i] != ' ')
			{
				if (szLine[i] == 'x')
					szLine2[j++] = '0';
				else
					szLine2[j++] = szLine[i];
			}
		}
		szLine2[j] = 0;
		int sumGoal = 0;
		for (int i = 0; i < 8; ++i)
			sumGoal += i - 1;
		int sumOri = 0;
		for (int i = 0; i < 9; ++i)
		{
			if (szLine2[i] == '0')
				continue;
			for (int j = 0; j < i; ++j)
			{
				if (szLine2[j] < szLine2[i] && szLine2[j] != '0')
					sumOri++;
			}
		}
		if (sumOri % 2 != sumGoal % 2)
		{
			cout << "unsolvable" << endl;
			continue;
		}
		Node nd = AStar(StrStatusToIntStatus(szLine2));
		if (nd.status != -1)
		{
			int nMoves = 0;
			multiset<Node>::iterator pos;
			pos = closedIdx[nd.status];
			do {
				if (pos->move != -1)
				{
					szResult[nMoves++] = pos->move;
					pos = closedIdx[pos->parent];
				}
			} while (pos->move != -1); for (int i = nMoves - 1; i >= 0; i--)
				cout << szResult[i];
			cout << endl;
		}
		else
			cout << "unsolvable" << endl;
	}
	return 0;
}