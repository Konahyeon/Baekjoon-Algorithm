#include <iostream>
#include <algorithm>
using namespace std;

int money[10000]; //개별 예산 요청액
int N, M;

bool valid(int mid) {
	int sum = 0;

	for (int i = 0; i < N; i++) { //총액 구하기
		sum += min(mid, money[i]);
		//sum += (mid < money[i]) ? mid : money[i];
	}
	return (sum <= M) ? true : false;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	cin >> M;

	//개별 요청액들의 합과 M 크기 비교
	int acc = 0;
	int maxval = -1;
	for (int i = 0; i < N; i++) {
		acc += money[i];
		maxval = max(maxval, money[i]);
	}

	if (acc <= M) { //개별 요청액들의 합이 M보다 작거나 같으면 가장 큰 원소가 최대 상한액이 됨
		cout << maxval << endl;
	}
	else { //이분탐색을 통해 최대 상한액 구함
		int mid, start = 0, end = 100000;
		int ans = -1;

		while (start <= end) {
			mid = (start + end) / 2;

			if (valid(mid)) {
				ans = mid;
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		cout << ans << '\n';
	}
	
	return 0;
}