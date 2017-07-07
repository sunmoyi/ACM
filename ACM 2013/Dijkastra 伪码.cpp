void Dijkstra(table T)
{
	vertex v, w;

	for (;;)
	{
		v = smallest unknown distance vertex;
		if (v == notavrtex)
			break;

		T[v].known = true;
		for each w adjacent v
			if (!T[w].known)
				if (T[v].dist + cvw < T[w].dist)
				{
					T[w].dist = T[v].dist + cvw;
					T[w].path = v;
				}
	}
}