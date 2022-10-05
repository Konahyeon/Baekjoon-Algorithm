#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T, K;
	cin >> T;

	//i* (i + 1) / 2 <= 998
	vector<int> v;
	for (int i = 1; i <= 44; i++) {
		v.push_back(i*(i + 1) / 2);
	}

	for (int i = 0; i < T; i++) {
		int check = 0;
		cin >> K;
		//조합 찾기
		for (int p = 0; p < v.size(); p++) {
			for (int q = 0; q < v.size(); q++) {
				for (int r = 0; r < v.size(); r++) {
					if ((v[p] + v[q] + v[r]) == K) {
						check = 1;
					}
				}
			}
		}
		cout << check << '\n';
	}

	return 0;
}