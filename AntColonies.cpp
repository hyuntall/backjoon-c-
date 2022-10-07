/*
과학자들은 여러 개미 군락이 사는 둥지를 분석했다.
개미 둥지는 각 노드가 개미 군집이 사는 물리적 장소를 나타내는 나무 구조이고,
각 가장자리는 두 개미 군집을 연결하는 터널을 나타내는 것을 발견했다.
가장 흥미로운 것은 각 군락지가 정확히 하나의 색을 가지고 있고 그것은 때때로 그것의 색을 바꾼다는 것이다.
색 변화 메커니즘은 주어진 두 군락 A와 B 사이의 경로에 있는 군락들 중 특정 색 C를 가진 가장 가까운 한 쌍의 군락에 의존한다.
두 군락 사이의 거리는 이들을 연결하는 경로의 터널 수
즉 트리 구조에서 두 개의 해당 노드를 연결하는 경로의 가장자리 수이다.
예를 들어, 그림 A.1 (a)은 콜로니 1부터 콜로니 5까지 각각 콜로니 1부터 콜로니 5까지 각각 콜로니 위에
주황색으로 표시된 색상 1, 2, 2, 2, 2, 2, 1의 1~5번으로 번호가 매겨진 5개의 개미 콜로니를 가진 나무 구조를 보여준다.
컬러 2와 2개의 콜로니 2와 5의 경우, 콜로니 2와 콜로니 5 사이의 경로에 컬러 2가 있는 가장 가까운 콜로니 쌍(콜로니 2, 콜로니 3)이다.
그러나 콜로니 2와 콜로니 4의 경우, 색상이 2인 가장 가까운 쌍이 쌍이다.(콜로니 3, 콜로니 4).
그림 A.1 (b)와 같이 콜로니 3의 현재 색상 2가 색상 3으로 변경된다고 가정하자.
그러면 콜로니 2와 콜로니 5 사이의 경로에는 오직 하나의 콜로니만이 2를 가지고 있기 때문이다.
콜로니 2와 콜로니 4의 색상 2를 가진 가장 가까운 쌍은 (콜로니 2, 콜로니 4)가 된다.
개미 군락의 색상, 개미 둥지의 트리 구조, 색상 변경을 위한 업데이트 명령의 정렬된 목록과
가장 가까운 쌍에 대한 쿼리 명령이 주어지면 색상이 있는 가장 가까운 군체 쌍을 찾는 프로그램을 작성하십시오.

첫줄에 개미 군락의 수 n과 업데이트 명령 쿼리의 수 q가 주어진다.
두번째 줄은 개미 군락의 색상을 나타내는 정수의 쿼리가 주어진다.
다음 줄부터 n-1번 동안 한 줄씩 개미 둥지의 트리 관계가 주어진다.
다음 줄 부터 q번 동안 한 줄씩 명령, 트리 관계, 색상을 입력 받는다. (Q, A, B, c) or (U, A, c);
명령어가 U면 둥지의 현재 색상을 업데이트 하는 것이고, Q면 가장 가까운 둥지 쌍의 거리를 색으로 출력하는 것이다.
*/ 
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int colors[100001];
map < int, vector<int> > colonies;
char S;
int minLen = 100001;
int	dfs(int A, int B, int len, int count, int target, bool *visited)
{
	visited[A] = true;
	cout << A <<"아오 <<" << colors[A] << ":"<<target << "\n";
	if (colors[A] == target)
	{
		count += 1;
		if (count > 1)
		{
			minLen = min(minLen, len);
			len = 0;
			count = 1;
		}
	}
	cout << A << " : " << colonies[A].size() << "/ count: "<< count << "/ len: " << minLen <<"\n";
	if (A == B)
	{
		if (count > 1)
			return (minLen);
		minLen = 1000001;
		return (-1);
	}
	for (int i = 0; i < colonies[A].size(); i++)
	{
		int y = colonies[A][i];
		if (!visited[y])
			return dfs(y, B, len + 1, count, target, visited);
	}
}

int main()
{
	int n, q, A, B, c;
	int tmp1, tmp2;
	cin >> n >> q;
	for (int i = 1; i < n + 1; i++)
		cin >> colors[i];
	for (int i = 0; i < n - 1; i++)
	{
		cin >> tmp1 >> tmp2;
		colonies[tmp1].push_back(tmp2);
		colonies[tmp2].push_back(tmp1);
	}
	for (int i = 0; i < q; i++)
	{
		cin >> S;
		if (S == 'Q')
		{
			cin >> A >> B >> c;
			int cur = A;
			bool visited[100001] = {false};
			int len1 = dfs(A, B, 0, 0, c, visited);
			minLen = 100001;
			cout << len1;
		}
		else
		{
			cin >> A >> c;
			cout << colors[A] << "\n";
			colors[A] = c;
			cout << colors[A] << "\n";
		}
	}
}