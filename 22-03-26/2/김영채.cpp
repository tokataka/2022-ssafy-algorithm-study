#include <iostream>
#include<string>

using namespace std;

string arr[100];
int dp[101] = { 0 };
string str;
int N;

int main() {
	cin >> str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[str.length()] = 1;
	for (int j = str.length() - 1; j >= 0; j--) {
		for (int i = 0; i < N;i++) {
			if (str.find(arr[i], j) == j && dp[j + arr[i].length()]) {
				dp[j] = 1;
				break;
			}
		}
	}
	cout << dp[0];
	return 0;
}