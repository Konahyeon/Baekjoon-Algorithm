#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int board[52][52];
bool vis[52][52];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        
        int m, n, k;
        cin >> m >> n >> k;

        //배추 있는 곳 표시
        while (k--) {
            int x, y;
            cin >> x >> y; //x: 가로, y: 세로

            board[y][x] = 1;
        }

        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == true || board[i][j] == 0) continue; //이미 방문했거나 배추 없는 곳이면 패스

                queue<pair<int, int>> q;

                //bfs 시작점
                q.push({i, j});
                vis[i][j] = 1;
                cnt++;

                while(!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();

                    //상하좌우 네 방향에 배추 있는 경우 찾는 과정
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위 벗어난 경우 패스
                        if (vis[nx][ny] == true || board[nx][ny] == 0) continue; //이미 방문했거나 배추 없는 곳이면 패스
                        
                        q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        cout << cnt << '\n';

        //테스트 케이스 반복하기 위해 메모리 초기화
        memset(board, 0, sizeof(board));
        memset(vis, false, sizeof(vis));
    }

    return 0;
}