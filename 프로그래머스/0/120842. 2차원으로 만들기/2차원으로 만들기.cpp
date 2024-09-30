#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    int len = num_list.size();
    
    int idx = 0;
    for (int i = 0; i < len/n; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            v.push_back(num_list[idx++]);
        }
        answer.push_back(v);
    }
    
    return answer;
}