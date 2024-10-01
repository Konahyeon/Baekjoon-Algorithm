#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    answer = "fail";
    
    string id = id_pw[0];
    string pw = id_pw[1];
    
    for (int i = 0; i < db.size(); i++) {
        if (db[i][0] == id) {
            if (db[i][1] == pw) answer = "login";
            else answer = "wrong pw";
            break;
        }
    }
    
    return answer;
}