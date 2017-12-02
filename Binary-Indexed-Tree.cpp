#include <cstdio>
using namespace std;

const int maxn = 100;

int lowbit(int x){
	return x & (-x);	
}

int c[maxn], a[maxn], n, l, r;

int sum(int x){
	int ret = 0;
	while(x > 0){
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d){
	while(x <= n){
		c[x] += d;
		x += lowbit(x);
	}
}

void build(){
	for(int i = 1; i <= n; i++)
		for(int j = i-lowbit(i)+1; j <= i; j++)
			c[i] += a[j];
}

int main(){
	scanf("%d", &n);
	scanf("%d%d", &l, &r);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	build();
	return 0;
}
