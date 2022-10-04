#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];
int N; //배열에 들어갈 원소 개수

int binary_search(int target) {
	int start = 0;
	int end = N - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (target < A[mid])
			end = mid-1;
		else if (target > A[mid])
			start = mid+1;
		else //target = A[mid], 존재하는 경우
			return 1;
	}
	return 0; //존재하지 않는 경우
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M; //존재 여부 확인할 원소 개수
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N); //오름차순 정렬

	cin >> M;

	//있는지 확인
	while(M--) {
		int target; //찾으려는 원소
		cin >> target;
		cout << binary_search(target) << " \n";
	}

	return 0;
}