/*
https://www.acmicpc.net/problem/5567

&Title
5567번 - 결혼식

&Question
상근이는 자신의 결혼식에 학교 동기 중 자신의 친구와 
친구의 친구를 초대하기로 했다. 상근이의 동기는 모두 N명이고, 이 
학생들의 학번은 모두 1부터 N까지이다. 상근이의 학번은 1이다.상근이는 동기들의 
친구 관계를 모두 조사한 리스트를 가지고 있다. 이 리스트를 
바탕으로 결혼식에 초대할 사람의 수를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 상근이의 동기의 수 n (2 ≤ 
n ≤ 500)이 주어진다. 둘째 줄에는 리스트의 길이 m 
(1 ≤ m ≤ 10000)이 주어진다. 다음 줄부터 m개 
줄에는 친구 관계 ai bi가 주어진다. (1 ≤ ai 
< bi ≤ n) ai와 bi가 친구라는 뜻이며, bi와 
ai도 친구관계이다. 

&Output
첫째 줄에 상근이의 결혼식에 초대하는 동기의 수를 출력한다. 


&Example
-input
6
5
1 2
1 3
3 4
2 3
4 5

-output
3


*/

/*
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n; // 동기수 2~500
int m; // 리스트 길이 1~10000
vector<vector<int>> connected(501); // 친구관계

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> m;
	int a, b;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		connected[a].push_back(b);
		connected[b].push_back(a);
	}
	unordered_set<int> friends;
	for (int i = 0; i < connected[1].size(); ++i) {
		int f = connected[1][i];
		friends.insert(f);
		for (int j = 0; j < connected[f].size(); ++j)
			friends.insert(connected[f][j]);
	}
	friends.erase(1);
	cout << friends.size() << endl;

	return 0;
}
*/