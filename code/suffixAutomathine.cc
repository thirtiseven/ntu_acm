//Author:CookiC
#include<cstring>
#define MAXN 10000

struct State{
	State *f,*c[26];
	int len;
};

State *root,*last,*cur;
State StatePool[MAXN];

State* NewState(int len){
	cur->len=len;
	cur->f=0;
	memset(cur->c,0,sizeof(cur->c));
	return cur++;
}

void Init(){
	cur=StatePool;
	last=StatePool;
	root=NewState(0);
}

void Extend(int w){
	State *p = last;
	State *np = NewState(p->len+1);
	while(p&&!p->c[w]) {
		p->c[w] = np;
		p = p->f;
	}
	if(!p) {
		np->f=root;
	} else {
		State *q=p->c[w];
		if(p->len+1==q->len) {
			np->f=q;
		} else {
			State *nq = NewState(p->len+1);
			memcpy(nq->c, q->c, sizeof(q->c));
			nq->f = q->f;
			q->f = nq;
			np->f = nq;
			while(p&&p->c[w]==q) {
				p->c[w]=nq;
				p=p->f;
			}
		}
	}
	last=np;
}

bool Find(char *s,int len) {
	int i;
	State *p=root;
	for(i=0;i<len;++i) {
		if(p->c[s[i]-'a']) {
			p=p->c[s[i]-'a'];
		} else {
			return false;
		}
	}
	return true;
}