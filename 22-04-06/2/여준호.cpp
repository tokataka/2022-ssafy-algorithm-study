#include <iostream>
using namespace std;

int main()
{
	/*ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/

	int DP[1005] = { 0, 1, 2 };
	int n;
	cin >> n;
	for (int i = 3; i <= n; i++) {
		DP[i] = (DP[i - 2] + DP[i - 1])%10007;
	}

	cout << DP[n];

	return 0;
}