#include<iostream>

using namespace std;

int arr[10000];
int sum[10000];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			if (sum == M) {
				cnt++;
				break;
			}
			else if (sum > M) break;
		}
	}

	cout << cnt;
	return 0;
}