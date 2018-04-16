int fa[N];

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}