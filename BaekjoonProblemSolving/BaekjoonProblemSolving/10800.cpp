/*
https://www.acmicpc.net/problem/10800

&Title
10800번 - 컬러볼

&Question
지훈이가 최근에 즐기는 컴퓨터 게임이 있다. 이 게임은 
여러 플레이어가 참여하며, 각 플레이어는 특정한 색과 크기를 가진 
자기 공 하나를 조종하여 게임에 참여한다. 각 플레이어의 목표는 
자기 공보다 크기가 작고 색이 다른 공을 사로잡아 그 
공의 크기만큼의 점수를 얻는 것이다. 그리고 다른 공을 사로잡은 
이후에도 본인의 공의 색과 크기는 변하지 않는다. 다음 예제는 
네 개의 공이 있다. 편의상 색은 숫자로 표현한다.공 번호색크기11102315313448이 
경우, 2번 공은 다른 모든 공을 사로잡을 수 있다. 
반면, 1번 공은 크기가 더 큰 2번 공과 색이 
같은 3번 공은 잡을 수 없으며, 단지 4번 공만 
잡을 수 있다. 공들의 색과 크기가 주어졌을 때, 각 
플레이어가 사로잡을 수 있는 모든 공들의 크기의 합을 출력하는 
프로그램을 작성하시오. 

&Input
첫 줄에는 공의 개수를 나타내는 자연수 N이 주어진다(1 
≤ N ≤ 200,000). 다음 N개의 줄 중 i번째 
줄에는 i번째 공의 색을 나타내는 자연수 Ci와 그 크기를 
나타내는 자연수 Si가 주어진다(1 ≤ Ci ≤ N, 1 
≤ Si ≤ 2,000). 서로 같은 크기 혹은 같은 
색의 공들이 있을 수 있다. 

&Output
N개의 줄을 출력한다. N개의 줄 중 i번째 줄에는 
i번째 공을 가진 플레이어가 잡을 수 있는 모든 공들의 
크기 합을 출력한다. 

&Example
-input
4
1 10
3 15
1 3
4 8

-output
8
21
0
3

-input
3
2 3
2 5
2 4

-output
0
0
0


*/

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

bool compare(tuple<int, int, int> p1, tuple<int, int, int> p2) {
	if (get<2>(p1) == get<2>(p2)) return get<1>(p1) < get<1>(p2);
	else return get<2>(p1) < get<2>(p2);
}

bool compare2(tuple<int, int, int> p1, tuple<int, int, int> p2) {
	return get<0>(p1) < get<0>(p2);
}
int colors[200001] = {};

int main() {
	int N, color, sz;
	
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	vector<tuple<int, int, int>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> color >> sz;
		v[i] = { i, color, sz };
	}
	sort(v.begin(), v.end(), compare);
	int total = 0, prev_val = 0, prev_total = 0, duplication = 0, prev_duplcation = 0, prev_color = 0;


	for (int i = 0; i < N; i++) {
		int val = get<2>(v[i]);
		if (val == prev_val) {
			if (prev_color == get<1>(v[i])) prev_duplcation++;
			else {
				duplication += prev_duplcation + 1;
				prev_duplcation = 0;
			}
			get<2>(v[i]) = total - colors[get<1>(v[i])] - duplication * prev_val;			
		}
		else {
			prev_val = val;
			prev_duplcation = 0;
			duplication = 0;
			get<2>(v[i]) = total - colors[get<1>(v[i])];
			
		}
		total += val;
		colors[get<1>(v[i])] += val;
		prev_color = get<1>(v[i]);
	}
	sort(v.begin(), v.end(), compare2);
	for (int i = 0; i < N; i++) {
		cout << get<2>(v[i]) << "\n";
	}
	return 0;
}
*/

/*


c++
이렇게 간단히 풀수있는걸 개떡같이 풀어 자괴감이 들어...
```
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <memory>
#include <cstring>

using namespace std;

const int max_N = 200002;
int N;
vector<pair<int, int>> balls[2001]; //[size]{ind, color}
int ans[max_N], summ[max_N];

int main()
{
	scanf("%d ", &N);
	memset(summ, 0, sizeof(summ));
	int color, size;
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &color, &size);
		balls[size].push_back({ i, color });
	}
	int total = 0;
	for (int s = 1; s <= 2000; s++) {
		for (auto& item : balls[s]) {
			ans[item.first] = total - summ[item.second];
		}
		for (auto& item : balls[s]) {
			summ[item.second] += s;
			total += s;
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
```
*/