#include <iostream>
using namespace std;

int func(int n, int r, int c) {
    if (n == 0) return 0;

    int half = 1<<n-1;
    if (r < half && c < half) return func(n-1, r, c); //1번
    if (r < half && c >= half) return half*half + func(n-1, r, c-half); //2번 (1번에서의 방문 횟수 고려해줘야 하므로 half*half 더함)
    if (r >= half && c < half) return 2*half*half + func(n-1, r-half, c); //3번
    return 3*half*half + func(n-1, r-half, c-half); //4번
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    cout << func(n, r, c);

    return 0;
}