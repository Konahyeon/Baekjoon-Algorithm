#include <iostream>
using namespace std;
int main()
{
	int num, x, y;
	int cnt = 0;
	int arr[100][100] = { 0 };
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				arr[x + j][y + k] = 1;
			}
			
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{

			if (arr[i][j] == 1)
			{
				cnt++;
			}
		}
		
	}
	cout << cnt;

	return 0;
}