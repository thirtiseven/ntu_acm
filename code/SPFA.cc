#include <queue> 
#include <cstring> 
#include <vector> 
#define maxn 10007 
#define INF 0x7FFFFFFF 
using namespace std;
struct Edge{ 
	int v,w;
	Edge(int v,int w):v(v),w(w){} 
};
int d[maxn];
bool inq[maxn]; 
vector<Edge> G[maxn];
void SPFA(int s){ 
	queue<int> q;
	memset(inq,0,sizeof(inq)); 
	for(int i=0;i<maxn;++i)
		d[i]=INF; 
	d[s]=0;
	inq[s]=1; 
	q.push(s);
	int u; 
	while(!q.empty()){
		u=q.front(); 
		q.pop(); 
		inq[u]=0;
		for(vector<Edge>::iterator e=G[u].begin();e!=G[u].end();++e) {
			if(d[e->v]>d[u]+e->w){
				d[e->v]=d[u]+e->w; 
				if(!inq[e->v]){
					q.push(e->v);
					inq[e->v]=1; 
				}
			} 
    	}
	}	
}