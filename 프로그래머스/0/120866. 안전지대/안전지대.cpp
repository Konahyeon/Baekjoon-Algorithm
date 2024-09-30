#include <string>
#include <vector>
#include <queue>

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
bool visit[102][102];

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                visit[i][j] = true;
                
                for (int idx = 0; idx < 8; idx++) {
                    int nx = i + dx[idx];
                    int ny = j + dy[idx];
                    
                    if (nx < 0 || nx >=n || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == 1 || visit[nx][ny]) continue;
                    
                    visit[nx][ny] = true;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j]) answer++;
        }
    }
    
    return answer;
}