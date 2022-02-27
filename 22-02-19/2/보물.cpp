#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
	priority_queue<pair<int, int>>pq;
	// 1. b�� ���ҵ��� ������������ ����
	// 2. a�� ������������ ���� 
	// 3. ���� index�� �ִ� ���ҵ鳢�� ���ϸ� �ּҰ�
	sort(a.begin(), a.end()); // ��������
	sort(b.begin(), b.end(), greater<int>()); // ��������
	int s = 0;
	for (int i = 0; i < n; ++i) s += (a[i] * b[i]);
	printf("%d", s);
}
