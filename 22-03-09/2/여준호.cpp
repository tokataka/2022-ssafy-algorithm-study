#include<iostream>
#include<algorithm>
using namespace std;

int dp[40005];
int num[40005];
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
    
	int size = 1;
	dp[1] = num[1];
	for (int i = 2; i <= n; i++) {
		if (dp[size] < num[i]) {
			size++;
			dp[size] = num[i];
			continue;
		}
		int idx = lower_bound(dp + 1, dp + 1 + size, num[i]) - dp;
		dp[idx] = num[i];
	}
	cout << size;
}