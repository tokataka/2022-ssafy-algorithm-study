#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100000] = { 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int max = -99999;
	for (int i = 0; i < N; i++) {
		if (arr[i] * (N - i) > max) max = arr[i] * (N - i);
	}
	cout << max;
	return 0;
}