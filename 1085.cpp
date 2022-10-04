#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int x, y, w, h;
	int lf, ur;
	cin >> x >> y >> w >> h;
	lf = min(x, y);
	ur = min(w-x, h-y);
	cout << min(lf, ur);
}
