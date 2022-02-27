#include <iostream>
using namespace std;

int N;
int pow(int x, int n)
{
    int a = 1;

    if (n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            a *= x;
        }
    }
    return a;
}

void hano(int from, int mid, int to, int lev) {
    if (lev == 1) {
        printf("%d %d\n", from, to);
        return;
    }
    hano(from, to, mid, lev - 1);
    printf("%d %d\n", from, to);
    hano(mid, from, to, lev - 1);

}

int main()
{
    cin >> N;
    int count = pow(2, N) - 1;
    cout << count << endl;
    hano(1, 2, 3, N);
    return 0;
}