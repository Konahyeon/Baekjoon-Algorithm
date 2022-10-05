#include <iostream>
#include <algorithm>
using namespace std;

int lec_length[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, sum=0, start=-1, end=0, ans=-1; //N: 강의 수, M: 블루레이 수
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> lec_length[i];
		start = max(start, lec_length[i]);
		end += lec_length[i];
	}

	while (start <= end) {
		int acc = 0, cnt = 1;
		int mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			if (acc + lec_length[i] > mid) {
				cnt++;
				acc = 0;
			}
			acc += lec_length[i];
		}
		
		//개수 비교
		if (cnt > M)
			start = mid + 1;
		else {
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans << ' ';

	return 0;
}