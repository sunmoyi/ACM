/*这里是标准的 BFS

先解释变量： 
dis表示当前的步数此次
fact用来编码解码（这个解码方式有点诡异）
st是状态【当前】， goal是目标
vis进来筛查此种情况之前是否遇到过（和解码联合使用）
der分别表示0的4种可能移动情况
rear用来表示在树中本结点的位置
失败的结果应该是在某次的宽度遍历中 front = rear 即 在最终的循环中front = 8！ 
代码分析：

1.首先读入九宫格
2.用st[k]来表示在k步的时候数组的状态
3.查找0的位置

注意：

while中的for循环所形成的父节点下的小节点 而在这中 front并没有改变
*/



#include <stdio.h>
#include<memory.h>
#define len 362888           
#define le 9                  
typedef int state[le];       
state st[len], goal;          
int dis[len], fact[le], head[len], vis[len], der[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };  //dis为每种状态的已走的步骤   //der为方向:上，下，左，右
void encode()                            //编码
{
	int i;
	for (i = fact[0] = 1; i < le; i++)
		fact[i] = fact[i - 1] * i;    //fact[i] == i!    为下面（*）服务 为9进制的转化提供数字
}
int decode(int s)                   //解码
{
	int i, j, code, cnt;
	for (i = code = 0; i < le; i++)
	{
		for (cnt = 0, j = i + 1; j<le; j++)     
			if (st[s][i]>st[s][j])     
				cnt++;
		code += cnt*fact[8 - i]; //（*）     注 此处并不是转化为9进制 而是一种神奇的方式   当然只要编码方式可以区分不同的s就可以   推荐将九宫格中的数字认为成9位9进制 然后以10进制表示
	}
	if (vis[code])  
		return 0;
	else            
		return vis[code] = 1;
}
int bfs()
{
	int front = 1, rear = 2, i, x, y, z, nx, ny, nz;
	encode();
	while (front < rear)
	{
		state & s = st[front]; //    s   代表  st[front]
		if (memcmp(s, goal, sizeof(s)) == 0)      
			return front;                        // dis[front]比他小1    因为在初始的时候front为1； dis[front] = 0;
		for (i = 0; i < le; i++)                 //找到为0的元素，即空的那个格子，这里选取空的那个格子是应为相对于1,2,3,...8这样的数据，0作为判断依据简单于用数据作为判断依据
			if (s[i] == 0)    
				break;
		x = i / 3;
		y = i % 3;
		z = i;           //记录空的格子的行标，列表，和所在位置，这里的位置按照从左到右从上到下依次递增
		for (i = 0; i < 4; i++)                  //按照上，下，左，右四个方向进行搜索
		{

			nx = x + der[i][0];    //  一下三步来确定移动之后0的位置
			ny = y + der[i][1];
			nz = nx * 3 + ny;
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				state &t = st[rear];
				memcpy(t, s, sizeof(s));     //以下3步 记录此时的状态即九个格子的数值
				t[z] = s[nz];                // 这2步用来调整因为0的移动而导致的其他数字位置的变化
				t[nz] = s[z];
				dis[rear] = dis[front] + 1;     // 用来表示步数 
				if (decode(rear))               //判断st[rear]这种状态是否已经出现过
					rear++;
			}
		}
		front++;
	}
	return 0;
}
int main(void)
{
	int i, oj;
	for (i = 0; i < le; i++)   scanf_s("%d", &st[1][i]);      //按从左到右从上到下的顺序存储数据
	for (i = 0; i < le; i++)   scanf_s("%d", &goal[i]);
	oj = bfs();
	if (oj)    printf("%d\n", dis[oj]);
	else    puts("Impossible");
	return 0;
}