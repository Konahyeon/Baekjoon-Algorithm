#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> vec[102];
bool visited[102];
int answer = 0;

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        answer++;

        for (int i = 0; i < vec[cur].size(); i++) {
            int nx = vec[cur][i];

            if (visited[nx]) continue;

            q.push(nx);
            visited[nx] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    bfs(1);

    cout << answer - 1;

    return 0;
}