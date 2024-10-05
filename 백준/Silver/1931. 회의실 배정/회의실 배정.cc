#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> p[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }

    sort(p, p+n);

    int answer = 1;
    int start_time = p[0].second;
    int end_time = p[0].first;
    for (int i = 1; i < n; i++) {
        if (p[i].second >= end_time) { //end_time보다 시작 시간이 크거나 같으면
            answer++;
            start_time = p[i].second;
            end_time = p[i].first;
        }
    }

    cout << answer;


    return 0;
}