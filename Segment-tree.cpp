#include <cstdio>
typedef long long ll;

const int maxn = 100000 + 10;

ll a[maxn];
ll n, m;
struct node {
	ll addv, val;
}tree[maxn << 2];

void build(int root, ll* a, int l, int r) {
	tree[root].addv = 0;
	if(l == r) tree[root].val = a[l];
	else {
		int mid = (l + r) >> 1;
		build(root << 1, a, l, mid);
		build(root << 1 | 1, a, mid + 1, r);
		tree[root].val = tree[root << 1].val + tree[root << 1 | 1].val;
	}
}

void pushdown(int root, int l, int r) {	
	if(tree[root].addv == 0) return;
	tree[root << 1].addv += tree[root].addv;
	tree[root << 1 | 1].addv += tree[root].addv;
	int mid = (l + r) >> 1;
	tree[root << 1].val += tree[root].addv * (mid - l + 1);
	tree[root << 1 | 1].val += tree[root].addv * (r - mid);
	tree[root].addv = 0;
}

ll query(int root, int l, int r, int x, int y) {
	if(x > r || y < l) return 0;
	if(x <= l && y >= r) return tree[root].val;
	pushdown(root, l , r);
	int mid = (l + r) >> 1;
	ll L = query(root << 1, l, mid, x, y);
	ll R = query(root << 1 | 1, mid + 1, r, x, y);
	return L + R;
}

void update(int root, int l, int r, int x, int y, long long val) {
	if(x > r || y < l) return;
	if(x <= l && y >= r) {
		tree[root].addv += val;
		tree[root].val += val * (r - l + 1);
		return;
	}
	pushdown(root, l, r);
	int mid = (l + r) >> 1;
	update(root << 1, l, mid, x, y, val);
	update(root << 1 | 1, mid + 1, r, x, y, val);
	tree[root].val = tree[root << 1].val + tree[root << 1 | 1].val;
}

int main() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	build(1, a, 1, n);
	for(int i = 1; i <= m; i++) {
		int order;
		scanf("%d", &order);	
		if(order == 1) {
			long long  x, y, k;
			scanf("%lld%lld%lld", &x, &y, &k);	
			update(1, 1, n, x, y, k);
		}
		if(order == 2) {
			long long x, y;
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", query(1, 1, n, x, y));
		}
	}
	return 0;
}
