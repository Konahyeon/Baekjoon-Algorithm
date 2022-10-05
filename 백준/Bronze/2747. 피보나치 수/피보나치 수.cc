#include <iostream>
using namespace std;

int arr[46];

int fib(int n)
{
	if (n == 0 || n == 1)
	{
		//arr[n] = n;
		return n;
	}
	else if(arr[n] == 0)
	{
		arr[n] = fib(n - 1) + fib(n - 2);
		return arr[n];
	}
	else
	{
		return arr[n];
	}
} 

int main()
{
	int n;
	cin >> n;
	cout << fib(n);
}