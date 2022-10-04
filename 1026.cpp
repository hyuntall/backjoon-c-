#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int	main()
{
	int n;
	int tmp;
	int result = 0;

	vector<int> A;
	vector<int> B;
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		result += A[i] * B[i];
	}
	cout << result;
}