/*
*prim队列优化版
*
*Q为优先队列 以边的长度从小到大排序
*
*node结构体     v代表到达的顶点 len代表道路的长度
*
*不定长数组G以邻接表的方式保存图
*mindist数组初始化为INF
*/
int Prim()
{
	int sum = 0;
	priority_queue<node>Q;
	for (int i = 0; i < G[0].size(); i++)
	{

		minDist[G[0][i].v] = G[0][i].len;
		Q.push(G[0][i]);
	}
	intree[0] = true;

	while (!Q.empty())
	{
		node now = Q.top();
		Q.pop();
		if (intree[now.v])
			continue;
		intree[now.v] = true;
		sum += now.len;
		for (int i = 0; i < G[now.v].size(); i++)
		{
			int vex = G[now.v][i].v;
			int len = G[now.v][i].len;
			if (len < minDist[vex])
			{
				minDist[vex] = len;
				Q.push(G[now.v][i]);
			}
		}
	}
	return sum;
}