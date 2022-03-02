#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>

using namespace std;

int parents[1000001];

int getParent(int node) {
	if (parents[node] == node) return node; // node is the root, hasn't united yet
	return parents[node] = getParent(parents[node]); //the highest parent (the node referring to itself) found until now
}

void unite(int start, int end) { // Put these two nodes in the same graph!
	int sp = getParent(start); // find the root of the graph
	int ep = getParent(end);
	if (sp == ep) return; // already unified, already belong in the same graph (share the same root)
	if (sp < ep) parents[ep] = sp; // larger node refers to the smaller node -> O(1)
	else parents[sp] = ep;
}

bool check(int start, int end) {
	int sp = getParent(start);
	int ep = getParent(end);
	if (sp == ep) return true;
	return false;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N+1; ++i) parents[i] = i; // N graphs
	for (int i = 0; i < M; ++i) {
		int order, a, b;
		scanf("%d %d %d", &order, &a, &b);
		if (order == 0) {
			unite(a, b); // union
		} else { // check if these two nodes belong in the same graph
			int p1 = getParent(a);
			int p2 = getParent(b);
			if (p1 == p2) printf("%s\n", "YES"); // share the same root = belong in the same graph
			else printf("%s\n", "NO");
		}
	}
}