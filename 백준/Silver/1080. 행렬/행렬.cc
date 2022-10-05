#include <iostream>
using namespace std;

//matrix
char src[50][50], dst[50][50];

//focus : 왼쪽 상단
void reverse(int p, int q) {
	for (int i = p; i < p+3; i++) {
		for (int j = q; j < q+3; j++) {
			src[i][j] = (src[i][j] == '0') ? '1' : '0';
		}
	}
}

int main() {
	int N, M, cnt=0; //row, column, count
	cin >> N >> M;

	//src matrix
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> src[i][j];
		}
	}
	//dst matrix
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> dst[i][j];
		}
	}

	//check whether two arrs's element is equal or not and reverse
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			if (src[i][j] != dst[i][j]) {
				reverse(i, j);
				cnt++;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (src[i][j] != dst[i][j])
				flag = true;
		}
	}

	if (flag) cout << -1 << "\n";
	else cout << cnt << "\n";

	return 0;
}