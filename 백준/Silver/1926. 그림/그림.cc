#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[502][502];
int vis[502][502];

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

    int picture_count = 0, mx=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 1 || board[i][j] == 0) continue;  //아직 안 곳이면서 가야할 곳인 경우
            
            picture_count++;
            queue<pair<int, int>> q;

            q.push({i, j});
            vis[i][j] = 1;
            int width = 0;

            while(!q.empty()) { 
                pair<int, int> cur = q.front(); q.pop();
                width++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;

                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    
                }
            }
            mx = max(mx, width);
        
        }
    }

    cout << picture_count << '\n' << mx;

    return 0;
}