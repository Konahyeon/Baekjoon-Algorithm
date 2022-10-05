#include <iostream>
using namespace std;

int main() {
	int L, P, V; //L: 사용 가능한 날, P: 연속 제한 일, V: 강산's 휴가일
	int cnt = 1;
	while (true) {
		int result = 0;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)
			break;
		result = (V / P) * L + (V % P > L ? L : V % P); //TRUE인 경우 : P=8, L=2, V=19 (예외 주의!)
		cout << "Case " << cnt++ << ": " << result << '\n';
	}

	return 0;
}