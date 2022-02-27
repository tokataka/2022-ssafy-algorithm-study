#include<stdio.h>
#include<iostream>
#include<vector>

int N;

using namespace std;

struct Node {
	char l, r;
};

vector<Node>tree(27);

void preorder(char target) {
	if (target == '.') return;
	printf("%c", target);
	preorder(tree[target - 'A'].l);
	preorder(tree[target - 'A'].r);
}

void inorder(char target) {
	if (target == '.') return;
	inorder(tree[target - 'A'].l);
	printf("%c", target);
	inorder(tree[target - 'A'].r);
}

void postorder(char target) {
	if (target == '.') return;
	postorder(tree[target - 'A'].l);
	postorder(tree[target - 'A'].r);
	printf("%c", target);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		char node, lnode, rnode;
		cin >> node;
		cin >> lnode;
		cin >> rnode;
		tree[node - 'A'].l = lnode;
		tree[node - 'A'].r = rnode;
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	return 0;
}