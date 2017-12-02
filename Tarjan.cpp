#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
const int INF = 2147483647;
const int maxn = 200005;
int n, m, DFN[maxn], LOW[maxn], Belong[maxn], Dindex, SCCcnt;
bool instack[maxn];
struct node{
	int to, val;	
}k;
vector<node> a[maxn];
stack<int> s;
void Tarjan(int u){
	int v;
	DFN[u] = LOW[u] = ++Dindex;
	s.push(u);
	instack[u] = true;
	for(int i = 0; i < a[u].size(); i++){
		v = a[u][i].to;
		if(!DFN[v]){
			Tarjan(v);
			LOW[u] = min(LOW[u], LOW[v]);
		}
		else if(instack[v])
			LOW[u] = min(LOW[u], DFN[v]);
	}
	if(DFN[u] == LOW[u]){
		SCCcnt++;
		do{
			v = s.top();
			s.pop();
			instack[v] = false;
			Belong[v] = SCCcnt;
		}
		while(u != v);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		node temp;
		temp.to = v;
		temp.val = w;
		a[u].push_back(temp);
	}
	Tarjan(1);
	return 0;
}
