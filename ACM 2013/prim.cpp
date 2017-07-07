/*
*prim�����Ż���
*
*QΪ���ȶ��� �Աߵĳ��ȴ�С��������
*
*node�ṹ��     v������Ķ��� len�����·�ĳ���
*
*����������G���ڽӱ�ķ�ʽ����ͼ
*mindist�����ʼ��ΪINF
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