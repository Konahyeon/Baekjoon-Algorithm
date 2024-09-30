#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    int n = board[0] / 2; // 가로 : -n ~ n
    int m = board[1] / 2; // 세로 : -m ~ m
    
    int x = 0, y = 0;
    
    for (int i = 0; i < keyinput.size(); i++) {
        if (keyinput[i] == "left") {
            if (x - 1 >= n * (-1)) x -= 1;
        }
        else if (keyinput[i] == "right") {
            if (x + 1 <= n) x += 1;
        }
        else if (keyinput[i] == "down") {
            if (y - 1 >= m * (-1)) y -= 1;
        }
        else if (keyinput[i] == "up") {
            if (y + 1 <= m) y += 1;
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}