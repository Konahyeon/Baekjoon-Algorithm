#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, start, end, pre_start, pre_end, cnt=1;
	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
	cin >> start >> end;
		v.push_back({ end, start }); //pair의 sort는 first, second 순이기에 순서 바꿈
	}
	sort(v.begin(), v.end()); //일찍 끝나는 순서대로 정렬

	pre_end = v[0].first; //이전 회의 끝나는 시간
	pre_start = v[0].second; //이전 회의 시작 시간 
	for (int i = 1; i < N; i++) {
		if (pre_end <= v[i].second) { //이전 회의 끝나는 시간보다 v[i]의 회의 시작 시간이 크면
			pre_start = v[i].second;
			pre_end = v[i].first;
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}