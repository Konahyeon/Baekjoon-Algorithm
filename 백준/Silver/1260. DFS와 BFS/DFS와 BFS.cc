#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

vector<int> vec[1002];
bool visited[1002];
vector<int> dfs_ans;
vector<int> bfs_ans;


void dfs(int v) {
    visited[v] = true;
    dfs_ans.push_back(v);

    for (int i = 0; i < vec[v].size(); i++) {
        int nx = vec[v][i];
        if (visited[nx]) continue;
        dfs(nx);
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        bfs_ans.push_back(cur);

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

    int n, m, v;
    cin >> n >> m >> v;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) { //정점 번호는 1번부터 N번까지! (주의)
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(v);
    memset(visited, 0, sizeof(visited));
    bfs(v);

    for (int i = 0; i < dfs_ans.size(); i++) {
        cout << dfs_ans[i] << ' ';
    }
    cout << '\n';
    for(int i = 0; i < bfs_ans.size(); i++) {
        cout << bfs_ans[i] << ' ';
    }

    return 0;
}