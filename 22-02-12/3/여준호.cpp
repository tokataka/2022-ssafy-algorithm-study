#include <iostream>
using namespace std;

int N;

int main()
{
    cin >> N;  //1 ~ 20, N개의 로마숫자
    // I=1, V=5, X=10, L=50
    
    int tmp;
    int sum;
    int arr[1001] = { 0 };
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < N - i+1; j++) {
            for (int k = 0; k < N - i - j+1; k++) {
                tmp = N - i - j - k;
                sum = tmp + i * 5 + j * 10 + k * 50;
                arr[tmp + i * 5 + j * 10 + k * 50]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (arr[i] > 0)cnt++;
    }
    cout << cnt;
    return 0;
}