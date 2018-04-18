LL C(const LL &n, const LL &m, const int &pr) {
	LL ans = 1;
	for (int i = 1; i <= m; i++) {
		LL a = (n - m + i) % pr;
		LL b = i % pr;
		ans = (ans * (a * Inv(b, pr)) % pr) % pr;
	}
	return ans;
}