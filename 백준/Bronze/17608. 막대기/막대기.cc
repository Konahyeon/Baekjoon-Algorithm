#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	int N, height;
	int count = 1;
	cin >> N; //막대기 수

	for (int i = 0; i < N; i++)
	{
		cin >> height; //막대 길이
		s.push(height);
	}

	int firstTop = s.top();
	s.pop();
	for (int i = 0; i < N-1; i++)
	{
		if (s.top() > firstTop)
		{
			count++;
			firstTop = s.top();
		}
		s.pop();
	}
	cout << count << endl;

	return 0;
}