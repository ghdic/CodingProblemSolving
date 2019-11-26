/*
https://www.acmicpc.net/problem/2989

&Title
2989번 - 개구리 왕눈이스페셜 저지

&Question
개구리 왕눈이는 N개의 연꽃잎이 있는 연못에 살고 있다. 
연꽃잎은 1부터 N까지 차례대로 번호가 매겨져 있다. 연못을 위에서 
봤을 때 2차원 평면에 연꽃잎이 (x,y) 좌표에 떠 있는 
것 처럼 보인다. 왕눈이는 대각선으로 뛰는 것과 음의 방향으로 
뛰는 것을 무서워 한다. 좀 더 자세히 말하자면 (x 
1,y1)에서 (x2,y2)로 뛰기 위해서는 아래 두 조건 중 하나를 
만족해야한다.x2 > x1 이고 y2 = y1y2 > y1 
이고 x2 = x1각 연꽃잎 마다 일정 수의 파리가 
있고, 왕눈이는 파리를 먹으며 힘을 회복한다.왕눈이가 한 번 연꽃잎을 
이동하기 위해서는 K 만큼 힘이 든다. 왕눈이는 처음 1번 
연꽃잎에서 시작하여 N번 연꽃잎으로 이동하려고 한다. 다만, 도착하고 난 
뒤 힘의 최대이고 싶어한다. 처음 왕눈이가 가진 힘은 0 
이다. 힘은 항상 0 이상 이어야 한다.왕눈이를 도와 연꽃잎 
사이를 이동하는 경로를 출력하는 프로그램을 작성하시오. 

&Input
첫 줄에 연꽃잎의 수 N과 한 번 이동하는데 
필요한 힘 K가 주어진다. (2 ≤ N ≤ 300 
000, 1 ≤ K ≤ 1000)다음 N개의 줄에 걸쳐 
각 연꽃잎의 좌표 X, Y와 파리의 양 F가 차례대로 
주어진다. i+1번째 줄에 주어지는 좌표와 파리의 양은 i번 연꽃잎에 
관한 정보이다. 연꽃잎의 좌표는 서로 다르다. (0 ≤ X, 
Y ≤ 100 000, 0 ≤ F ≤ 1000)입력은 
항상 답이 존재하도록 주어진다. 

&Output
첫 줄에 N번 연꽃잎에 도착 한 뒤 최대 
힘의 양을 출력한다.두 번째 줄에는 1번 연꽃잎과 N번 연꽃잎을 
포함하여 방문한 연꽃잎의 수 L을 출력한다.다음 L개의 줄에 방문한 
연꽃잎의 좌표들을 차례대로 출력한다.만약, 가능한 답이 여러 가지인 경우 
그 중 아무거나 하나 출력한다. 

&Example
-input
6 5
1 1 5
2 1 5
1 2 4
2 3 5
3 2 30
3 3 5

-output
5
4
1 1
2 1
2 3
3 3


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

struct pos {
	int y, x;
};

pos start, finish;

struct lotus {
	int y, x, fly;
	bool operator < (lotus& a) {
		return (this->y + this->x < a.y + a.x);
	}
};

int n, k, index;
int max_x[MAX + 1], max_y[MAX + 1];
vector<lotus> v;
int dp[300001];
int path[300001];

void print(int idx, int cnt) { // path을 통해 개수와 경로를 출력해줌
	if (idx == index) {
		cout << cnt << "\n";
		cout << v[idx].x << " " << v[idx].y << "\n";
		return;
	}
	else {
		print(path[idx], cnt + 1);
		cout << v[idx].x << " " << v[idx].y << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	v.reserve(n + 1);
	int a, b, f;
	v.push_back({ 0, 0, 0 }); // dp를 위해 덤프 하나 넣어줌
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> f;
		v.push_back({ b, a, f });
	}
	start = { v[1].y, v[1].x }, finish = { v[n].y, v[n].x };
	sort(v.begin(), v.end());

	// dp 초기세팅 처음 start값 넣어줌
	dp[0] = -1e9;
	int i = 0;
	while (v[i].y != start.y || v[i].x != start.x)++i;
	dp[i] = v[i].fly;
	max_y[v[i].y] = max_x[v[i].x] = i;
	index = i;
	++i;
	for (; i <= n; ++i) {
		dp[i] = -1;

		int& y = max_y[v[i].y];
		int& x = max_x[v[i].x];

		if (dp[y] >= k && dp[i] < dp[y] + v[i].fly - k) {
			dp[i] = dp[y] + v[i].fly - k;
			
			path[i] = y;
		}
		if (dp[x] >= k && dp[i] < dp[x] + v[i].fly - k) {
			dp[i] = dp[x] + v[i].fly - k;
			
			path[i] = x;
		}
		if (dp[i] > dp[y])y = i;
		if (dp[i] > dp[x])x = i;
		if (v[i].y == finish.y && v[i].x == finish.x)break;
	}
	cout << dp[i] << "\n";
	print(i, 1);
	return 0;
}
*/


/*
// 메모리 초과
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;

struct pos {
	int y, x;
};

pos start, finish;

struct lotus {
	int y, x, fly;
	bool operator < (lotus& a) {
		return (this->y + this->x < a.y + a.x);
	}
};
struct answer {
	vector<pos> v;
	int power = 0;
};

int n, k;
int max_x[MAX + 1], max_y[MAX + 1];
vector<lotus> v;
vector<answer> dp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	dp.reserve(n);
	int x, y, f;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y >> f;
		v.push_back({ y, x, f });
	}
	start = { v[0].y, v[0].x }, finish = { v[n - 1].y, v[n - 1].x };
	sort(v.begin(), v.end());

	// dp 초기세팅 처음 start값 넣어줌
	int i = 0;
	while (v[i].y != start.y || v[i].x != start.x)++i;
	answer ans;
	ans.power = v[i].fly;
	ans.v.push_back({ v[i].y, v[i].x });
	dp.push_back(ans);
	++i;
	for (; i < n; ++i) {
		int index = -1, maximum = -1;
		for (int j = 0; j < dp.size(); ++j) {
			pos p = dp[j].v[dp[j].v.size() - 1];
			// 이전값들중 y축이 같은것들
			if (v[i].y == p.y && v[i].x > p.x) {
				if (dp[j].power - k > maximum) {
					index = j;
					maximum = dp[j].power - k;
				}
			}

			// 이전값들중 x축이 같은 것들
			if (v[i].x == p.x && v[i].y > p.y) {
				if (dp[j].power - k > maximum) {
					index = j;
					maximum = dp[j].power - k;
				}
			}
		}
		
		// dp를 통해 찾은 최대값을 넣어줌
		if (index != -1) {
			ans.v = dp[index].v;
			ans.v.push_back({ v[i].y, v[i].x });
			ans.power = maximum + v[i].fly;
			dp.push_back(ans);
			if (v[i].y == finish.y && v[i].x == finish.x)break;
		}
	}
	ans = dp[dp.size() - 1];
	cout << ans.power << "\n";
	cout << ans.v.size() << "\n";
	for (int i = 0; i < ans.v.size(); ++i)
		cout << ans.v[i].x << " " << ans.v[i].y << "\n";
	return 0;
}
*/