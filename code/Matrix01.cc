#include <bitset> 
#define maxn 1000
struct Matrix01{ 
	int n,m;
	std::bitset<maxn> a[maxn];
	void Resize(int x,int y){ 
		n=x;
		m=y; 
	}
	std::bitset<maxn>& operator [] (int n) { 
		return a[n];
	}
	void print(){ 
		for(int i = 0; i < n; ++i) 
			std::cout << a[i] << std::endl;
		} 
};

Matrix01 operator & (Matrix01 &a,Matrix01 &b){ int i,j,k;
	Matrix01 c; 
	c.Resize(a.n,b.m); 
	for(i = 0; i < a.n; ++i) {
	c[i].reset(); 
	for(j = 0; j < b.m; ++j)
		if(a[i][j]) 
			c[i]|=b[j];
		}
	return c; 
}