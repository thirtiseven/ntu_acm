/*
MST算法(Kruskal)：
e数组记录每条边，下标1~n，pre记录并查集根节点，lef记录剩余未连接数量，ans为最短路径
注：Kruskal算法更适用稀疏图
*/

struct edge {
	int s, t, w;	//从s到t，权值w
	edge() {}
	edge(int s, int t, int w) :s(s), t(t), w(w) {}
}e[maxn];

int pre[maxn];

int find(int x) {
	int r = x, i = x, j;
	while (pre[r] != r)
		r = pre[r];
	while (i != r) {	//状态压缩
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

int cmp(edge e1, edge e2) {
	return e1.w < e2.w;
}

int kruskal(int n, int m) {	//n为边数，m为点数
	int lef = m - 1, ans = 0;
	for (int i = 1; i <= m; i++)pre[i] = i;
	sort(e + 1, e + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int fs = find(e[i].s), ft = find(e[i].t);
		if (fs != ft) {
			pre[fs] = ft;
			ans += e[i].w;
			lef--;
		}
		if (!lef)break;
	}
	if (lef)ans = 0;	//图不连通
	return ans;
}