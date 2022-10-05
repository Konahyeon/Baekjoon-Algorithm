#include <iostream>
using namespace std;
int main()
{
	int count = 0;
	int sum, sum_right, N, N_left, N_right, n;
	int new_N = -1234;
	cin >> N;
	n = N;
	while (new_N != n)
	{
		//N의 각 자릿수 구하기
		N_left = N / 10;
		N_right = N % 10;
		//N의 각 자릿수 더한 결과값을 sum에 담기
		sum = N_left + N_right;
		//sum의 각 자릿수 구하기
		sum_right = sum % 10;
		new_N = N_right*10 + sum_right;
		count++;
		if (new_N == n) //N은 42, new_N은 26. while 이전에 입력받은 N값과 비교해야함
		{
			break;
		}
		else
		{
			N = new_N;
		}
	}
	cout << count;
	return 0;
}