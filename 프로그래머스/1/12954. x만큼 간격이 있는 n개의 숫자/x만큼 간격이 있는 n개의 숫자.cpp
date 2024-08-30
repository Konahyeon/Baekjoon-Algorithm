#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int temp = x;
    answer.push_back(x);
    
    while (--n) {
        temp += x;
        answer.push_back(temp);
    }
    
    return answer;
}