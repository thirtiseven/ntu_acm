//整型
//若读入不成功，返回false 
//ios::sync_with_stdio(true)
//#include <cctype>
bool quick_in(int &x) { 
	char c;
	while((c = getchar()) != EOF && !isdigit(c)); 
	if(c == EOF) {
		return false;
	}
	x = 0;
	do {
		x *= 10;
		x += c - '0'; 
	} while((c = getchar()) != EOF && isdigit(c)); 
	return true;
}

//带符号整型
//直接=返回值
//#include <cctype>
int read() {
	int x = 0, l = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch=='-') l=-1; ch=getchar();}
	while (isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*1;
}

template <class T>
inline bool Read(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-') ?-1:1 ;
    ret=(c=='-') ?0:(c -'0');
    while(c=getchar(),c>='0'&&c<='9')
        ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}