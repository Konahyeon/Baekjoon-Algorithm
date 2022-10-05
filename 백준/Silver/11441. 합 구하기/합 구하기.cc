#include <iostream>
using namespace std;

int pSum[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int element;
		cin >> element;
		pSum[i + 1] = pSum[i] + element;
	}
	cin >> M;
	for (int s = 0; s < M; s++) {
		int i, j;
		cin >> i >> j;
		cout << pSum[j] - pSum[i - 1] << "\n";
	}

	return 0;
}