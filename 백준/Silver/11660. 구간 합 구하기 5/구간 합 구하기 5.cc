#include <iostream>
using namespace std;

int pSum[1025][1025];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//배열 채우기
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int element;
			cin >> element;
			pSum[i + 1][j + 1] = pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j] + element;
		}
	}

	//구간 합 구하기
	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << pSum[x2][y2] - pSum[x2][y1 - 1] - pSum[x1 - 1][y2] + pSum[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}