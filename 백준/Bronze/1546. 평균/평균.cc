#include <iostream>
using namespace std;
int main()
{
	int N;
	int M = -1;
	cin >> N;
	double* score = new double[N];
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];
		if (M < score[i])
		{
			M = score[i];
		}
	}
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		score[i] = score[i] / M * 100;
		sum += score[i];
	}
	cout << sum / N << endl;

	return 0;
}