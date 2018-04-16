class TwoSAT{
	private:
		const static int maxm=maxn*2;
		
		int S[maxm],c;
		vector<int> G[maxm];
		
		bool DFS(int u){
			if(vis[u^1])
				return false;
			if(vis[u])
				return true;
			vis[u]=1;
			S[c++]=u;
			for(auto &v:G[u])
				if(!DFS(v))
					return false;
			return true;
		}
		
	public:
		int N;
		bool vis[maxm];
		
		void Clear(){
			for(int i=2;i<(N+1)*2;++i)
				G[i].clear();
			memset(vis,0,sizeof(bool)*(N+1)*2);
		}
		
		void AddClause(int x,int xv,int y,int yv){
			x=x*2+xv;
			y=y*2+yv;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		
		bool Solve(){
			for(int i=2;i<(N+1)*2;i+=2)
				if(!vis[i]&&!vis[i+1]){
					c=0;
					if(!DFS(i)){
						while(c>0)
							vis[S[--c]]=0;
						if(!DFS(i+1))
							return false;
					}
				}
			return true;
		}
	};