#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    vector<int> n;
    vector<int> m;
    
    for (int i = 0; i < dots.size(); i++) {
        n.push_back(dots[i][0]);
        m.push_back(dots[i][1]);
    }
    
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());
    
    answer = (n[3] - n[0]) * (m[3] - m[0]);
    
    return answer;
}