#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    
    int n=0, b=0;
    cin >> n;

    int a = n / 5;

    while(true) {
        if (a < 0) {
            cout << -1 << '\n';
            return 0;
        }
        if ((n-a*5) % 3 == 0) {
            b = (n-a*5) / 3;
            break;
        }
        a--;
    }
    cout << a + b << '\n';

}