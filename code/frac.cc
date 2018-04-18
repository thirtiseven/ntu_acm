inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct frac{
	int a,b;
	frac(int _a,int _b){int g=gcd(_a,_b); a=_a/g; b=_b/g;}
	frac(){}
	friend bool operator<(frac a, frac b) {
		return (ll)a.a*b.b < (ll)b.a*a.b;
	}
	friend bool operator==(frac a, frac b) {
		return a.a==b.a && a.b==b.b;
	}
}