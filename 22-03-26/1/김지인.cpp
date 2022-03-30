#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

int chapters[501];
int sum[501];
int dp[501][501];

int main(int, char**) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int K;
    cin >> K;
    for (int i = 1; i <= K; i++) {
      cin >> chapters[i];
      sum[i] = sum[i - 1] + chapters[i];
    }

    for (int i = 1; i <= K; i++) {
      for (int j = 1; j <= K - i; j++) {
        dp[j][i + j] = INT32_MAX;
        for (int k = j; k < j + i; k++) {
          dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] +
                                               sum[i + j] - sum[j - 1]);
        }
      }
    }

    cout << dp[1][K] << "\n";
  }

  return 0;
}
