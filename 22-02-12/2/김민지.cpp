#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

int K, N, answer;
vector<pair<int, int>>route;

void hanoi(int n, int start, int end, int via) {
	if (n == 0) {
		//printf("%d\n", K);
		//answer = max(answer, K);
		return;
	}
	//++K;
	hanoi(n - 1, start, via, end); // 1 -> 2 -> 3에서 1 -> 2로 감
	route.push_back({ start, end });
	printf("%d %d\n", start, end);
	hanoi(n - 1, via, end, start); // 2 -> 3
}

int main() {
	//1. 1st pole -> 2nd pole -> 3rd pole
	//2. 2nd pole -> 3rd pole
	// 2^20-1: route stack save (x)

	scanf("%d", &N);
	K = 0;
	cout << (1 << N) - 1 << "\n";
	hanoi(N, 1, 3, 2);

	//printf("%d\n", answer);
	//for (vector<pair<int, int>>::iterator iter = route.begin(); iter != route.end(); ++iter) {
	//	printf("%d %d\n", iter->first, iter->second);
	//}
}