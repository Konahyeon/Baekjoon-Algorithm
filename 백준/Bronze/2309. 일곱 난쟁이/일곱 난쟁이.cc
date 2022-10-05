#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int sum=0, arr[9], temp=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	//9명의 난쟁이 키의 총 합을 구한 후, 두 난쟁이의 키 합 빼보기!
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j)
				temp = arr[i] + arr[j];
			if (sum - temp == 100) {
				for (int k = 0; k < 9; k++) {
					if (arr[k] != arr[i] && arr[k] != arr[j])
						cout << arr[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}