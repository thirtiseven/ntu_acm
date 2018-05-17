const int maxn=2000005;
int f[maxn];
std::string a, s;
int manacher() {
	int n=0, res=0, maxr=0, pos=0;
	for (int i=0; a[i]; i++) {
		s[++n] = '#', s[++n] = a[i];
		s[++n] = '#';
	}
	for (int i=1; i<=n; i++) {
		f[i] = (i<maxr? std::min(f[pos*2-i], maxr-i+1): 1);
		while (i-f[i]>0 && i+f[i]<=n && s[i-f[i]]==s[i+f[i]]) {
			f[i]++;
		}
		if (i+f[i]-1 > maxr) {
			maxr=i+f[i]-1;
			pos=i;
		}
		res = std::max(res,f[i]-1);
	}
	return res;
}
