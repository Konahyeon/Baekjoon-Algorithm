#include <string>
#include <vector>
#include "math.h"

using namespace std;

int solution(string s) {
    bool isMinus = false;
    int answer = 0;
    vector<int> v;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') continue;
        else if (s[i] == '-') {
            isMinus = true;
        }
        else {
            v.push_back(s[i] - '0');
        }
    }
    
    int cnt = 0;
    while (!v.empty()) {
        answer += v.back() * pow(10, cnt++);
        v.pop_back();
    }
    
    if (isMinus) {
        return answer * (-1);
    }
    
    return answer;
}