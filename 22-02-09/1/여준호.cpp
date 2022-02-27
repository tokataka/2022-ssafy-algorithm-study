#include <iostream>
#include <cstring>
using namespace std;

int N;
char vect[26][4];


void front(char lev) {
    if (lev == '.') { 
        return;
    }
    cout << lev;
    front(vect[lev - 'A'][1]);
    front(vect[lev - 'A'][2]);
}

void middle(char lev) {
    if (lev == '.') {
        return;
    }
    middle(vect[lev - 'A'][1]);
    cout << lev;
    middle(vect[lev - 'A'][2]);
}


void back(char lev) {
    if (lev == '.') {
        return;
    }
    back(vect[lev - 'A'][1]);
    back(vect[lev - 'A'][2]);
    cout << lev;

}


int main()
{
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> vect[y][x];
        }
    }
    char min = 'Z';
    for (int y = 0; y < N; y++) {
        for (int z = y + 1; z < N; z++) {
            if (vect[y][0] > vect[z][0]) {
                char temp[4];
                strcpy(temp, vect[y]);
                strcpy(vect[y], vect[z]);
                strcpy(vect[z], temp);
            }
        }
    }

    front(vect[0][0]);
    cout << endl;
    middle(vect[0][0]);
    cout << endl;
    back(vect[0][0]);

    int de = -1;
    return 0;
}
