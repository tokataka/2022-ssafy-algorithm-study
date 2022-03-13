#include <iostream>
using namespace std;

int n;
int buf[1000000];

int dfs(int level) {
	buf[1] = 0;
	for (int i = 2; i <= level; i++) {
		buf[i] = buf[i - 1] + 1;
		if (i % 2 == 0 && buf[i] > buf[i / 2] + 1) {
			buf[i] = buf[i / 2] + 1;
		}
		if (i % 3 == 0 && buf[i] > buf[i / 3] + 1) {
			buf[i] = buf[i / 3] + 1;
		}
	}
	return buf[level];
}

int main()
{
	cin >> n;
	int ans = dfs(n);
	cout << ans;
	return 0;
}
