#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int arr[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int,int> m;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    for (int i = 0; i < N; i++) {
        //map에 arr[i]인 key가 있는 경우
        if (m.find(arr[i]) != m.end())
            continue;
        //map에 arr[i]인 key가 없는 경우
        m.insert({arr[i], i}); //m[arr[i]] = i 와 동일
    }

    for (int i = 0; i < M; i++) {
        int D;
        cin >> D;

        if (m.find(D) != m.end()) {
            cout << m.find(D)->second << '\n';
            continue;
        }
        cout << -1 << '\n';
    }

    return 0;
}