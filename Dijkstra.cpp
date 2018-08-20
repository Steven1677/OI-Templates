#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
const int INF = 2147483647;

int n, m, s;

struct Edge{
	int from, to, dist;
	Edge(int u, int v, int d): from(u), to(v), dist(d) {}
};

struct HeapNode{
	int d, u;
	bool operator < (const HeapNode& rhs) const{
		return d > rhs.d;	
	}
};

struct Dijkstr{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	
	void init(int n){
		this -> n = n;
		for(int i = 1; i <= n; i++) G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist){
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(int s){
		priority_queue<HeapNode> Q;
		for(int i = 1; i <= n; i++) d[i] = INF;
		d[s] = 0;
		memset(vis, 0, sizeof(vis));
		Q.push((HeapNode){0, s});
		while(!Q.empty()){
			HeapNode x = Q.top(); Q.pop();
			int u = x.u;
			if(vis[u]) continue;
			vis[u] = true;
			for(int i = 0; i < G[u].size(); i++){
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist){
					d[e.to] = d[u] + e.dist;
					Q.push((HeapNode){d[e.to], e.to});
				}
			}
		}
	}
} D;

int main(){
	scanf("%d%d%d", &n, &m, &s);
	D.init(n);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		D.AddEdge(u, v, w);
	}
	D.dijkstra(s);
	for(int i = 1; i <= n; i++)
		printf("%d ", D.d[i]);
	return 0;
}
