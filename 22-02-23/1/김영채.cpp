#include <iostream>

using namespace std;

int day[16];
int price[16];
int maxprice[16] = { 0 };

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> day[i] >> price[i];
    }

    for (int now = N; now >= 1; now--) {
        int scheduled = now + day[now];
        if (scheduled - 1 > N) {
            maxprice[now] = maxprice[now + 1];
        }
        else {
            if (maxprice[now + 1] < price[now] + maxprice[scheduled]) maxprice[now] = price[now] + maxprice[scheduled];
            else maxprice[now] = maxprice[now+1];
        }
    }
    cout << maxprice[1];
    return 0;
}