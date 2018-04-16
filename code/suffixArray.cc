//Author:CookiC
#include <cstring>
const int maxn = 10010;

char str[maxn];
int s[maxn], si[maxn], n;

void BuildSi(int m) {
	//si为第一关键字排在第i位的后缀在s中的下标
	//y为第二关键字排在第i位的后缀在s中的下标 
	//m为字母的种类 
	static int t1[maxn], t2[maxn], c[maxn];
	int *x=t1, *y=t2;
	int i;
	//基数排序 
	memset(c, 0, sizeof(int)*m);
	for(i=0; i<n; ++i)	++c[x[i]=s[i]];
	for(i=1; i<m; ++i)	c[i]+=c[i-1];
	for(i=n-1; i>=0; --i)	si[--c[x[i]]]=i;
	for(int k=1; k<=n; k<<=1) {
		int p=0;
		
		//第二关键字排序 
		for(i=n-k;i<n;++i)	y[p++]=i;
		for(i=0;i<n;++i)	if(si[i]>=k)	y[p++]=si[i]-k;
		
		//第一关键字与第二关键字合并排序 
		memset(c,0,sizeof(int)*m);
		for(i=0;i<n;++i)
			++c[x[y[i]]];
		for(i=0;i<m;++i)
			c[i]+=c[i-1];
		for(i=n-1;i>=0;--i)
			si[--c[x[y[i]]]]=y[i];
		
		//判断相邻元素是否等价，等价则标上同等大小的数字。 
		swap(x,y);
		p=1;
		x[si[0]]=0;
		for(i=1;i<n;++i)
			x[si[i]]=y[si[i-1]]==y[si[i]]&&y[si[i-1]+k]==y[si[i]+k]?p-1:p++;
		if(p>=n)
			break;
		m=p;
	}
}