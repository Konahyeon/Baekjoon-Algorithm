#include <iostream>
#include <list>
using namespace std;

int main() {
    string s;
    cin >> s;

    list<char> L;

    for (auto temp : s) {
        L.push_back(temp);
    }
    list<char>::iterator cur = L.end();

    int num;
    cin >> num;

    while (num--) {
        char c;
        cin >> c;

        if (c == 'L') {
            if (cur != L.begin()) {
                cur--;
            }
        }
        else if (c == 'D') {
            if (cur != L.end()) {
                cur++;
            }
        }
        else if (c == 'B') {
            if (cur != L.begin()) {
                cur--;
                cur = L.erase(cur); //삭제된 요소 다음 위치의 반복자 반환 대입 필요
            }
        }
        else { //c == 'P'
            char add;
            cin >> add;
            L.insert(cur, add);

        }
    }

    for (auto c : L) {
        cout << c;
    }

    return 0;
}