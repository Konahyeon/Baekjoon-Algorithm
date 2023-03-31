#include <iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++) { //각 상태마다 사용
        if (!isused[i]) {
            if (k > 0 && arr[k-1] > i) continue;
            arr[k] = i; //arr[k]를 해당 수열에서 사용하고 있지 않는 i로 초기화
            isused[i] = 1;
            func(k+1); //이 시점에서의 arr[k+1]에 들어올 수 있는 원소 찾으러 들어감
            isused[i] = 0; //i로 볼 건 다 봤으니 뒤에서 사용할 수 있게 false로 둠
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    func(0);

    return 0;
}