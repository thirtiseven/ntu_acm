/*
并查集模板：
pre数组记录根节点
*/

int pre[maxn];

void init(int n) {
	for (int i = 1; i <= n; i++)
		pre[i] = i;
}

int find(int x) {
	int r = x, i = x, j;
	while (pre[r] != r)
		r = pre[r];
	while (i != r) {
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void join(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy)
		pre[fx] = fy;
}