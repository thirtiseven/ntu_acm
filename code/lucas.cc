//C(n, m) mod p(n 很大 p 较小(不知道能不能为非素数）
LL Lucas(LL n, LL m, const int &pr) {
	if (m == 0) return 1;
	return C(n % pr, m % pr, pr) * Lucas(n / pr, m / pr, pr) % pr;
}