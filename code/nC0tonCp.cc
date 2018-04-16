//by Yuhao Du
int p;
std::vector<int> gao(int n) {
	std::vector<int> ret(p+1,0);
	if (n==0) {
		ret[0]=1;
	} else if (n%2==0) {
		std::vector<int> c = gao(n/2);
		for(int i = 0; i <= p+1; i++) {
			for(int j = 0; j <= p+1; j++) { 
				if (i+j<=p) ret[i+j]+=c[i]*c[j];
			}
		}
	} else {
		std::vector<int> c = gao(n-1);
		for(int i = 0; i <= p+1; i++) {
			for(int j = 0; j <= 2; j++) {
				if (i+j<=p) ret[i+j]+=c[i];
			}
		}
	}
	return ret;
}