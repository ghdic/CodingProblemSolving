/*
https://www.acmicpc.net/problem/1728

&Title
1728번 - 구슬 굴리기

&Question
탁자 위에 N 개의 구슬 굴러다닌다. 탁자를 하나의 
좌표 평면으로 보았을 때, 구슬은 x축에 나란하게 굴러다니는데, 각각의 
y좌표가 달라 굴러다니는 도중에 충돌은 일어나지 않는다. 각각의 구슬은 
일정한 속도를 가지고 있으며, 출발 위치가 서로 다르다.일정한 시간 
간격으로 구슬의 사진을 찍어 구슬들의 x좌표들을 모두 나열한다고 생각하자. 
이때, 구슬들의 모양이 모두 똑같아서 어느 구슬이 어느 좌표에 
있는지는 사진에서 알 수 없다. 그러나 일정한 간격으로 찍은 
몇 개의 사진이 주어진다면, 각 구슬의 출발 위치와 속도를 
모두 알아낼 수 있게 된다. 이를 알아내는 프로그램을 작성하시오. 


&Input
첫 행에는 구슬의 개수 N이 주어진다. (1 ≤ 
N ≤ 500) 사진은 N+1장이 주어지며, 다음 행부터 각각의 
사진에 보이는 구슬들의 x좌표가 주어진다.구슬의 x좌표는 절댓값이 20억을 넘지 
않는 자연수이다. 

&Output
N개의 줄에 각 구슬의 처음 위치와 속도를 빈 
칸을 사이에 두고 출력한다. 이때, 구슬의 처음 위치를 기준으로, 
오름차순 정렬하여 출력하도록 한다. 

&Example
-input
3
0 2 3
5 1 1
2 0 7
9 3 -1

-output
0 1
2 -1
3 2


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAXN = 502;
const int MAX = 2e9;
struct info {
	int start, interval;

	bool operator < (const info v) const {
		return this->start < v.start;
	}
};
int n;
unordered_map<int, int> us[MAXN], gap[MAXN];
info res[MAXN];
vector<long long> values(MAXN);

bool combine(int cur) {
	// n개의 공차 다 골랐으면 끝
	if (cur == n) {
		return true;
	}
	for (auto v : gap[cur]) {
		int i;
		long long val = res[cur].start + v.first;
		bool flag = false;
		for (i = 1; i <= n; ++i, val += v.first) {
			if (val > MAX) {
				flag = true; break;
			}
			if (us[i][val]) {
				us[i][val]--;
			}
			else {
				flag = true; break;
			}
		}
		if (flag) {
			// 복구해준다.
			val = res[cur].start + v.first;
			for (int j = 1; j < i; ++j, val += v.first) {
				us[j][val]++;
			}
		}
		else {
			if (combine(cur + 1)) {
				res[cur].interval = v.first;
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> res[i].start;
	int val;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> val;
			us[i][val]++;
		}
	}
	// 공차 구함 중복제거를 위해 map 사용
	for (int i = 0; i < n; ++i) {
		for (auto v : us[1]) {
			gap[i][v.first - res[i].start]++;
		}
	}
	// 공차들의 조합으로 브루트포스
	combine(0);
	sort(&res[0], &res[n]);
	for (int i = 0; i < n; ++i) {
		cout << res[i].start << ' ' << res[i].interval << '\n';
	}
	return 0;
}
*/

/*
// 틀림 먼저 n개 공차 고르는 식으로 짰더니
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAXN = 502;
const int MAX = 2e9;
int n;
unordered_map<int, int> us[MAXN], gap[MAXN];
int start[MAXN];
vector<int> interval;
vector<long long> values(MAXN); // 더할때 int 범위 넘을 수도 있으니 long long

bool dfs(int cur) {
	if (cur == n + 1) {
		return true; // n 번째 라인까지 같다면 정답을 찾은것
	}
	unordered_map<int, int> copy = us[cur];
	for (int i = 0; i < n; ++i) {
		values[i] += interval[i]; // 공차만큼 더함
		if (values[i] > MAX)return false; // 2e9넘으면 out
		if (copy[values[i]]) { // 해당 라인에 공차를 더한 값이 있다면 계속 go아니면 stop
			copy[values[i]]--;
		}
		else return false;
	}
	return dfs(cur + 1);
}

bool combine(int cur) {
	// n개의 공차 다 골랐으면 go
	if (cur == n) {
		for (int i = 0; i < n; ++i)
			values[i] = start[i] + interval[i];
		return dfs(2);
	}
	for (auto v : gap[cur]) {
		auto& k = us[1][start[cur] + v.first];
		if (k != 0) {
			k--;
			interval.push_back(v.first);
			if (combine(cur + 1))return true;
			interval.pop_back();
			k++;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> start[i];
	int val;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> val;
			us[i][val]++;
		}
	}
	// 공차 구함 중복제거를 위해 map 사용
	for (int i = 0; i < n; ++i) {
		for (auto v : us[1]) {
			gap[i][v.first - start[i]]++;
		}
	}
	// 공차들의 조합으로 브루트포스
	combine(0);
	for (int i = 0; i < n; ++i) {
		cout << start[i] << ' ' << interval[i] << '\n';
	}
	return 0;
}
*/