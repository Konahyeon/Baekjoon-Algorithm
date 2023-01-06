#include <iostream>
#include <queue>
using namespace std;

int board[102][102];
int height_arr[102][102];
bool vis[102][102];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;


void make_board(int height) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (height >= height_arr[i][j])
                board[i][j] = 0;
            else
                board[i][j] = 1;
        }
    }
}
void make_vis() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            vis[i][j] = false;
    }
}
int bfs(int height) {
    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            num++;

            queue<pair<int, int>> Q;
            vis[i][j] = true;
            Q.push({i, j});

            while(!Q.empty()) {
                pair<int, int> cur = Q.front();
                Q.pop();
                
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (board[nx][ny] == 0 || vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int h_max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //높이 정보 입력
            cin >> height_arr[i][j];
            h_max = max(h_max, height_arr[i][j]);
        }
    }
    
    //비 양 정하기
    int height = h_max;
    int safe_max = 0;
    while(height >= 0) {
        make_board(height);
        make_vis();
        int num = bfs(height);
        safe_max = max(safe_max, num);
        height--;
    }
    cout << safe_max;

    return 0;
}