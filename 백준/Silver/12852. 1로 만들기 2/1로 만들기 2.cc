#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int D[1000002]; //정수 k가 1이 되기까지 연산 최솟값
int pre[1000002]; //k가 정수 몇으로 가야 최적인지

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    D[1] = 0;
    pre[1] = 0;

    for (int i = 2; i <= n; i++) {
        D[i] = D[i-1] + 1;
        pre[i] = i-1;

        if ((i % 3 == 0) && (D[i/3] + 1 < D[i])) {
            D[i] = D[i/3] + 1;
            pre[i] = i/3;
        }
        if ((i % 2 == 0) && (D[i/2] + 1 < D[i])) {
            D[i] = D[i/2] + 1;
            pre[i] = i/2;
        }
    }
    
    //연산 최솟값
    cout << D[n] << '\n';

    //n을 1로 만드는 방법에 포함된 수
    int answer = n;
    while (true) {
        cout << answer << ' ';
        if (answer == 1) break;
        answer = pre[answer];
    }


    return 0;
}