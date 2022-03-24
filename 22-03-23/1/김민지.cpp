#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

typedef long long ll;

int K, N;

int main() {
	scanf("%d %d", &K, &N);
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	vector<int>numbers;
	for (int i = 0; i < K; ++i) {
		int num;
		cin >> num;
		numbers.push_back(num);
	}
	pq.push(1);
	int cnt = -1;
	unordered_map<ll, bool>map;
	ll maxi = -1;
	ll answer = 0;
	while (!pq.empty()) {
		ll cur = pq.top();
		pq.pop();
		++cnt;
		if (cnt == N) {
			answer = cur;
			break;
		}
		for (int i = 0; i < numbers.size(); ++i) {
			ll next = cur * numbers[i];
			if (map.count(next) != 0) continue;
			if (pq.size() > N && maxi < next) continue;
			pq.push(next);
			map[next] = true;
			maxi = max(maxi, next);
		}
	}
	printf("%lld", answer);
}