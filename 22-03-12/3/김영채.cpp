#include<iostream>

using namespace std;

int dp[1000001];

int dfs(int n) {
	if (n == 1) {
		return 0;
	}
	if (dp[n] != -2134567890) return dp[n];

	dp[n] = dfs(n - 1) + 1;
	if (!(n % 2)) {
		int tmp = dfs(n / 2) + 1;
		if (dp[n] > tmp) dp[n] = tmp;
	}
	
	if (!(n % 3)) {
		int tmp = dfs(n / 3) + 1;
		if (dp[n] > tmp) dp[n] = tmp;
	}
	return dp[n];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < 1000001; i++) {
		dp[i] = -2134567890;
	}
	cout << dfs(N);
	return 0;
}