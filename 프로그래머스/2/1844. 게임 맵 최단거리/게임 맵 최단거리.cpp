#include<vector>
#include<queue>
using namespace std;

int dist[101][101];
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!maps[nx][ny] || dist[nx][ny] > 0) continue;
            
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    
    if (dist[n-1][m-1] == 0) { //도달 방법 없는 경우
        answer = -1;
    }
    else {
        answer = dist[n-1][m-1];
    }
    
    return answer;
}