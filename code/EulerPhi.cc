LL EulerPhi(LL n){
	LL m = sqrt(n + 0.5);
	LL ans = n;
	for(LL i = 2; i <= m; ++i)
	if(n % i == 0) { 
		ans = ans - ans / i;
	while(n % i == 0) 
		n/=i;
	} 
	if(n > 1)
		ans = ans - ans / n; 
	return ans;
}