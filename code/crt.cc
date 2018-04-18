LL Crt(LL *div, LL *rmd, LL len) { 
	LL sum = 0;
	LL lcm = 1; 
	//lcm为除数们的最小公倍数, 若div互素, 则如下一行计算lcm 
	for (int i = 0; i < len; ++i) 
		lcm *= div[i];
	for (int i = 0; i < len; ++i) {
		LL bsn = lcm / div[i];
		LL inv = Inv(bsn, div[i]);
		// dvd[i] = inv[i] * bsn[i] * rmd[i]
		LL dvd = MulMod(MulMod(inv, bsn, lcm), rmd[i], lcm);
		sum = (sum + dvd) % lcm; 
	}
	return sum; 
}