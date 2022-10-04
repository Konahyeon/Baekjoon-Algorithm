//이분탐색

#include <iostream>
#include <algorithm>
using namespace std;

int A[100000], N;

bool valid(int target) {
	int start = 0, end = N-1, mid;

	while (start <= end) {
		mid = (start + end) / 2;
		if (target > A[mid])
			start = mid + 1;
		else if (target < A[mid])
			end = mid - 1;
		else
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N);

	int M, target;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		cout << valid(target) << '\n';
	}

	return 0;
}