#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        map<string, int> m; //{name : kind}

        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;
            if (m.find(kind) != m.end()) {//있는 경우
                m[kind]++;
            }
            else {
                m[kind] = 1;
            }
        }

        int ret = 1;
        for (auto iter : m) {
            int temp = iter.second;
            ret *= temp + 1;
        }
        cout << ret-1 << '\n';
    }

    return 0;
}