#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector<int> a;
int n, d[100][100];

void RMQ_init(const vector<int>& A){
	int n = a.size();
	for(int i = 0; i < n; i++) d[i][0] = A[i];
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 0; i + (1<<j) - 1 < n; i++)
			d[i][j] = min(d[i][j-1], d[i + (1<<(j-1))][j-1]);
}

int RMQ(int l, int r){
	int k = 0;
	while(1<<(k+1) <= r-l+1) k++;
	return min(d[l][k], d[r-(1<<k)+1][k]);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	RMQ_init(a);
	int l, r;
	scanf("%d%d", &l, &r);
	printf("%d", RMQ(l, r));
	return 0;
}
