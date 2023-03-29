#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int cnt;

int hanoi(int a, int b, int n) {
    if (n == 1) {
        q.push({a, b});
        cnt++;
        return 0;
    }
    
    hanoi(a, 6-a-b, n-1);
    q.push({a, b});
    cnt++;
    hanoi(6-a-b, b, n-1);

    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin >> n;

    hanoi(1, 3, n);

    cout << cnt << '\n';
    while (!q.empty()) {
        cout << q.front().first << ' ' << q.front().second << '\n';
        q.pop();
    }

    return 0;
}