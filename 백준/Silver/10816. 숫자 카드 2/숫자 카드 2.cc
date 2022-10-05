#include <iostream>
using namespace std;

int cnt[20000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	int M, N, num, check;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		cnt[num + 10000000]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> check;
		cout << cnt[check + 10000000] << ' ';
	}

	return 0;
}