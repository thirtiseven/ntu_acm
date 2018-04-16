void quick_out(int x) { 
	char str[13];
	if(x) {
		int i;
 		for(i = 0; x; ++i) { 
			str[i] = x % 10 + '0';
			x /= 10; 
		}
		while(i--) {
			putchar(str[i]);
		}
	} else {
		putchar('0');
	}
}