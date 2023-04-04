#include <iostream>
using namespace std;

int n, s, cnt=0;
int arr[25];

void func(int cur, int tot) {
    if (cur == n) {
        if (tot == s) cnt++;
        return;
    }

    func(cur+1, tot); //안 더하는 거
    func(cur+1, tot+arr[cur]); //더하는 거
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    func(0, 0);

    if (s == 0) cnt--; //부분수열의 크기가 양수여야 하기에 공집합인 경우를 제거
    cout << cnt;

    return 0;
}