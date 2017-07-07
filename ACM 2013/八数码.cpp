/*�����Ǳ�׼�� BFS

�Ƚ��ͱ����� 
dis��ʾ��ǰ�Ĳ����˴�
fact����������루������뷽ʽ�е���죩
st��״̬����ǰ���� goal��Ŀ��
vis����ɸ��������֮ǰ�Ƿ����������ͽ�������ʹ�ã�
der�ֱ��ʾ0��4�ֿ����ƶ����
rear������ʾ�����б�����λ��
ʧ�ܵĽ��Ӧ������ĳ�εĿ�ȱ����� front = rear �� �����յ�ѭ����front = 8�� 
���������

1.���ȶ���Ź���
2.��st[k]����ʾ��k����ʱ�������״̬
3.����0��λ��

ע�⣺

while�е�forѭ�����γɵĸ��ڵ��µ�С�ڵ� �������� front��û�иı�
*/



#include <stdio.h>
#include<memory.h>
#define len 362888           
#define le 9                  
typedef int state[le];       
state st[len], goal;          
int dis[len], fact[le], head[len], vis[len], der[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };  //disΪÿ��״̬�����ߵĲ���   //derΪ����:�ϣ��£�����
void encode()                            //����
{
	int i;
	for (i = fact[0] = 1; i < le; i++)
		fact[i] = fact[i - 1] * i;    //fact[i] == i!    Ϊ���棨*������ Ϊ9���Ƶ�ת���ṩ����
}
int decode(int s)                   //����
{
	int i, j, code, cnt;
	for (i = code = 0; i < le; i++)
	{
		for (cnt = 0, j = i + 1; j<le; j++)     
			if (st[s][i]>st[s][j])     
				cnt++;
		code += cnt*fact[8 - i]; //��*��     ע �˴�������ת��Ϊ9���� ����һ������ķ�ʽ   ��ȻֻҪ���뷽ʽ�������ֲ�ͬ��s�Ϳ���   �Ƽ����Ź����е�������Ϊ��9λ9���� Ȼ����10���Ʊ�ʾ
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
		state & s = st[front]; //    s   ����  st[front]
		if (memcmp(s, goal, sizeof(s)) == 0)      
			return front;                        // dis[front]����С1    ��Ϊ�ڳ�ʼ��ʱ��frontΪ1�� dis[front] = 0;
		for (i = 0; i < le; i++)                 //�ҵ�Ϊ0��Ԫ�أ����յ��Ǹ����ӣ�����ѡȡ�յ��Ǹ�������ӦΪ�����1,2,3,...8���������ݣ�0��Ϊ�ж����ݼ�����������Ϊ�ж�����
			if (s[i] == 0)    
				break;
		x = i / 3;
		y = i % 3;
		z = i;           //��¼�յĸ��ӵ��б꣬�б�������λ�ã������λ�ð��մ����Ҵ��ϵ������ε���
		for (i = 0; i < 4; i++)                  //�����ϣ��£������ĸ������������
		{

			nx = x + der[i][0];    //  һ��������ȷ���ƶ�֮��0��λ��
			ny = y + der[i][1];
			nz = nx * 3 + ny;
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				state &t = st[rear];
				memcpy(t, s, sizeof(s));     //����3�� ��¼��ʱ��״̬���Ÿ����ӵ���ֵ
				t[z] = s[nz];                // ��2������������Ϊ0���ƶ������µ���������λ�õı仯
				t[nz] = s[z];
				dis[rear] = dis[front] + 1;     // ������ʾ���� 
				if (decode(rear))               //�ж�st[rear]����״̬�Ƿ��Ѿ����ֹ�
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
	for (i = 0; i < le; i++)   scanf_s("%d", &st[1][i]);      //�������Ҵ��ϵ��µ�˳��洢����
	for (i = 0; i < le; i++)   scanf_s("%d", &goal[i]);
	oj = bfs();
	if (oj)    printf("%d\n", dis[oj]);
	else    puts("Impossible");
	return 0;
}