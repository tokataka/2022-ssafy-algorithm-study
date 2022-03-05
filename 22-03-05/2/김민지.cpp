////https://www.acmicpc.net/problem/2003
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//int numbers[10000];
//
//int main() {
//	int N, M;
//	scanf("%d %d", &N, &M);
//	for (int i = 0; i < N; ++i) {
//		int target;
//		scanf("%d", &target);
//		numbers[i] = target;
//	}
//	int answer = 0;
//	for (int i = 0; i < N-1; ++i) {
//		int sum = numbers[i];
//		if (sum == M) {
//			++answer;
//			continue;
//		}
//		for (int j = i+1; j < N; ++j) {
//			sum += numbers[j];
//			if (sum == M) {
//				++answer;
//				break;
//			}
//			else if (sum > M) break;
//		}
//	}
//	printf("%d", answer);
//}