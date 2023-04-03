#include <iostream>
using namespace std;

int n;
int cnt;
bool isused1[30]; //열(column)에 대한 사용 유무 | (y)
bool isused2[30]; //왼쪽 하단에서 오른쪽 상단으로의 대각선에 대한 사용 유무 / (x+y)
bool isused3[30]; //왼쪽 상단에서 오른쪽 하단으로의 대각선에 대한 사용 유무 \ (x-y+n-1)


void func(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }

    //cur에 대해 (cur, 0), (cur, 1) ... (cur, i-1)까지 확인
    for (int i = 0; i < n; i++) {
        if (isused1[i] || isused2[cur+i] || isused3[cur-i+n-1]) continue; //하나라도 true인 경우 패스

        isused1[i] = 1;
        isused2[cur+i] = 1;
        isused3[cur-i+n-1] = 1;
        func(cur+1); //다음 행에 대해 분석
        isused1[i] = 0;
        isused2[cur+i] = 0;
        isused3[cur-i+n-1] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);

    cout << cnt;

    return 0;
}