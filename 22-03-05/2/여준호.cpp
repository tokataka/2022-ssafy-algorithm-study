#include <iostream>
using namespace std;

int A[10001];

int main()
{
	int N;
	long long M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) { //시작점 for문
		long long sum = 0;
		for (int j = i; j < N; j++) { //합 for문
			sum += A[j];
			if (sum == M) { 
				cnt++;
				break;
			}
			else if (sum > M) { break; }
		}
	}
	cout << cnt;

	return 0;
}