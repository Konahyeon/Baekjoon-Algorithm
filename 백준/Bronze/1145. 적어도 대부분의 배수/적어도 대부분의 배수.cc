#include <iostream>
#include <algorithm>
using namespace std;

//최대공약수
int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

//최소공배수
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int arr[5], temp, answer = 2e9;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 4; j++) {
			for (int k = j+1; k < 5; k++) {
				temp = lcm(lcm(arr[i], arr[j]), arr[k]); //세 수의 최소공배수
				answer = min(temp, answer);
			}

		}
	}

	cout << answer;

	return 0;
}