#include <iostream>
using namespace std;

int pSum[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//배열 채우기
	int R, C, Q, element;
	cin >> R >> C >> Q;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> element;
			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + element;
		}
	}

	//구간합 구하기
	for (int i = 0; i < Q; i++) {
		int c1, r1, c2, r2;
		cin >> c1 >> r1 >> c2 >> r2;
		int sum = pSum[c2][r2] - pSum[c2][r1 - 1] - pSum[c1 - 1][r2] + pSum[c1 - 1][r1 - 1];
		cout << sum / ((c2 - c1 + 1) * (r2 - r1 + 1)) << "\n";
	}

	return 0;
}