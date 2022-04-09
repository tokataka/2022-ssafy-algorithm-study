#include <iostream>

using namespace std;

int main()
{
	int dp[1010] = { 0 };						//���� ������ �迭 ����
	int n;

	cin >> n;

	dp[1] = 1;									//ù��° �迭 1�� ����
	dp[2] = 2;									//�ι�° �迭 2�� ����

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];			//��ȭ��
		dp[i] %= 10007;							//10007�� ���� ������ �� ����
	}

	cout << dp[n];								//n��° �� ���
}