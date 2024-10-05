#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    while (!q.empty()) {
        for (int i = 1; i <= k; i++) {
            if (i == k) {
                cout << q.front();
                q.pop();
                if (!q.empty()) cout << ", ";
                break;
            }
            int front_num = q.front();
            q.push(front_num);
            q.pop();
        }
    }
    cout << ">";

    return 0;
}