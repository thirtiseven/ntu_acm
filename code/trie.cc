#include <cstring>

const int maxn = 10000*50+10; 
const int max_stringlen = 26+2;
int trie[maxn][max_stringlen];
int val[maxn];
int trie_index;

int index_of(const char &c) { 
	return c - 'a';
}
void trie_init() { 
	trie_index = 0;
	memset(val, 0, sizeof(val));
	memset(trie, 0, sizeof(trie)); 
}
void trie_insert(char *s, int v) { //要求v!=0 
	int len = strlen(s);
	int now = 0;
	for (int i = 0; i < len; ++i) {
		int idx = index_of(s[i]); 
		int &tr = trie[now][idx]; 
		if (!tr) {
			tr = ++trie_index; 
		}
		now = tr; 
	}
	val[now] += v; 
}