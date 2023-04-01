#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int isused[10002];
vector<int> v;

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        if (!isused[v[i]]) {
            arr[k] = v[i];
            isused[v[i]] = 1;
            func(k+1);
            isused[v[i]] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    func(0);

    return 0;
}