bool dfs(int u)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!used[v])
		{
			used[v] = true;
			if (linker[v] == -1 || dfs(linker[v]))
			{
				linker[v] == u;
				return true;
			}
		}
	}
	return false;
}

int hungary(void)
{
	int res;
	memset(linker, -1, sizeof(linker));
	for (int u = 0; u < V; u++)
	{
		memset(used, 0, sizeof(used));
		if (dfs(u))
			res++;
	}
	return res;
}
