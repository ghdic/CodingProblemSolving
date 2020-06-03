// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo&categoryId=AWXRFInKex8DFAUo&categoryType=CODE

/*
2차원 평면상에 상하좌우 움직일수 있는 원자
1초에 1만큼 거리를 이동(서로 마주보는 방향으로 올경우 0.5초도 고려)
두개이상의 원자가 동시에 충돌시, 충돌한 모든 원자는 보유한 에너지 방출하고 소멸
원자들이 소멸되면서 방출하는 에너지의 총합을 구하라
*/

// 시간초과
/*
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

struct element {
	int x, y, d, k;
};
int n;
element e[1000];
bool extinct[1000];
const int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };


void init() {
	fill(extinct, extinct + 1000, false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e[i].x >> e[i].y >> e[i].d >> e[i].k;
		e[i].x = e[i].x*2 + 2000;
		e[i].y = e[i].y*2 + 2000;
	}
}

int move() {
	int sum = 0;
	unordered_map<int, vector<int>> dict;
	for (int i = 0; i < n; i++) {
		if (!extinct[i]) {
			e[i].x += dx[e[i].d], e[i].y += dy[e[i].d];
			if (e[i].y < 0 || e[i].y > 4000 || e[i].x < 0 || e[i].x > 4000) {
				extinct[i] = true;
				continue;
			}
			dict[e[i].x * 4000 + e[i].y].push_back(i);
		}
	}

	for (auto v : dict){
		if (v.second.size() > 1) {
			for (int m : v.second) {
				extinct[m] = true;
				sum += e[m].k;
			}
		}

	}
	return sum;
}

int run() {
	int res = 0;
	init();
	for (int i = 0; i < 2000; ++i)
		res += move();
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "#" << t << " " << run() << "\n";
	}
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
using namespace std;

struct element {
	int x, y, d, k;
};
int n, map[4001][4001];
vector<element> e;
const int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };


void init() {
	cin >> n;
	e.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> e[i].x >> e[i].y >> e[i].d >> e[i].k;
		e[i].x = e[i].x * 2 + 2000;
		e[i].y = e[i].y * 2 + 2000;
	}
}

int solve() {
	int ans = 0;
	while (e.size()) {
		for (int i = 0; i < e.size(); i++) {
			map[e[i].x][e[i].y] = 0;
			e[i].x += dx[e[i].d], e[i].y += dy[e[i].d];
			if (e[i].x < 0 || e[i].x > 4000 || e[i].y < 0 || e[i].y > 4000) {
				e.erase(e.begin() + i);
				--i;
				continue;
			}
			map[e[i].x][e[i].y] += e[i].k;
		}
		for (int i = 0; i < e.size(); i++) {
			if (map[e[i].x][e[i].y] != e[i].k) {
				ans += e[i].k;
				map[e[i].x][e[i].y] = 0;
				e.erase(e.begin() + i);
				--i;
				
			}
		}
	}
	return ans;
}

int run() {
	init();
	return solve();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "#" << t << " " << run() << "\n";
	}
	return 0;
}
*/