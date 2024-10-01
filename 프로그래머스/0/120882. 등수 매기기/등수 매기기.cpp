#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, int> m;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<int> v;
    vector<int> v_sort;
    
    for (int i = 0; i < score.size(); i++) {
        int avg = (score[i][0] + score[i][1]);
        v.push_back(avg);
        v_sort.push_back(avg);
    }
    sort(v_sort.rbegin(), v_sort.rend()); //내림차순
    
    int num = 1;
    for (int i = 0; i < v_sort.size(); i++) {
        if (m.find(v_sort[i]) == m.end()) m[v_sort[i]] = num; //key:value = 평균점수:등수, 동일 점수 없는 경우
        num++;
    }
    
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(m[v[i]]);
    }
    
    return answer;
}