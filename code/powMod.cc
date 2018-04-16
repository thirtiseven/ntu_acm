using LL = long long;

LL PowMod(LL a, LL b, const LL &Mod) { 
	a %= Mod;
	LL ans = 1; 
	while(b) {
		if (b & 1){
			ans = (ans * a) % Mod; 
		} 
		a = (a * a) % Mod;
		b >>= 1;
	}
	return ans; 
}
