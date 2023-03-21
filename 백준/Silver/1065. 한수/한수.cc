#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int x;
    cin >> x;

    if (x <= 99) {
        cout << x;
        return 0;
    }
    
    int cnt=0;
    for (int i = 100; i <= x; i++) {
        if (i == 1000) {
            break; //어차피 한수 아님
        }

        int temp = i;
        int first = temp % 10;
        temp /= 10;
        int second = temp % 10;
        temp /= 10;
        int third = temp % 10;

        if (first-second == second-third) {
            cnt++;
        }
    }

    cout << 99 + cnt;

    return 0;
}