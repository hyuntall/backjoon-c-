#include <iostream>
#include <algorithm>
using namespace std;

int	main()
{
	int n, i;
	cin >> n;
	int arr[n];
	while (i < n)
	{
		cin >> arr[i];
		sort(arr, arr + i + 1, less<int>());
		cout << arr[i++ / 2];
	}
}