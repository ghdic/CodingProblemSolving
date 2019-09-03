/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl

2383. [모의 SW 역량테스트] 점심 식사시간
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


N*N 크기의 정사각형 모양의 방에 사람들이 앉아 있다.

점심을 먹기 위해 아래 층으로 내려가야 하는데, 밥을 빨리 먹기 위해 최대한 빠른 시간 내에 내려가야 한다.

방 안의 사람들은 P로, 계단 입구를 S라고 했을 때 [Fig. 1]은 사람의 위치와 계단 입구의 위치를 표시한 모습이다.

 
[Fig. 1]
 

이동 완료 시간은 모든 사람들이 계단을 내려가 아래 층으로 이동을 완료한 시간이다.

사람들이 아래층으로 이동하는 시간은 계단 입구까지 이동 시간과 계단을 내려가는 시간이 포함된다.


    ① 계단 입구까지 이동 시간
        - 사람이 현재 위치에서 계단의 입구까지 이동하는데 걸리는 시간으로 다음과 같이 계산한다.
        - 이동 시간(분) = | PR - SR | + | PC - SC |
          (PR, PC : 사람 P의 세로위치, 가로위치, SR, SC : 계단 입구 S의 세로위치, 가로위치)

    ② 계단을 내려가는 시간
        - 계단을 내려가는 시간은 계단 입구에 도착한 후부터 계단을 완전히 내려갈 때까지의 시간이다.
        - 계단 입구에 도착하면, 1분 후 아래칸으로 내려 갈 수 있다.
        - 계단 위에는 동시에 최대 3명까지만 올라가 있을 수 있다.
        - 이미 계단을 3명이 내려가고 있는 경우, 그 중 한 명이 계단을 완전히 내려갈 때까지 계단 입구에서 대기해야 한다.
        - 계단마다 길이 K가 주어지며, 계단에 올라간 후 완전히 내려가는데 K 분이 걸린다.


사람의 위치와 계단 입구의 위치 및 계단의 길이 정보가 표시된 N*N 크기의 지도가 주어진다.

이때, 모든 사람들이 계단을 내려가 이동이 완료되는 시간이 최소가 되는 경우를 찾고,

그 때의 소요시간을 출력하는 프로그램을 작성하라.


[예시]

방의 한 변의 길이 N 이 5인 지도가 [Fig. 2]와 같이 주어진 경우를 생각해보자.

지도 내에 1 은 사람을 나타내고, 2 이상 10 이하의 숫자는 계단의 입구를 나타내며 해당 숫자는 계단의 길이를 의미한다.

[Fig. 2]에는 사람 6명이 있고, 계단은 2개가 있으며 길이는 각각 3과 5이다.
  [Fig. 2]


다음은 이동 완료되는 시간이 최소가 되는 경우 중 하나이다.

    - 1번, 2번, 3번 사람은 길이가 3인 1번 계단을 통해 이동

    - 4번, 5번, 6번 사람은 길이가 5인 2번 계단을 통해 이동





이 경우, 모든 사람이 계단을 내려가 이동 완료하는 최소 시간은 9분이다.

다른 예시로, 한 변의 길이가 N인 방에 [Fig. 3]과 같이 배치되어 있는 경우를 생각해보자.

지도 내에 1 은 사람을 나타내고, 2 이상 10 이하의 숫자는 계단의 입구를 나타내며 해당 숫자는 계단의 길이를 의미한다.

  [Fig. 3]

  다음은 이동이 완료되는 시간이 최소가 되는 경우 중 하나이다.

    - 1번, 2번, 3번, 4번 사람은 길이가 2인 1번 계단을 통해 이동

    - 5번, 6번 사람은 길이가 5인 2번 계단을 통해 이동







이 경우, 모든 사람이 계단을 내려가 이동 완료하는 최소 시간은 8분이다.


[제약 사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초

2. 방의 한 변의 길이 N은 4 이상 10 이하의 정수이다. (4 ≤ N ≤ 10)

3. 사람의 수는 1 이상 10 이하의 정수이다. (1 ≤ 사람의 수 ≤ 10)

4. 계단의 입구는 반드시 2개이며, 서로 위치가 겹치지 않는다.

5. 계단의 길이는 2 이상 10 이하의 정수이다. (2 ≤ 계단의 길이 ≤ 10)

6. 초기에 입력으로 주어지는 사람의 위치와 계단 입구의 위치는 서로 겹치지 않는다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 방의 한 변의 길이 N이 주어진다.

다음 N줄에는 N*N 크기의 지도의 정보가 주어진다.

지도에서 1은 사람을, 2 이상은 계단의 입구를 나타내며 그 값은 계단의 길이를 의미한다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

정답은 이동이 완료되는 최소의 시간을 출력한다.
입력
10
5
0 1 1 0 0
0 0 1 0 3
0 1 0 1 0
0 0 0 0 0
1 0 5 0 0
5
0 0 1 1 0
0 0 1 0 2
0 0 0 1 0
0 1 0 0 0
1 0 5 0 0
… // 총 테스트 케이스 개수 T=10
// 첫 번째 테스트 케이스





// 두 번째 테스트 케이스





// 나머지는 sample_input.txt 참조
sample_input.txt
출력
#1 9
#2 8
#3 9
#4 7
#5 8
#6 8
#7 11
#8 11
#9 18
#10 12
sample_output.txt
*/
/*
점심을 최대한 빨리 먹기위해 빠른시간내로 내려가야댐
방안 사람들을 p 계단입구를 s라했을때
이동 완료시간(입구까지 + 계단내려가는데 시간)은 아래층으로 모든사람이 이동 완료
계단 위 최대 3명 서있을수 있음(세명이 내려가고있으면 입구에서 ㄱㄷ)
1분 후 아래칸으로 내려갈 수 있음
계단길이 K 완전히 내려가는데 K분
*/

/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct person {
	int y, x;
	person(int y, int x) :y(y), x(x) {};
};
struct door {
	int y, x, stairs;
	door(int y, int x, int stairs) :y(y), x(x), stairs(stairs) {};
};
int n, result = 54321;
vector<person> people;
vector<door> st;
vector<int> Time[2];
vector<int> d1, d2;

void lunch_time() {
	vector<int> v1 = d1, v2 = d2;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int start1 = 0, end1 = 0, start2 = 0, end2 = 0;
	int t;
	for (t = 1; t < 60; ++t) {
		if (start1 == v1.size() && start2 == v2.size())break;
		// 계단 다 내려갔는지 확인
		while (start1 != v1.size() && start1 < end1 && v1[start1] == t) {
			++start1;
		}
		while (start2 != v2.size() && start2 < end2 && v2[start2] == t) {
			++start2;
		}
		//계단에 세명이상 없으면 내려감
		while (end1 != v1.size() && v1[end1] == t) {
			if (end1 - start1 >= 3) {
				v1[end1] = st[0].stairs + v1[end1 - 3];
			}
			else {
				v1[end1] += st[0].stairs;
			}
			end1++;
		}
		while (end2 != v2.size() && v2[end2] == t) {
			if (end2 - start2 >= 3) {
				v2[end2] = st[1].stairs + v2[end2 - 3];
			}
			else {
				v2[end2] += st[1].stairs;
			}
			end2++;
		}
	}
	result = min(result, t);
}

void dfs(int pos) {
	if (pos == people.size()) {
		lunch_time();
		return;
	}
	d1.push_back(Time[0][pos]);
	dfs(pos + 1);
	d1.pop_back();

	d2.push_back(Time[1][pos]);
	dfs(pos + 1);
	d2.pop_back();
}

void get_time() {
	Time[0].resize(people.size());
	Time[1].resize(people.size());
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < people.size(); ++j) {
			Time[i][j] = abs(people[j].y - st[i].y) + abs(people[j].x - st[i].x);
		}
	}
}

void run() {
	get_time();
	dfs(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	people.reserve(10);
	st.reserve(2);
	d1.reserve(10);
	d2.reserve(10);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		result = 54321;
		people.clear();
		st.clear();
		
		cin >> n;
		int z;
		for(int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				cin >> z;
				if (z == 1)
					people.push_back({ i,j });
				else if (z > 1)
					st.push_back({ i,j,z });
			}
		run();
		cout << "#" << t << " " << result << '\n';
	}
	return 0;
}
*/