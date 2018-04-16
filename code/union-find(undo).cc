#include <iostream>
#include <stack>
#include <utility>

class UFS {
	private:
		int *fa, *rank;
		std::stack <std::pair <int*, int> > stk ;    
	public:
		UFS() {}
		UFS(int n) {
			fa = new int[(const int)n + 1];
			rank = new int[(const int)n + 1];
			memset (rank, 0, n+1);   
			for (int i = 1; i <= n; ++i) {
				fa [i] = i;
			}
		}
		inline int find(int x) {
			while (x ^ fa[x]) {
				x = fa[x];
			}
			return x ;
		}
		inline int Join (int x, int y) {
			x = find(x), y = find(y);
			if (x == y) {
				return 0;
			}
			if (rank[x] <= rank[y]) {
				stk.push(std::make_pair (fa + x, fa[x]));
				fa[x] = y;
				if (rank[x] == rank[y]) {
					stk.push(std::make_pair (rank + y, rank[y]));
					++rank[y];
					return 2;
				}
				return 1 ;
			}
			stk.push(std::make_pair(fa + y, fa [y]));
			return fa[y] = x, 1;
		}
		inline void Undo ( )  {
			*stk.top( ).first = stk.top( ).second ;
			stk.pop( ) ;
		}
}T;