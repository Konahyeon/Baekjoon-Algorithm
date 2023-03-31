#include <iostream>
using namespace std;

int n, m;
int arr[10]; //수열 각 원소 담을 array (idx 0부터 사용)
int isused[10]; //해당 수가 수열에 사용 되었는지 유무 기록 (idx 1부터 사용)

void func(int k) { //그 시점까지 채워진 원소 개수
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = 1;
            func(k+1); //다음 수 정하기 위해 한 단계 더 들어감
            isused[i] = 0; //k번째 수를 i로 둔 모든 수열 확인 됐으므로 false로 둠
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