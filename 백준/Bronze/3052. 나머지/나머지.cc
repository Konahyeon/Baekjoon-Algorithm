#include <iostream>
using namespace std;
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 10; i++)
	{
		arr[i] %= 42;
	}
	bool check[42] = { false };
	for (int i = 0; i < 10; i++)
	{
		check[arr[i]] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++)
	{
		if (check[i] == true)
		{
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}