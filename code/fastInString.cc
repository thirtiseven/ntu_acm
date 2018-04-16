bool quick_in(char *p) { 
	char c;
	while((c = getchar()) != EOF && (c == ' ' || c == '\n')); 
	if(c == EOF) {
		return false; 
	}
	do {
		*p++ = c; 
	} while((c=getchar()) != EOF && c != ' ' && c != '\n'); 
	*p = 0;
	return true;
}