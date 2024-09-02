#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    string temp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        else { //공백인 경우
            v.push_back(stoi(temp));
            temp = "";
        }
    }
    
    v.push_back(stoi(temp)); //s 문자열 내 마지막 숫자
    
    sort(v.begin(), v.end()); //sort
    
    string minVal = to_string(v.front());
    string maxVal = to_string(v.back());

    answer = minVal + " " + maxVal;
    
    return answer;
}