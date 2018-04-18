bool prime_or_not[maxn];
for (int i = 2; i <= int(sqrt(maxn)); i++) {
	if (!prime_or_not[i]) {
    	for (int j = i * i; j <= maxn; j = j+i) {
			prime_or_not[j] = 1;
		}
	}
}