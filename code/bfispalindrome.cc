bool is_palindrome(int bob) {
	int clare = bob, dave = 0;
	while (clare){
		dave = dave * 10 + clare % 10;
		clare /= 10;
	}
	if(bob == dave) {
		return true;
	} else {
		return false;
	}
}