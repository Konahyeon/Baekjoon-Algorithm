#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	stack<string> s;
	string command;
	getline(cin, command);//고무오리 디버깅 시작
	cin.clear();
	while(1)
	{
		getline(cin, command);//고무오리 디버깅 시작
		
		if (command == "문제")
		{
			s.push("문제");
		}
		else if (command == "고무오리")
		{
			if (s.empty() == 1) //풀 문제가 없을 때 고무오리 사용시
			{
				s.push("문제");
				s.push("문제");
			}
			else s.pop();
		}
		else if (command == "고무오리 디버깅 끝")
		{
			if (s.empty() == 1)
			{
				cout << "고무오리야 사랑해" << endl;
			}
			else
			{
				cout << "힝구" << endl;
			}
			break;
		}
		cin.clear();
	}

	return 0;
}