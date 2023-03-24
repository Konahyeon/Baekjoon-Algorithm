#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int board[302][302];
int dist[302][302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int s; //한 변의 길이
        cin >> s;

        int src_x, src_y, dst_x, dst_y;
        cin >> src_x >> src_y;
        cin >> dst_x >> dst_y;

        //초기 위치와 이동하려는 위치가 같은 경우
        if (src_x == dst_x && src_y == dst_y) {
            cout << 0 << '\n';
            continue;
        }

        queue<pair<int, int>> q;
        q.push({src_x, src_y});

        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();

            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= s || ny < 0 || ny >= s) continue;
                if (dist[nx][ny] > 0 || board[nx][ny] > 0) continue;

                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }

        cout << dist[dst_x][dst_y] << '\n';

        memset(board, 0, sizeof(board));
        memset(dist, 0, sizeof(dist));
    }

    return 0;
}