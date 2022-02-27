//https://www.acmicpc.net/problem/1817

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int>books;
	for (int i = 0; i < N; ++i) {
		int book;
		cin >> book;
		books.push_back(book);
	}
	int answer = 0;
	int pointer = 0;
	int current = 0;
	while (pointer < N) {
		current += books[pointer];
		if (current > M) {
			current = books[pointer];
			++answer;
		}
		++pointer;
	}

	if (current > 0) ++answer;
	printf("%d", answer);
}