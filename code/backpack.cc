const int maxn=100005;
int w[maxn],v[maxn],num[maxn];
int W,n;
int dp[maxn];

void ZOP(int weight, int value) {
	for(int i = W; i >= weight; i--) {
		dp[i]=std::max(dp[i],dp[i-weight]+value);
	}
}

void CP(int weight, int value){
	for(int i = weight; i <= W; i++) {
		dp[i] = std::max(dp[i], dp[i-weight]+value);
	}
}

void MP(int weight, int value, int cnt){
	if(weight*cnt >= W) {
		 CP(weight, value);
	} else {
		for(int k = 1; k < cnt; k <<= 1) {
			ZOP(k*weight, k*value), cnt -= k;
		}
		ZOP(cnt*weight, cnt*value);
	}
}