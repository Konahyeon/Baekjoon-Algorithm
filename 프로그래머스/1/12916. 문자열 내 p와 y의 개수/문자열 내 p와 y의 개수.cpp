#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_num = 0, y_num = 0;

    for (int i = 0; i < s.size(); i++) {
        char temp = s[i];
        
        if (temp == 'p' || temp == 'P') {
            p_num++;
        }
        else if (temp == 'y' || temp == 'Y') {
            y_num++;
        }
    }
    
    if (p_num != y_num) {
        answer = false;
    }

    return answer;
}