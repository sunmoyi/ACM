/*
HDU1074
*/
#include<stdio.h>
#include<string.h>
const int MAXN = 1 << 16;
struct Node
{
	int cost;//����ʱ��
	int pre;//ǰһ״̬
	int reduced;//������ʧ�ķ��� 
}dp[MAXN];
bool visited[MAXN];
struct Course
{
	int deadtime;//��ֹ����
	int cost;//��������
	char name[201];
}course[16];
void output(int status)
{
	int curjob = dp[status].pre^status;
	int curid = 0;
	curjob >>= 1;
	while (curjob)
	{
		curid++;
		curjob >>= 1;
	}
	if (dp[status].pre != 0)
	{
		output(dp[status].pre);
	}
	printf("%s\n", course[curid].name);
}
int main()
{
	int T, n, i, j;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int upper = 1 << n;
		int dayupper = 0;
		for (i = 0; i<n; i++)
		{
			scanf("%s%d%d", &course[i].name, &course[i].deadtime, &course[i].cost);
			dayupper += course[i].cost;
		}
		memset(visited, false, sizeof(visited));
		dp[0].cost = 0;
		dp[0].pre = -1;
		dp[0].reduced = 0;//dp[0]��ָ������ҵ��û������״̬  
		visited[0] = true;
		int work;
		int tupper = upper - 1;//tupper��ʾ�ɶ���������n��1�ģ���ʾ���е���ҵ������� 
		for (j = 0; j<tupper; j++)//��������״̬ 
		{
			for (work = 0; work<n; work++)
			{
				int cur = 1 << work;
				if ((cur&j) == 0)//������ҵ��δ����
				{
					int curtemp = cur | j;
					int day = dp[j].cost + course[work].cost;
					dp[curtemp].cost = day;
					int reduce = day - course[work].deadtime;
					if (reduce<0)reduce = 0;
					reduce += dp[j].reduced;
					if (visited[curtemp])//��״̬���з�����Ϣ
					{
						if (reduce<dp[curtemp].reduced)
						{
							dp[curtemp].reduced = reduce;
							dp[curtemp].pre = j;
						}
						//else if(reduce==dp[curtemp].reduced)
						//�۷���ͬ��ȡ�ֵ���С����һ������������j�ǰ���С���������ģ�Ĭ�����ǰ��ֵ��򣬲����ٴ���         
						// {                                      
						//  if(dp[curtemp].pre>j)        
						//   dp[curtemp].pre = j;        
						// }   
					}
					else //û�з��ʹ�
					{
						visited[curtemp] = true;
						dp[curtemp].reduced = reduce;
						dp[curtemp].pre = j;
					}
				}
			}
		}
		printf("%d\n", dp[tupper].reduced);
		output(tupper);//�ݹ���� 
	}
}