#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[102][102];

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size(), m = maps[0].size();    
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;
    
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (maps[nx][ny] == 0 || dist[nx][ny] > 0) continue;
            
            q.push({nx, ny});
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
        }
    }
    
    if (dist[n-1][m-1] != 0) answer = dist[n-1][m-1];
    
    return answer;
}