#include <iostream>
#include <string>
using namespace std;

string board[68];

bool check(int x, int y, int n) {
    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (board[x][y] != board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n) {

    if (check(x, y, n)) { //다 똑같은 경우
        cout << board[x][y];
        return;
    }

    cout << '(';
    int new_n = n/2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            solve(x+i*new_n, y+j*new_n, new_n);
        }
    }
    cout << ')';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string n;
    cin >> n;
    int stoi_n = stoi(n);
    
    for (int i = 0; i < stoi_n; i++) {
        cin >> board[i];
    }

    solve(0, 0, stoi_n);

    return 0;
}