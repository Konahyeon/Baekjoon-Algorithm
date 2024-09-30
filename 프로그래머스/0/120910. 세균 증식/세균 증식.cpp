#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = 0;
    answer = n;
    
    for (int i = 1; i <= t; i++) {
        answer *= 2;
    }
    
    return answer;
}