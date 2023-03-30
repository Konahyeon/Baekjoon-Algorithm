#include <iostream>
using namespace std;

int board[130][130];
int cnt[2]; //0: 하얀색, 1: 파란색

bool check(int x, int y, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[x][y] != board[x+i][y+j])
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int n) {
    if (check(x, y, n)) {
        cnt[board[x][y]]++;
        return; //base condition
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int new_n = n/2;
            solve(x+i*new_n, y+j*new_n, new_n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(0, 0, n);

    cout << cnt[0] << '\n';
    cout << cnt[1] << '\n';

    return 0;
}