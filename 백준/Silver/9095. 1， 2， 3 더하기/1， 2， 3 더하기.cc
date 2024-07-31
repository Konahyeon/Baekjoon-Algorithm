#include <iostream>
using namespace std;
int D[12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    D[1] = 1, D[2] = 2, D[3] = 4;

    //D[1] ~ D[10] 까지 미리 다 구해놓기
    for (int i = 4; i < 11; i++) {
        D[i] = D[i-3] + D[i-2] + D[i-1];
    }

    while (t--) {
        int n;
        cin >> n;
        //n을 1, 2, 3 합으로 나타내는 방법 수
        cout << D[n] << '\n';
    }

    return 0;
}