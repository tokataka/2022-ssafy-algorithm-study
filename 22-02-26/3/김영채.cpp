#include<iostream>

using namespace std;

int  arr[50];

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int cnt = 1;
	if (N == 0) cnt = 0;
	else {
		for (int i = 0; i < N; i++) {
			sum += arr[i];
			if (sum > M) {
				sum = arr[i];
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}