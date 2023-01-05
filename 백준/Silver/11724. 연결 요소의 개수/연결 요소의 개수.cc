#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int N, M, num = 0;
    vector<int> vec[1005];
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for (int i = 1; i <= N; i++) {
        if (check[i])
            continue;
        num++;
        queue<int> q;
        q.push(i);
        check[i] = true;
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto node : vec[front]) {
                if (check[node])
                    continue;
                q.push(node);
                check[node] = true;
            }
        }
    }

    cout << num;

    return 0;
}