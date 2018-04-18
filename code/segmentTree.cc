//A为原始数组，sum记录区间和，Add为懒惰标记

int A[maxn], sum[maxn << 2], Add[maxn << 2];

void pushup(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int l, int r) {
	if (Add[rt]) {
		int mid = (l + r) >> 1;
		Add[rt << 1] += Add[rt];
		Add[rt << 1 | 1] += Add[rt];
		sum[rt << 1] += (mid - l + 1)*Add[rt];
		sum[rt << 1 | 1] += (r - mid)*Add[rt];
		Add[rt] = 0;
	}
}

void build(int l, int r, int rt) {
	if (l == r) {
		sum[rt] = A[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//区间加值
void update(int L, int R, int val, int l, int r, int rt) {
	if (L <= l && R >= r) {
		Add[rt] += val;
		sum[rt] += (r - l + 1)*val;
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid)update(L, R, val, l, mid, rt << 1);
	if (R > mid)update(L, R, val, mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//点修改
void update(int index, int val, int l, int r, int rt) {
	if (l == r) {
		sum[rt] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (index <= mid)update(index, val, l, mid, rt << 1);
	else update(index, val, mid + 1, r, rt << 1 | 1);
	pushup(rt);
}

//区间查询
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && R >= r) {
		return sum[rt];
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid)ret += query(L, R, l, mid, rt << 1);
	if (R > mid)ret += query(L, R, mid + 1, r, rt << 1 | 1);
	return ret;
}