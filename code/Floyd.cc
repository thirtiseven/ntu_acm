//#define inf maxn*maxw+10
for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
		d[i][j] = inf;
	}
}
d[0][0] = 0;
for(int k = 0; k < n; k++) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);		
		}
	}
}