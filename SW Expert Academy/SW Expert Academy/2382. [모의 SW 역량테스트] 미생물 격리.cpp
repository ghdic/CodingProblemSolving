/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl

2382. [모의 SW 역량테스트] 미생물 격리
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


정사각형 구역 안에 K개의 미생물 군집이 있다.

이 구역은 가로 N개, 세로 N개, 총 N * N 개의 동일한 크기의 정사각형 셀들로 이루어져 있다.

미생물들이 구역을 벗어나는걸 방지하기 위해, 가장 바깥쪽 가장자리 부분에 위치한 셀들에는 특수한 약품이 칠해져 있다.

[Fig. 1]은 9개의 군집이 한 변이 7개의 셀로 이루어진 구역에 배치되어 있는 예이다.

가장자리의 빨간 셀은 약품이 칠해져 있는 셀이다.


[Fig. 1]
 

   ① 최초 각 미생물 군집의 위치와 군집 내 미생물의 수, 이동 방향이 주어진다. 약품이 칠해진 부분에는 미생물이 배치되어 있지 않다. 이동방향은 상, 하, 좌, 우 네 방향 중 하나이다.

   ② 각 군집들은 1시간마다 이동방향에 있는 다음 셀로 이동한다.

   ③ 미생물 군집이 이동 후 약품이 칠해진 셀에 도착하면 군집 내 미생물의 절반이 죽고, 이동방향이 반대로 바뀐다. 
       미생물 수가 홀수인 경우 반으로 나누어 떨어지지 않으므로, 다음과 같이 정의한다.
       살아남은 미생물 수 = 원래 미생물 수를 2로 나눈 후 소수점 이하를 버림 한 값
       따라서 군집에 미생물이 한 마리 있는 경우 살아남은 미생물 수가 0이 되기 때문에, 군집이 사라지게 된다,

   ④ 이동 후 두 개 이상의 군집이 한 셀에 모이는 경우 군집들이 합쳐지게 된다. 
       합쳐 진 군집의 미생물 수는 군집들의 미생물 수의 합이며, 이동 방향은 군집들 중 미생물 수가 가장 많은 군집의 이동방향이 된다. 
       합쳐지는 군집의 미생물 수가 같은 경우는 주어지지 않으므로 고려하지 않아도 된다.
     

M 시간 동안 이 미생물 군집들을 격리하였다. M시간 후 남아 있는 미생물 수의 총합을 구하여라.

시간에 지남에 따라 군집이 변하는 예를 보자.

[Fig. 2]은 최초 군집의 배치를 그림으로 표현한 것이다. 이는 예제 입력 1번과 동일하다. (N = 7, K = 9)
 
[Fig. 2]

1시간 후 [Fig. 3]과 같이 군집들이 이동한다.

A 군집은 약품이 칠해진 구역(가장 자리의 빨간 셀)로 이동하게 되어, 미생물 중3마리만 남고 나머지는 죽는다. 이동 방향은 상에서 하로 바뀐다.

D, E, F 군집은 모두 세로 위치 3, 가로 위치 3에 위치한 셀로 모이게 되며, 합쳐진 군집의 미생물 수는 8 + 14 + 3 = 25가 된다.

E 군집의 미생물 수가 가장 많기 때문에, 합쳐 진 군집의 이동 방향은 E 군집의 이동 방향인 상이 된다.

G, H 군집도 세로 위치 2, 가로 위치 5에 위치한 셀로 모이게 되며, 미생물 수는 108이 되고 이동 방향은 상이 된다.

 
[Fig. 3]


시작으로부터 2시간이 지났을 때, [Fig. 4]와 같이 군집들이 이동한다.

A, B 그룹은 이동 중 섞이지 않고 각 그룹의 이동 방향으로 움직이는데, B 그룹은 약품이 칠해진 셀로 이동하므로 미생물 수가 7에서 3으로 반감하고, 이동 방향이 상에서 하로 바뀐다.
 
 
[Fig. 4]


2시간이 지난 후, 남아 있는 미생물 수는 총 3 + 3 + 5 + 25 + 108 + 1 = 145이다.


[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 5초

2. 구역의 모양은 정사각형으로 주어지며, 한 변의 셀의 개수 N은 5이상 100이하의 정수이다. (5 ≤ N ≤ 100)

3. 최초 배치되어 있는 미생물 군집의 개수 K는 5이상 1,000이하의 정수이다. (5 ≤ K ≤ 1,000)

4. 격리 시간 M은 1이상 1,000이하의 정수이다. (1 ≤ M ≤ 1,000)

5. 최초 약품이 칠해진 가장자리 부분 셀에는 미생물 군집이 배치되어 있지 않다.

6. 최초에 둘 이상의 군집이 동일한 셀에 배치되는 경우는 없다.

7. 각 군집 내 미생물 수는 1 이상 10,000 이하의 정수이다.

8. 군집의 이동방향은 상하좌우 4방향 중 한 방향을 가진다. (상: 1, 하: 2, 좌: 3, 우: 4)

9. 주어진 입력으로 진행하였을 때, 동일한 셀에 같은 미생물 수를 갖는 두 군집이 모이는 경우는 발생하지 않는다.

10.  각 군집의 정보는 세로 위치, 가로 위치, 미생물 수, 이동 방향 순으로 주어진다. 각 위치는 0번부터 시작한다.


[입력]

첫 줄에는 총 테스트 케이스의 개수 T가 주어진다.

그 다음 줄부터 T개의 테스트 케이스가 차례대로 주어진다.

각 테스트 케이스의 첫째 줄에는 구역의 한 변에 있는 셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K가 순서대로 주어지며, 다음 K줄에 걸쳐서 미생물 군집 K개의 정보가 주어진다.

미생물 군집의 정보는 세로 위치, 가로 위치, 미생물 수, 이동 방향 순으로 4개의 정수가 주어진다.


[출력]

테스트 케이스의 개수 만큼 T개의 줄에 각 테스트 케이스에 대한 답을 출력한다.

각 줄은 “#x”로 시작하고, 공백을 하나 둔 후 정답을 출력한다. (x는 테스트 케이스의 번호이며, 1번부터 시작한다.)

출력해야 할 정답은 M시간 후 남아 있는 미생물 수의 총 합이다.
입력
10      
7 2 9   
1 1 7 1 
2 1 7 1
5 1 5 4
3 2 8 4 
4 3 14 1
3 4 3 3 
1 5 8 2 
3 5 100 1
5 5 1 1
... // 총 테스트케이스 개수 T=10
// 테스트 케이스 1,     N=7, M=2, K=9
// 세로위치(1), 가로위치(1), 미생물 수(7), 이동방향(상)


// 세로위치(3), 가로위치(2), 미생물 수(8), 이동방향(우)

// 세로위치(3), 가로위치(4), 미생물 수(3), 이동방향(좌)
// 세로위치(1), 가로위치(5), 미생물 수(8), 이동방향(하)


// 나머지는 sample_input.txt 참조
sample_input.txt
출력
#1 145
#2 5507
#3 9709
#4 2669
#5 3684
#6 774
#7 4797
#8 8786
#9 1374
#10 5040
sample_output.txt
*/

/*
n * n 에 k개의 미생물 군집 벽o
1. 위치, 미생물수, 이동방향
2. 1시간마다 다음 셀로 이동
3. 약품에 칠해진 셀에 도착하면 절반 죽음(소수점버림) 이동방향 반대
4. 두개이상의 군집이 한 셀에 모이는 경우 군집 합쳐짐
이동방향은 미생물수가 많은 곧


/
*/

/*
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
int n, m, k, result = 0;
int Y[4] = { -1, 1, 0 ,0 }, X[4] = { 0, 0, 1, -1 };
vector<int> map[100][100];
pair<int, int> microbe[1001];


// 한 셀에 두개 이상의 군집이 있을 경우 합쳐지는것 처리
void combine() {

	for(int i = 0; i < 100; ++i)
		for(int j = 0; j < 100; ++j)
			if (map[i][j].size() > 1) {
				int Max = 0, pos = 0, cnt = 0;
				for (int k = 0; k < map[i][j].size(); ++k) {
					int key = map[i][j][k];
					if (Max < microbe[key].first) {
						Max = microbe[key].first;
						pos = k;
					}
					cnt += microbe[key].first;
				}
				int key = map[i][j][pos];
				microbe[key].first = cnt;
				map[i][j].clear();
				map[i][j].push_back(key);
			}
}

// 벽에 있을 경우 충돌 처리
bool collideWALL(int key) {
	int dir = microbe[key].second;
	if (dir == UP)dir = DOWN;
	else if (dir == DOWN)dir = UP;
	else if (dir == RIGHT)dir = LEFT;
	else if (dir == LEFT)dir = RIGHT;
	microbe[key].second = dir;
	microbe[key].first /= 2;
	if (microbe[key].first == 0) return false;
	return true;
}

// 벽인지 확인
bool isWALL(int y, int x) {
	return y == 0 || y == n - 1 || x == 0 || x == n - 1;
}
void Move() {
	vector<bool> check(k + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!map[i][j].empty()) {
				int key = map[i][j][0];
				if (!check[key]) {
					int dir = microbe[key].second;
					int y = i + Y[dir], x = j + X[dir];
					map[i][j].erase(map[i][j].begin());
					map[y][x].push_back(key);
					if (isWALL(y, x)) {
						if (!collideWALL(key))map[y][x].pop_back();
					}
					check[key] = true;
				}
			}
		}
	}
}

// 초기 상태 설정 & 입력 처리
void init() {
	result = 0;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			map[i][j].clear();
	cin >> n >> m >> k;
	int r, c, s, d;
	for (int i = 1; i <= k; ++i) {
		cin >> r >> c >> s >> d;
		map[r][c].push_back(i);
		microbe[i] = { s, d-1 };
	}
}

int countMicrobe() {
	int sum = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(!map[i][j].empty())
				sum += microbe[map[i][j][0]].first;
	return sum;
}

void run() {
	init();
	for (int i = 0; i < m; ++i) {
		Move();
		combine();
	}
	result = countMicrobe();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		run();
		cout << "#" << t << " " << result << "\n";
	}
	return 0;
}
*/