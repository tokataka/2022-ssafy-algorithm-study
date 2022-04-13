#include <iostream>
#include<algorithm>

using namespace std;

int T, K;
int arr[500], dp[500][500], sum[500];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> arr[j];
			if (!j) {
				sum[j] = arr[j];
				continue;
			}
			sum[j] = sum[j - 1] + arr[j];
		}
		for (int size = 1; size <= K; size++) {
			for (int start = 0; start <= K - size; start++) {
				int end = start + size;
				dp[start][end] = 2134567890;
				for (int mid = start; mid < end; mid++) {
					dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
				}
			}
		}
		cout << dp[0][K-1] << endl;
	}
	return 0;
}