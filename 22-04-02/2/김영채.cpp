#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int minpak = 2000, minind = 2000;
	for (int i = 0; i < M; i++) {
		int pak, ind;
		cin >> pak >> ind;
		if (minpak > pak) minpak = pak;
		if (minind > ind) minind = ind;
	}
	int indmon = minind * N;
	cout << min((N / 6 + 1)*minpak, min(N*minind, N / 6 * minpak + N % 6 * minind));
	return 0;
}