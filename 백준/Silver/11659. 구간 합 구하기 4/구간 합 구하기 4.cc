#include <iostream>
using namespace std;

int pSum[100001];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		pSum[i + 1] = pSum[i] + A;
	}

	//합 구하기
	for (int s = 0; s < M; s++) {
		int i, j;
		cin >> i >> j;
		cout << pSum[j] - pSum[i - 1] << "\n";
	}

	return 0;
}