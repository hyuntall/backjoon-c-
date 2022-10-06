#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define ii pair<int, int>

int main()
{
    int n, m;
    int a, b;
	int querie[100001];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &querie[i]);
    for (int i = 0; i < m; i++)
    {
        map<int, int, greater<int>> dict;
        scanf("%d %d", &a, &b);
        for (int i = a - 1; i < b; i++)
        {
            if (dict[querie[i]])
                dict[querie[i]] += 1;
            else
                dict[querie[i]] = 1;
            
        }
        vector<ii> vec(dict.begin(), dict.end());
        
        sort(vec.begin(), vec.end(), [](ii a, ii b){
            return a.second > b.second;
        });
        printf("%d", vec[0].first);
    }
}