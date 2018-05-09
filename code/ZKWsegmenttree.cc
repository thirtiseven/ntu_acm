const int maxn = 100;
int M, T[maxn*2+2], n;

void build(int x) {
	for(M=1; M<=n+1; M<<=1);
	
	for(int i=1; i<=n; i++)
		scanf("%d",&T[i+M]);
	
	for(int i=M-1;i;i--)
		T[i]=T[i<<1]+T[i<<1|1];
}
void updata(int n,int val) {
	T[n+=M]=val;//这个地方是单点修改的哟
	for(n>>=1;n;n>>=1)
		T[n]=T[n<<1]+T[n<<1|1];
}
int query(int l,int r) {
	int ans=0;
	l=l+M-1, r=r+M+1;
	for (;l^r^1;l>>=1,r>>=1) {
		if (~l&1)ans+=T[l^1];
		if (r&1) ans+=T[r^1];
	}
	return ans;
}