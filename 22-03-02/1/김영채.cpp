#include<iostream>

using namespace std;

int parent[1000001];

int Find(int now) {
	if (now == parent[now]) return now;
	parent[now] = Find(parent[now]);
	return parent[now];
}

void Union(int a, int b) {
	int ancienta = Find(a);
	int ancientb = Find(b);
	if (ancienta > ancientb) parent[ancienta] = ancientb;
	else if (ancienta < ancientb) parent[ancientb] = ancienta;
	return;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (!op) Union(a, b);
		else {
			if (Find(a) == Find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}