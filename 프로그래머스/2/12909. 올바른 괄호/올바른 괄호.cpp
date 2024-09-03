#include<string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> v;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') {
            if (!v.empty()) {
                v.pop_back();
            }
            else { //v.empty == true
                answer = false;
            }
        }
        else { //"(" 인 경우
            v.push_back('(');
        }
    }
    
    if (!v.empty()) {
        answer = false;
    }

    return answer;
}