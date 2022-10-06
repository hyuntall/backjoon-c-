#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, k;
    int cur, position;
    char j;
    map <int, string> map;
    cin >> n;
    for (int index = 0; index < n; index++)
    {
        cin >> i >> j >> k;
        if (j == 'R')
            map[i] = to_string(i+k);
        else
            map[i] = to_string(i-k);
    }
    cin >> cur;
    while (!map[cur].empty())
        cur = stoi(map[cur]);
    cout << cur;
}