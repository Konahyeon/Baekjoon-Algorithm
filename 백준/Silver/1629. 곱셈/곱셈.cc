#include <iostream>
using namespace std;

using ll = long long;
ll pow(ll a, ll b, ll m) {
    if (b == 1) return a % m; //base condition

    ll val = pow(a, b/2, m);
    val = val * val % m;
    
    if (b % 2 == 0) return val;
    else return val * a % m;
}

int main() {
    ll a, b, m;
    cin >> a >> b >> m;

    cout << pow(a, b, m);

    return 0;
}