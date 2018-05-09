int cnt[maxn];//存储质因子是什么
int num[maxn];//该质因子的个数
int tot = 0;//质因子的数量
void factorization(int x)//输入x，返回cnt数组和num数组
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			cnt[tot]=i;
			num[tot]=0;
			while(x%i==0)
			{
				x/=i;
				num[tot]++;
			}
			tot++;
		}
	}
	if(x!=1)
	{
		cnt[tot]=x;
		num[tot]=1;
		tot++;
	}
}