#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int result;
	cin >> a >> b >> c;

	if (a % b == 0)
	{
		cout << 0;
		return (0);
	}
	if (a > b)
		a %= b;
	for (int i = 0; i < c; i++)
	{
		a *= 10;
		result = (int)(a / b);
		a %= b;
	}
	cout << result;
	return (0);
}