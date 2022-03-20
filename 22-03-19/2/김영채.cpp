#include <iostream>
#include<queue>

using namespace std;

int arr[100000];
priority_queue<int> mini;
priority_queue<int, vector<int>, greater<int>> maxi;
int N, mid;

int main() {
	scanf("%d", &N);
	scanf("%d", &mid);
	printf("%d\n", mid);
	for (int i = 1; i < N; i++) {
		int val;
		scanf("%d", &val);
		if (val >= mid) maxi.push(val);
		else mini.push(val);
		if (mini.size() - maxi.size() == 2 || mini.size() - maxi.size() == 1) {
			maxi.push(mid);
			mid = mini.top();
			mini.pop();
		}
		else if (maxi.size() - mini.size() == 2) {
			mini.push(mid);
			mid = maxi.top();
			maxi.pop();
		}
		printf("%d\n", mid);
	}
	return 0;
}