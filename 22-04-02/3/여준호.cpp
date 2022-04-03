#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int coin[105];
int DP[10005];


void input() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
}

int main()
{
	input();
	DP[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			DP[j] = DP[j] + DP[j - coin[i]];
		}
	}
	cout << DP[k];
	return 0;
}