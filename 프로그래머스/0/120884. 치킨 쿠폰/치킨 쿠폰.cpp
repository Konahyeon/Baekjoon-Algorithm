#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    
    int coupon = 0;
    while (chicken > 0) {
        coupon += chicken % 10; //안 쓴 쿠폰(1 + 8 + 0 + 1)
        answer += chicken/10; //쿠폰으로 시켜먹은 서비스 치킨 수(108 + 10 + 1)
        chicken /= 10;
        
        if (coupon >= 10) {
            answer += coupon/10;
            coupon += coupon/10;
            coupon %= 10;
        }
    }
    
    answer += coupon / 10;
    
    return answer;
}