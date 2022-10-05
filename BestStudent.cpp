// SY 학교는 매일 최고의 학생을 선정한다.
// n일동안 최고의 학생 목록이 주어지면
// 학교는 S~E일 동안 가장 최고의 학생으로 선택된 빈도가 높은 학생이 누구인지 알고싶어한다.
// 학교는 그 학생에게 수상을 할 계획이다.
// n일 연속 및 해당 쿼리에 대해 최고의 학생 목록이 주어지면
// 해당 기간동안 가장 빈번히 선택될 최고의 학생을 찾는 프로그램을 작성한다.
// 첫 줄에 표준 입력으로 일 수 n과, 학생의 수 m이 주어지고,
// 둘째 줄에 일별로 우수한 학생의 번호를 기록한 수들의 쿼리가 주어진다.
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#define pp pair<int, int>

using namespace std;

bool cmp(const pp& a, const pp& b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

int	main()
{
	int n, m;
	int a, b;
	int querie[1000001];
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> querie[i];
	for (int i = 0; i < m; i++)
	{
		map<int, int> dict;
		cin >> a >> b;
		for (int i = a-1; i < b; i++)
		{
			if (dict[querie[i]])
				dict[querie[i]] += 1;
			else
				dict[querie[i]] = 1;
			cout << querie[i]<< "값" << dict[querie[i]] << "\n";
		}
		vector<pp> vec(dict.begin(), dict.end());
		sort(vec.begin(), vec.end(), [](pp a, pp b){
			return a.second > b.second;
		});
		cout << vec[0].first;
	}
}