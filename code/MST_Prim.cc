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