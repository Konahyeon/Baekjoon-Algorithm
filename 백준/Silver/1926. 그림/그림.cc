#include <iostream>
#include <queue>
using namespace std;

bool vis[502][502];
int board[502][502];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int num = 0;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;

            //bfs 새로 시작
            num++;
            int width = 0;
            queue<pair<int, int>> q;
            vis[i][j] = true;
            q.push({i, j});

            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                width++;

                //cur 기준으로 상하좌우 연결된 정점 queue에 push
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (board[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            mx = max(mx, width);
        }
    }
    cout << num << '\n' << mx;

    return 0;
}