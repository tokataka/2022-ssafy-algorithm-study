#include <iostream>

using namespace std;

char arr[26][3];
int node[26][3] = { 0 };

void pre(int value) {
    if (value == 100) return;

    cout << (char)(value + 'A');
    pre(node[value][1]);
    pre(node[value][2]);
    return;
}

void mid(int value) {
    if (value == 100) return;

    mid(node[value][1]);
    cout << (char)(value + 'A');
    mid(node[value][2]);
    return;
}

void post(int value) {
    if (value == 100) return;

    post(node[value][1]);
    post(node[value][2]);
    cout << (char)(value + 'A');
    return;
}

//output 작성
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int y = arr[i][0] - 'A';
        if (arr[i][1] == '.') node[y][1] = 100;
        else node[y][1] = arr[i][1] - 'A';
        if (arr[i][2] == '.') node[y][2] = 100;
        else node[y][2] = arr[i][2] - 'A';
    }

    pre(0);
    cout << endl;
    mid(0);
    cout << endl;
    post(0);

    return 0;
}