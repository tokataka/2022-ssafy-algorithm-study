#include <iostream>
#include<queue>
#include<cmath>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int K, N;
int arr[100];

int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}

	while (--N >= 1) {
		long long now = pq.top();
		pq.pop();
		for (int i = 0; i < K; i++) {
			long long a = now * arr[i];
			if (a >= pow(2, 31)) continue;
			pq.push(a);
		}
		while (pq.top() == now) {
			pq.pop();
		}
	}
	cout << pq.top();
	return 0;
}