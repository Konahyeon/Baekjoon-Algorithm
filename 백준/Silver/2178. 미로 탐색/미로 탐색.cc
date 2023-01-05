#include <iostream>
#include <queue>
using namespace std;

string board[102];
int dist[102][102];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;
        board[i] = ' ' + temp;
    }
    
    //bfs
    queue<pair<int, int>> q;
    dist[1][1] = 1; //visit와 동일한 역할
    q.push({1, 1});

    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (dist[nx][ny] > 0 || board[nx][ny] == '0') continue; //이미 방문한 곳
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[N][M];

    return 0;
}