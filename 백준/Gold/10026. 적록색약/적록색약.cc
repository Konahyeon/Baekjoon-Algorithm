#include <iostream>
#include <queue>
using namespace std;

char two[102][102];
char three[102][102];
bool vis_two[102][102];
bool vis_three[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == 'G') {
                two[i][j] = 'R'; //적록색약-> R=G
                three[i][j] = c;
            }
            else {
                two[i][j] = c;
                three[i][j] = c;
            }
        }
    }

    //적록색약 아닌 사람
    int three_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis_three[i][j] == true) continue; //이미 방문한 경우

            queue<pair<int, int>> q;
            q.push({i, j});
            vis_three[i][j] = true;
            three_cnt++;

            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis_three[nx][ny] == true || three[nx][ny] != three[cur.first][cur.second]) continue;

                    q.push({nx, ny});
                    vis_three[nx][ny] = true;
                }
            }
        }
    }

    //적록색약인 사람
    int two_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis_two[i][j] == true) continue; //이미 방문한 경우

            queue<pair<int, int>> q;
            q.push({i, j});
            vis_two[i][j] = true;
            two_cnt++;

            while (!q.empty()) {
                pair<int, int> cur = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis_two[nx][ny] == true || two[nx][ny] != two[cur.first][cur.second]) continue;

                    q.push({nx, ny});
                    vis_two[nx][ny] = true;
                }
            }
        }
    }
    
    cout << three_cnt << ' ' << two_cnt;

    return 0;
}