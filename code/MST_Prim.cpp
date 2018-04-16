/*
MST算法(Prim)：
d[i][j]表示点i到点j的边的权值，lowc记录当前最短路，vis记录节点是否已被访问
注：Prim算法更适用稠密图，用邻接矩阵表示
*/

int d[maxn][maxn];
int lowc[maxn];
int vis[maxn];

int prim(int n) {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i <= n; i++)
		lowc[i] = d[1][i];
	vis[1] = 1;
	for (int i = 1; i < n; i++) {
		int minc = INF;
		int p = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && minc > lowc[j]) {
				minc = lowc[j];
				p = j;
			}
		}
		vis[p] = 1;
		ans += minc;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && lowc[j] > d[p][j])
				lowc[j] = d[p][j];
		}
	}
	return ans;
}