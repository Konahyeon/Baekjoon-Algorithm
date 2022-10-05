#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; //N의 최소 생성자 찾기! (N 자체는 분해합 결과임)
	cin >> s;

	int size = s.size(); //자릿수
	int N = std::stoi(s); //int로 타입 변환
	int start = N - (9 * size);
	int answer = 0;
	for (int i = start; i < N; i++) {
		int sum = i;
		int temp = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == N) {
			answer = i;
			break;
		}
	}
	cout << answer;
	return 0;
}