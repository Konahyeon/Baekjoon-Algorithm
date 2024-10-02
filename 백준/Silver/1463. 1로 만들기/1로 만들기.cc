#include <iostream>
#include <algorithm>
using namespace std;

int D[1000002]; //i를 1로 만드는 최소 연산 횟수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    D[1] = 0, D[2] = 1, D[3] = 1;
    for (int i = 4; i <= n; i++) {
        D[i] = D[i-1] + 1; //Case 3. 1을 뺀다
        if (i % 3 == 0) { //Case 1. 3으로 나눈다
            D[i] = min(D[i], D[i/3] + 1);
        }
        if (i % 2 == 0) { //Case 2. 2로 나눈다
            D[i] = min(D[i], D[i/2] + 1);
        }
    }
    cout << D[n];

    return 0;
}