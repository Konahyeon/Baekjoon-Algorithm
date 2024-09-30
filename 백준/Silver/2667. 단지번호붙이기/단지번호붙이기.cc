#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string board[26];
bool visited[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> house_num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '1' && !visited[i][j]) { //bfs 시작
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                int answer = 0; //각 단지에 속하는 집의 수

                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    answer++;

                    for (int i = 0; i < 4; i++) {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] != '1' || visited[nx][ny]) continue;

                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
                //각 단지에 대한 bfs 끝!
                
                house_num.push_back(answer);
            }
        }
    }

    cout << house_num.size() << '\n'; //단지 개수

    sort(house_num.begin(), house_num.end()); //각 단지에 속하는 집의 수를 오름차순으로 정렬

    for (int i = 0; i < house_num.size(); i++) {
        cout << house_num[i] << '\n';
    }

    return 0;
}