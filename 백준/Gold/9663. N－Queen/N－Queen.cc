#include <iostream>
using namespace std;

int n, cnt;
bool isused1[40]; //열 |
bool isused2[40]; //우상향 /
bool isused3[40]; //우하향 \

void func(int k) {
    if (k == n) { //x축이 n-1인 곳까지 찾는 건데 n이니까 다 찾은 것이므로
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) { //(k, i)에 퀸 놓기
        if (isused1[i] || isused2[k+i] || isused3[k-i+n-1]) continue; //하나라도 사용중이면 안 됨

        isused1[i] = 1;
        isused2[k+i] = 1;
        isused3[k-i+n-1] = 1;
        func(k+1); //x축이 k+1인 퀸 찾으러 가기
        isused1[i] = 0;
        isused2[k+i] = 0;
        isused3[k-i+n-1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0); //x축이 0인 곳부터 퀸 놓을 위치 찾기
    cout << cnt;

    return 0;
}