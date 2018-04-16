void add(int i, int x) {
	for(;i <= n; i += i & -i)
		tree[i] += x;
}

int sum(int i) {
	int ret = 0;
	for(; i; i -= i & -i) ret += tree[i];
	return ret;
}