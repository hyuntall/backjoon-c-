// SY 학교는 매일 최고의 학생을 선정한다.
// n일동안 최고의 학생 목록이 주어지면
// 학교는 S~E일 동안 가장 최고의 학생으로 선택된 빈도가 높은 학생이 누구인지 알고싶어한다.
// 학교는 그 학생에게 수상을 할 계획이다.
// n일 연속 및 해당 쿼리에 대해 최고의 학생 목록이 주어지면
// 해당 기간동안 가장 빈번히 선택될 최고의 학생을 찾는 프로그램을 작성한다.

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int	main()
{
	int n, m;
	int a, b;
	vector <pair <int, int> > queries;

	cin >> n >> m;
	int	days[n];
	for (int i = 0; i < n; i++)
		cin >> days[i];

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		queries.push_back(make_pair(a, b));
	}
	
	for (int i = 0; i < m; i++)
	{
		map <int, int> dict;
		
		for (int j = queries[i].first; j < queries[i].second; i++)
		{
			if (dict.find(days[j]) != dict.end())
				dict[days[j]] += 1;
			else
				dict[days[j]] = 1;
		}
		vector < pair <int, int> > result;
		for (int j = 0; j < dict.size(); i++)
		{
			result[j] = make_pair(dict[j].first, dict[j].second);
		}
	}
	return 0;
}