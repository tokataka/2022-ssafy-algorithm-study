#include <iostream>

using namespace std;

int N;
int sum = 0;
int arr[20] = {0};
int dat[2000] = {0};

void dfs(int level, int start) {
    if (level == N) {
        int result = 0;
        for (int i = 0; i < level; i++) {
            if (arr[i] == 1) result += 1;
            if (arr[i] == 2) result += 5;
            if (arr[i] == 3) result += 10;
            if (arr[i] == 4) result += 50;
        }
        dat[result]++;
        return;
    }

    for (int i = start; i <= 4; i++) {
        arr[level] = i;
        dfs(level + 1, i);
        arr[level] = 0;
    }
    return;
}

int main() {
    cin >> N;
    dfs(0, 1);
    for (int i = 0; i < 2000; i++) {
        if (dat[i]) sum++;
    }
    cout << sum;
    return 0;
}