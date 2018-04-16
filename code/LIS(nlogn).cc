int arr[maxn], n;

template<class Cmp>  
int LIS (Cmp cmp) {  
	static int m, end[maxn];  
	m = 0;  
	for (int i=0; i<n; i++) {  
		int pos = lower_bound(end, end+m, arr[i], cmp)-end;  
		end[pos] = arr[i], m += pos==m;  
	}  
	return m;  
}  

bool greater1(int value) {  
	return value >=1;  
}  

/*********
	std::cout << LIS(std::less<int>()) << std::endl;         //严格上升  
    std::cout << LIS(std::less_equal<int>()) << std::endl;   //非严格上升  
    std::cout << LIS(std::greater<int>()) << std::endl;      //严格下降  
    std::cout << LIS(std::greater_equal<int>()) << std::endl;//非严格下降  
    std::cout << count_if(a,a+7,std::greater1) << std::endl; //计数  
**********/