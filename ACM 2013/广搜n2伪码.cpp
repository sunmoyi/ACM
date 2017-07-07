/*void unweighted(table T)
{
	int currdist;
	vertex V, W;

	for (currdist = 0; currdist < numvertex; currdist++)
	{
		for each vertex V
		{
			if (!T[V].know && T[V].dist == currdist)
			{
				T[V].known = true;
				for each W adjacent to v;
				if (T[W].dist == infinity)
				{
					T[W].path = V;
					T[W].dist = currdist + 1;
				}
			}
		}
	}
}*/

void unweighted(Table T)
{
	queue Q;
	vertex V, W;

	Q = createQueue(numvertex);
	enqueue(S, Q);

	while (!isempty(Q))
	{
		V = Dequeue(Q);
		T[V].known = true;

		for each W adjacent to V
			if (T[W].dist == Infinity)
			{
				T[W].dist = T[V].dist + 1;
				T[W].path = V;
				enqueue(W, Q);
			}
	}
	Disposequeue(Q);
}