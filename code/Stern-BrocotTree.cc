//Author:CookiC
//未做模板调整，请自行调整
#include <cmath>
#define LL long long
#define LD long double

void SternBrocot(LD X, LL &A, LL &B) {
	A=X+0.5;
	B=1;
	if(A==X)
		return;
	LL la=X, lb=1, ra=X+1, rb=1;
	long double C=A, a, b, c;
	do {
		a = la+ra;
		b = lb+rb;
		c = a/b;
		if(std::abs(C-X) > std::abs(c-X)) {
			A=a;
			B=b;
			C=c;
			if(std::abs(X-C) < 1e-10) {
				break;
			}
		}
		if(X<c) {
			ra=a;
			rb=b;
		} else {
			la=a;
			lb=b;
		}
	} while(lb+rb<=1e5);
}