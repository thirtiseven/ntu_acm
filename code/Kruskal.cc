#include <vector> 
#include <algorithm> 

#define maxm 1000
#define maxn 1000

class Kruskal { 
	struct UdEdge {
		int u, v, w;
		UdEdge(){}
		UdEdge(int u,int v,int w):u(u), v(v), w(w){}
	};
	int N, M;
	UdEdge pool[maxm]; 
	UdEdge *E[maxm]; 
	int P[maxn];
	int Find(int x){ 
		if(P[x] == x)
			return x;
		return P[x] = Find(P[x]);
	}	
	public:
	static bool cmp(const UdEdge *a, const UdEdge *b) {
		return a->w < b->w; 
	}
	void Clear(int n) { 
		N = n;
		M = 0; 
	}
	void AddEdge(int u, int v, int w) {
		pool[M] = UdEdge(u, v, w);
		E[M] = &pool[M];
		++M; 
	}
	int Run() {
		int i, ans=0;
		for(i = 1; i <= N; ++i) 
			P[i] = i;
		std::sort(E, E+M, cmp); 
		for(i = 0; i < M; ++i) {
			UdEdge *e = E[i]; 
			int x = Find(e->u); 
			int y = Find(e->v); 
			if(x != y) {
				P[y] = x;
				ans += e->w; 
			}
		}
		return ans; 
	}
};