#include <iostream>
using namespace std;
int arr[99 * 99+5];
int main()
{
	int T, H, W, N; //T: 테스트 데이터 횟수, H: 호텔 층수, W: 각 층 방 수, N: 손님 번호
	cin >> T;
	for (int test = 0; test < T; test++)
	{
		cin >> H >> W >> N;
		int num = 0;
		for (int i = 1; i <= W; i++) //방 번호
		{
			for (int j = 1; j <= H; j++) //층수
			{
				arr[num] = 100 * j + i;
				if (num >= N - 1)
				{
					num++;
					break;
				}
				num++;
			}
			if (num >= N)
			{
				break;
			}
		}
		cout << arr[N-1] << "\n";
	}
	return 0;
}