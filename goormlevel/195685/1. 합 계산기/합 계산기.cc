#include <iostream>
using namespace std;
int main() {
	int t;
	int answer = 0;
	
	cin >> t;
	
	while (t--) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		
		if (c == '+') {
			answer += (a + b);
		}
		else if (c == '-') {
			answer += (a - b);
		}
		else if (c == '*') {
			answer += (a * b);
		}
		else if (c == '/') {
			answer += (a / b);
		}
	}
	
	cout << answer;
	
	return 0;
}