LL Inv(LL a, LL n){
	return PowMod(a, EulerPhi(n) - 1, n); 
	//return PowMod(a,n−2,n); //n为素数
}
