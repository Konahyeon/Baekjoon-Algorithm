#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    
    cin >> T;
    while (T--) {
    int N, size=0;
    long long answer=0;

    cin >> N;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        pq.push(num);
        size++;
    }
    
    while (size != 1) {
        long long temp = 0;
        temp += pq.top();
        pq.pop();
        size--;
        temp += pq.top();
        pq.pop();
        size--;

        pq.push(temp);
        size++;

        answer += temp;
    }

    cout << answer << '\n';
    }

    return 0;
}