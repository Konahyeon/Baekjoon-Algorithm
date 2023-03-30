#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void solve(int a, int b, int n) { //a에서 b로 n개 옮김
    if (n == 1) {
        cout << a << ' ' << b << '\n';
        return;
    }

    solve(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    solve(6-a-b, b, n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    //cout << (1<<n) - 1 << '\n'; -> Error! n 최댓값은 100. (2^100-1) > (2^31-1)이므로 표현 불가
    string num = to_string(pow(2, n));
    int dot_idx = num.find('.');
    num = num.substr(0, dot_idx); //substr(시작 위치, 문자열 길이)
    num[num.length()-1] -= 1;
    cout << num << '\n';
    
    if (n <= 20) {
        solve(1, 3, n);
    }

    return 0;
}