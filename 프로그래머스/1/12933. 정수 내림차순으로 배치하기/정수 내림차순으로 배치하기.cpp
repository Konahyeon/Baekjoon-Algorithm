#include <string>
#include <vector>
#include <algorithm>
#include "math.h"

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while (n > 0) {
        int temp = n % 10;
        v.push_back(temp);
        n /= 10;
    }
    sort(v.rbegin(), v.rend());
    
    int cnt = 0;
    while (!v.empty()) {
        int temp = v.back();
        v.pop_back();
        answer += temp * pow(10, cnt++);
    }
    
    return answer;
}