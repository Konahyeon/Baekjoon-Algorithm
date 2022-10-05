#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, P, sum=0;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		cin >> P;
		vec.push_back(P);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += vec[j];
		}
	}

	cout << sum << "\n";

	return 0;
}