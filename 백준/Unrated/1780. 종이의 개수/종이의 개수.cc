#include <iostream>
using namespace std;

int board[2200][2200];
int cnt[3]; //-1, 0, 1 종이 개수

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
    //다 같은 경우
    if (check(x, y, n)) {
        cnt[board[x][y]+1]++;
        return;
    }

    //다른 경우
    for (int i = 0; i < 3; i++) { //항상 9등분 이므로
        for (int j = 0; j < 3; j++) {
            int new_n = n/3;
            solve(x+i*new_n, y+j*new_n, new_n); //기존 시작점 기준으로, 등분 했을 때의 각 시작점 구함
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

    for (int i = 0; i < 3; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}