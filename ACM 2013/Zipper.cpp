# include<stdio.h>
# include<string.h>

char str1[205], str2[205], str[405], flag, visit[205][205];

void dfs(int i, int j, int k)
{
	if (str[i] == 0 && str1[j] == 0 && str2[k] == 0) 
	{ 
		flag = 1; 
		return;
	}
	if (str[i] != str1[j] && str[i] != str2[k]) 
		return;
	if (visit[j][k]) 
		return;///如果该状态已经访问过了，那就无需再访问了
	visit[j][k] = 1;
	if (str[i] == str1[j])    
		dfs(i + 1, j + 1, k);
	if (flag) 
		return;
	if (str[i] == str2[k])    
		dfs(i + 1, j, k + 1);
}
int main()
{
	int t, ncase;
	scanf("%d", &ncase);
	for (t = 1; t <= ncase; t++)
	{
		scanf("%s%s%s", str1, str2, str);
		memset(visit, 0, sizeof(visit));
		flag = 0;
		dfs(0, 0, 0);
		printf("Data set %d: ", t);
		if (flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}