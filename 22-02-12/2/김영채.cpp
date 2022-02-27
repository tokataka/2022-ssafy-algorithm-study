#include <iostream>
using namespace std;

int N;

void repeat(int level, int start, int other, int end) {
    if (level == 1) {
        printf("%d %d\n", start, end);
        return;
    }

    repeat(level - 1, start, end, other);
    printf("%d %d\n", start, end);
    repeat(level - 1, other, start, end);
}

int main() {
    cin >> N;
    cout << (1 << N) - 1 << endl;
    repeat(N, 1, 2, 3);
    return 0;
}