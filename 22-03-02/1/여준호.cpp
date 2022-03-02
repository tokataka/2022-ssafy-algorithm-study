#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1000000];

int Find(int now) {
	if (parent[now] == now) {
		return now;
	}
	int ret = Find(parent[now]);
	parent[now] = ret;
	return ret;
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) return;
	parent[pb] = pa;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if(a==0){
			Union(b, c);
		}
		else {
			if (Find(b) == Find(c)) { cout << "YES\n"; }
			else { cout << "NO\n"; }
		}
	}

	return 0;
}