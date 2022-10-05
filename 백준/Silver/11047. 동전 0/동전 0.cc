//Another Code

#include <iostream>
using namespace std;

int main() {
	int N, K, arr[10], cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		cnt += K / arr[i]; //cnt : 필요한 동전 개수
		K = K % arr[i]; //K : 잔액
	}

	cout << cnt;

	return 0;
}