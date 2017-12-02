#define INF 2147483647
#include <queue>
#include <cstdio>

const int maxn = 10005;
const int maxm = 500005;

int a[maxn][maxn], dis[maxn], vis[maxn];
int n, m, s;

std::queue<int> q;


void SPFA(int s){ //求单源点s到其他各点的距离（邻接矩阵版本）
	for(int i = 0; i <= n; i++) dis[i] = INF;
	dis[s] = 0; vis[s] = 1; q.push(s);
	int v;
	while(!q.empty()){
		v = q.front(); q.pop();
		vis[v] = 0;
		for(int i = 0; i <= n; i++)
			if(a[v][i] > 0 && dis[i] > dis[v] + a[v][i]){ //松弛操作（原理是三角不等式）
				dis[i] = dis[v] + a[v][i];
				if(vis[i] == 0){
					q.push(i);
					vis[i] = 1;
				}
			}
	}
}

/*void dfsSPFA(int s){ //b[s][0]表示从顶点s出发边的条数
	for(int i = 1; i <= b[s][0]; i++)
		if(dis[b[s][i]] > (dis[s] + a[s][b[s][i]])){ //b[s][i]表示从s出发的第i条边所连接的顶点
			dis[b[s][i]] = dis[s] + a[s][b[s][i]];
			dfsSPFA(b[s][i]);
		}
}
*/
int main(){
	int u, v, w;
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = w;
		a[v][u] = w;
	}
	SPFA(s);
	for(int i = 1; i <= n; i++) printf("%d ", dis[i]);
	return 0;
}
