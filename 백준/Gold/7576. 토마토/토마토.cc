#include <iostream>
#include <queue>
using namespace std;

int board[1002][1002];
int dist[1002][1002];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int m, n;
    cin >> m >> n;
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            // 토마토 없는 경우
            if (board[i][j] == -1) {
                dist[i][j] = -1;
            }
            //익은 토마토인 경우
            if (board[i][j] == 1) {
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] == -1 || board[nx][ny] != 0) continue; //안 봐도 되는 부분
            q.push({nx, ny});
            board[nx][ny] = 1;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    int min_day = -99;
    int already_check = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //토마토가 모두 익지는 못하는 상황일 경우
            if (board[i][j] == 0) {
                cout << -1;
                return 0;
            }
            //저장될 때부터 모든 토마토 익어있는 경우인지 확인하기 위한 수치
            if (dist[i][j] == 0) {
                already_check++;
            }
            min_day = max(dist[i][j], min_day);
        }
    }

    //저장될 때부터 모든 토마토가 익어있는 상태일 경우
    if (already_check == m*n) {
        cout << 0;
    }
    else {
        cout << min_day;
    }

    return 0;
}