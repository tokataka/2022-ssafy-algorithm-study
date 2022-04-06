#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int N;
int answer[1001];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) {
		if (i == 1) answer[i] = 1;
		else if (i == 2) answer[i] = 2;
		else answer[i] = (answer[i - 2] + answer[i - 1]) % 10007;
	}
	printf("%d", answer[N]);
}