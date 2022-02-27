#include <vector>
#include <iostream>
using namespace std;

int s;
int a[50], b[50];

int main() {
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < s; i++) {
        cin >> b[i];
    }

    int sum = 0;
    for (int i = 0; i < s - 1; i++) {
        for (int j = i; j < s; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }

            if (b[i] < b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
        sum += a[i] * b[i];
    }

    cout << sum + (a[s - 1] * b[s - 1]);

    return 0;
}