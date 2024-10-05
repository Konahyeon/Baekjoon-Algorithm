#include <iostream>
using namespace std;

int memo[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    memo[0] = 1;
    memo[1] = 2;
    for (int i = 2; i < n; i++) {
        memo[i] = (memo[i - 2] + memo[i - 1]) % 10007;
    }
    cout << memo[n - 1];

    return 0;
}