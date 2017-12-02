#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 100005;

int a[maxn], x, y, m, n, comd, k, _sum;

struct segmentTree{
	long long sum[2*maxn], addv[2*maxn];
	void build(int o, int l, int r){
		addv[o] = 0;
		if(l == r) sum[o] = a[l];
		else{
			int mid = (l+r)>>1;
			int lc = o << 1;
			int rc = o << 1 | 1;
			build(lc, l, mid);
			build(rc, mid+1, r);
			sum[o] = sum[lc] + sum[rc];
		}
	}
	void maintain(int o, int l, int r){
		int lc = o << 1;
		int rc = o << 1 | 1;
		if(l < r) sum[o] = sum[lc] + sum[rc];
		if(l == r) sum[o] += k;
		else sum[o] += addv[o]*(long long)(r-l+1);
	}
	void update(int o, int l, int r){
		int lc = o << 1; 
		int rc = o << 1 | 1;
		if(x <= l && y >= r) addv[o] += k;
		else{
			int mid = l + ((r - l)>>1);
			if(x <= mid) update(lc, l, mid);
			if(y > mid) update(rc, mid+1, r);
		}
		maintain(o, l, r);
	}
	void query(int o, int l, int r, int add){
		if(x <= l && y >= r)
			_sum += sum[o] + add * (long long)(r-l+1);
		else{ 
			int mid = l + (r - l) >> 1;
			if(x <= m) query(o<<1, l, mid, add + addv[o]);
			if(y > m) query(o<<1|1, mid + 1, r, add+addv[o]);
		}
	}
}tree;


int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", a+i);
	tree.build(1, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("%d", &comd);
		if(comd == 1){
			scanf("%d%d%lld", &x, &y, &k);
			tree.update(x, y, k);
		}
		if(comd == 2){
			scanf("%d%d", &x, &y);
			tree.query(1, 1, n, 0);
			printf("%d\n", _sum);
		}
	}
	return 0;
}
