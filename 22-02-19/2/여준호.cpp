#include <iostream>
using namespace std;

int n;
int arr1[50];
int arr2[50];
int buf[100] = { 0 };

int main()
{
    //입력
    cin >> n;
    for (int y = 0; y < n; y++) {
        cin >> arr1[y];
    }
    for (int y = 0; y < n; y++) {
        cin >> arr2[y];
        buf[arr2[y]]++;
    }

    //첫배열 arr1[]을 sort
    for (int y = 0; y < n; y++) {
        for (int x = y + 1; x < n; x++) {
            if (arr1[y] < arr1[x]) {
                int temp = arr1[y];
                arr1[y] = arr1[x];
                arr1[x] = temp;
            }
        }
    }

    int sum = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    while (1) {
        if (buf[tmp1] > 0) {
            sum += arr1[tmp2] * tmp1;
            tmp2++;
            buf[tmp1]--;
        }
        if (tmp2 == n) { break; }
        tmp1++;
    }
    cout << sum;
    return 0;
}