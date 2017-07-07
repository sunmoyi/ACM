#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define maxn 8
#define maxm 105
#define INF 0x3f3f3f3f
#define maxstate 15000

using namespace std;

int m, n, s[maxn], k[maxn], kk;
double c, price[maxm][maxm];
char name[maxn][10];
double d[maxm][maxstate];
int opt[maxm][maxstate], pre[maxm][maxstate];//������print_ans
int buy_next[maxstate][maxn], sell_next[maxstate][maxn];
vector<vector<int>>state;
//state[i]����һ�����Ϊi��nԪ��  ����Ϣ��vector���� //һ��nԪ������ֳָ���Ʊ����Ŀ
map<vector<int>, int>ID; //ID ��vector����ŵ�ӳ�� 

void dfs(int stock, vector<int>& lots, int totlot) //dfs����states 
{
	if (stock == n) //�µ�nԪ�鹹����� 
	{
		ID[lots] = state.size(); //ID 
		state.push_back(lots);//push 
	}
	else
	{
		for (int i = 0; i <= k[stock] && totlot + i <= kk; i++)
		{//������k[]��K�����������������dfs��һstock 
			lots[stock] = i;
			dfs(stock + 1, lots, totlot + i);  //���� д�� 
		}
	}
}

void init()//����states���߽���״̬֮��Ĺ�ϵ
{
	vector<int>lots(n);
	state.clear();
	ID.clear();
	dfs(0, lots, 0);
	for (int s = 0; s < state.size(); s++)//����һ��״̬ 
	{
		int totlot = 0;
		for (int i = 0; i < n; i++)
			totlot += state[s][i];//Ŀǰ״̬�����й���
		for (int i = 0; i < n; i++) //ö����״̬�иı�Ĺ�Ʊi 
		{
			buy_next[s][i] = sell_next[s][i] = -1;//��ֵ-1 
			if (state[s][i] < k[i] && totlot < kk)//���buy���� 
			{
				vector<int>newstate = state[s];
				newstate[i]++;
				buy_next[s][i] = ID[newstate];
			}
			if (state[s][i] > 0)//���sell���� 
			{
				vector<int>newstate = state[s];
				newstate[i]--;
				sell_next[s][i] = ID[newstate];
			}
		}
	}
}

void update(int day, int s, int s2, double v, int o)//ˢ�� ���� 
{//�ڵ�day�� �ڽ��в����� ״��sת�Ƶ�״��s2 ת�ƺ�����Ǯ��Ϊv
 //��|o|���в���      //opt�������������ֲ��� buy || sell
	if (v > d[day + 1][s2]) 
	{
		d[day + 1][s2] = v;
		opt[day + 1][s2] = o;//: �ó� [][] �����Ų��� 
		pre[day + 1][s2] = s;//: �ó� [][] ������ǰ״�� 
	}
}

double dp()
{
	for (int day = 0; day <= m; day++)
		for (int s = 0; s < state.size(); s++)
			d[day][s] = -INF;//�߽��趨 
	d[0][0] = c; //��0���ֳ�0�ֹ�Ʊ ������c��Ǯ�� 
	for (int day = 0; day < m; day++) //ö������ 
	{
		for (int s = 0; s < state.size(); s++)//ö�����й�Ʊ��״̬ 
		{
			double v = d[day][s];
			if (v < -1)
				continue;//return 
			update(day, s, s, v, 0);// HOLD
			for (int i = 0; i < n; i++)
			{
				if (buy_next[s][i] >= 0 && v >= price[i][day] - 1e-3) //s״̬��Ҫ���Ʊi 
					update(day, s, buy_next[s][i], v - price[i][day], i + 1); // BUY
				if (sell_next[s][i] >= 0)//s״̬��Ҫ����Ʊi 
					update(day, s, sell_next[s][i], v + price[i][day], -i - 1);// SELL
			}
		}
	}
	return d[m][0]; //���˵�m�� ����û�й�Ʊ //����DPԭ��������ֵ 
}

void print_ans(int day, int s)//����prev��opt�ݹ������ 
{
	if (day == 0)
		return;
	print_ans(day - 1, pre[day][s]);
	if (opt[day][s] == 0)
		printf("HOLD\n");//==0 
	else if (opt[day][s] > 0)
		printf("BUY %s\n", name[opt[day][s] - 1]);// >0 
	else
		printf("SELL %s\n", name[-opt[day][s] - 1]); //<0
}

int main(void)
{
	int icase = 0;
	while(scanf("%lf %d %d %d", &c, &m, &n, &kk) != EOF)
	{
		if (icase++ > 0)
			printf("\n");
		for (int i = 0; i < n; i++)
		{
			scanf("%s %d %d", name[i], &s[i], &k[i]);
			for (int j = 0; j < m; j++)
			{
				scanf("%lf", &price[i][j]);
				price[i][j] *= s[i];
			}
		}
		init();
		double ans = dp();
		printf("%.2lf\n", ans);
		print_ans(m, 0);
	}
	return 0;
}