#include <iostream>
#include <algorithm>
using namespace std;
int table[1000002]; //n이 1이 될 수 있는 데 필요한 연산 횟수 최소값

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    table[1] = 0;
    
    for (int i = 2; i <= n; i++) {
        //연산: 1을 뺀다
        table[i] = table[i-1] + 1;

        //연산: 3으로 나누어 떨어지면, 3으로 나눈다
        if (i % 3 == 0) {
            table[i] = min(table[i/3] + 1, table[i]);
        }

        //연산: 2로 나누어 떨어지면, 2로 나눈다
        if (i % 2 == 0) {
            table[i] = min(table[i/2] + 1, table[i]);
        }
    }

    cout << table[n];

    return 0;
}