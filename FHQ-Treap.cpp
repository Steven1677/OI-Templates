#include <cstdio>
#include <cstdlib>

struct Node {
	Node* ch[2];
	int v, r, s;
	Node(int v):v(v) { r = rand(); ch[0] = ch[1] = NULL; s = 1; }
	void maintain() {
		s = 1;
		if(ch[0] != NULL) s += ch[0]->s;
		if(ch[1] != NULL) s += ch[1]->s;
	}
};

Node* root;

inline int Size(Node* x) { return x != NULL ? x->s : 0; }

Node* merge(Node* a, Node* b) {
	if(a == NULL) return b;
	if(b == NULL) return a;
	if(a->r > b->r) {
		b->ch[0] = merge(a, b->ch[0]);
		b->maintain();
		return b;
	}
	else {
		a->ch[1] = merge(a->ch[1], b);
		a->maintain();
		return a;
	}
}

void split(Node* o, int k, Node* &l, Node* &r) {
	if(o == NULL) { l = r = NULL; return; }
	if(Size(o->ch[0]) >= k) {
		split(o->ch[0], k, l, r);
		o->ch[0] = r;
		o->maintain();
		r = o;
	} else {
		split(o->ch[1], k-Size(o->ch[0])-1, l, r);
		o->ch[1] = l;
		o->maintain();
		l = o;
	}
}

int kth(int k) {
	Node* l, r;
	split(root, k-1, l, r);
	split(r, 1, l, r);
	root = merge(merge())
	return l->v;
}

int main() {
	return 0;	
}
