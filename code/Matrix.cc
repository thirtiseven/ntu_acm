#define maxm 10 
typedef long long LL;

const LL Mod=1e9+7;
struct Matrix { 
	int n, m;
	LL mat[maxm][maxm];
	void clear() {
		memset(mat, 0, sizeof(mat));
	}

	Matrix(int n, int m) :n(n), m(m) {
		//不要设置默认构造函数，让编译器检查初始化遗漏 
		clear();
	}

	Matrix operator +(const Matrix &M) const {
		Matrix res(n, m);
		for (LL i = 0; i < n; ++i) for (LL j = 0; j < m; ++j) {
	 		res.mat[i][j] = (mat[i][j] + M.mat[i][j]) % Mod; 
		}
		return res; 
	}	

	Matrix operator *(const Matrix &M) const { 
		if (m != M.n){
			std::cout << "Wrong!" << std::endl;
			return Matrix(-1, -1); 
		}	
		Matrix res(n, M.m); 
		res.clear();
		int i,j,k;
		for (i = 0; i < n; ++i)
			for (j = 0; j < M.m; ++j)
				for (k = 0; k < m; ++k) {
					res.mat[i][j] += mat[i][k] * M.mat[k][j]%Mod; 
					res.mat[i][j] %= Mod;
				} 
		return res;
	}	
	Matrix operator *(const LL &x) const { 
		Matrix res(n,m);
		int i,j; 
		std::cout << n << ' ' << m << std::endl; 
		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j) 
				res[i][j] = mat[i][j] * x % Mod;
		return res; 
	}

	Matrix operator ^(LL b) const { // 矩阵快速幂 ， 取余Mod 
		if (n != m) 
			return Matrix(-1, -1);
		Matrix a(*this);
		Matrix res(n, n);
		res.clear();
		for (LL i = 0; i < n; ++i) 
			res.mat[i][i] = 1; 
		for (; b; b >>= 1) {
			if (b & 1) {
				res = a * res;
			}
			a = a * a; 
		}
		return res; 
	}

	LL* operator [](int i) { 
		return mat[i];
	}

	void Print() const {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) 
				std::cout << mat[i][j] << ' ';
			std::cout << '\n'; 
		}
	}
};