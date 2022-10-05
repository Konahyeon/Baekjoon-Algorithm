#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N, M, arr[100], temp=0, sum=0;
	//int distance = 9999
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N-1; j++) {
			for (int k = j+1; k < N; k++) {
				temp = arr[i] + arr[j] + arr[k];

				if (temp <= M) {
					sum = max(sum, temp);
				}

				/*
				if (temp <= M && sum < temp)
					sum = temp;
				*/

				// M과 temp 차이값의 절댓값을 비교하여 '합이 최대한 가까운' 값 찾기
				/*
				if (temp <= M && distance > abs(M - temp)) {
					distance = abs(M - temp);
					sum = temp;
				}
				*/
			}
		}
	}
	cout << sum;

	return 0;
}