#include <iostream>
#include <queue>
using namespace std;

string board[102];
int dist[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main (){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;

    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] > 0 || board[nx][ny] == '0') continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }

    cout << dist[n-1][m-1];

    return 0;
}