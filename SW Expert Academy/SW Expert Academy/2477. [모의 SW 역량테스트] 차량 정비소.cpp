/*
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy

2477. [모의 SW 역량테스트] 차량 정비소
※ SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.


고객이 차량 정비소에 지갑을 두고 갔다.

차량 정비소에서 근무하는 이 대리는 고객에게 지갑을 돌려주려고 한다.

하지만, 차량 정비소를 방문한 고객이 너무 많아 모두 전화하여 확인하기가 불가능하다.

다행히 지갑에는 고객만족도 설문지가 있다.

고객만족도 설문지에는 고객이 이용했던 접수 창구번호와 정비 창구번호가 있다.

이 대리는 이 정보를 이용하여 전화로 확인할 고객을 정하려고 한다.

차량 정비소에는 N개의 접수 창구와 M개의 정비 창구가 있다.

접수 창구는 1부터 N까지 번호가 붙어 있다. 정비 창구도 1부터 M까지 번호가 붙어 있다.

차량 정비소에는 [Fig. 1]와 같이 두 단계를 거쳐 고객의 차량을 정비한다.

첫 단계는 접수 창구에서 고장을 접수하는 것이고, 두 번째 단계는 정비 창구에서 차량을 정비하는 것이다.
 
[Fig. 1]

차량 정비가 끝난 고객은 고객만족도 조사를 위해 고객만족도 설문지를 받는다.

접수 창구 및 정비 창구의 담당자 업무 능력이 달라서 담당자 별 처리 시간이 다르다.

한 담당자의 처리 시간은 고객과 고장의 종류에 상관 없이 항상 같다.

접수 창구 i에서 고객 한 명의 고장을 접수하는 데 걸리는 처리 시간은 ai이다. (1 ≤ i ≤ N)

정비 창구 j에서 고객 한 명의 차량을 정비하는 데 걸리는 처리 시간은 bj이다. (1 ≤ j ≤ M)

지금까지 차량 정비소를 방문한 고객은 K명이다.

고객은 도착하는 대로 1번부터 고객번호를 부여 받는다.

고객번호 k의 고객이 차량 정비소에 도착하는 시간은 tk이다. (1 ≤ k ≤ K)

고객이 차량 정비소에 도착하면, 빈 접수 창구가 있는 경우 빈 접수 창구에 가서 고장을 접수한다.

빈 접수 창구가 없는 경우 빈 접수 창구가 생길 때까지 기다린다.

고장 접수를 완료하면 정비 창구로 이동한다.

빈 정비 창구가 있는 경우 빈 정비 창구에 가서 차량을 정비 받는다.

빈 정비 창구가 없는 경우 빈 정비 창구가 생길 때까지 기다린다.

접수 창구의 우선순위는 아래와 같다.

   ① 여러 고객이 기다리고 있는 경우 고객번호가 낮은 순서대로 우선 접수한다.
   ② 빈 창구가 여러 곳인 경우 접수 창구번호가 작은 곳으로 간다.


정비 창구의 우선순위는 아래와 같다.

   ① 먼저 기다리는 고객이 우선한다.
   ② 두 명 이상의 고객들이 접수 창구에서 동시에 접수를 완료하고 정비 창구로 이동한 경우, 이용했던 접수 창구번호가 작은 고객이 우선한다.
   ③ 빈 창구가 여러 곳인 경우 정비 창구번호가 작은 곳으로 간다.


고객이 차량 정비소에 도착하여 접수 창구로 가는 시간 또는 접수 창구에서 정비 창구로 이동하는 시간은 무시할 수 있다. 즉, 이동 시간은 0이다.

고객의 도착 시간 tk, 접수 창구의 처리 시간 ai, 정비 창구의 처리 시간 bj가 주어졌을 때, 지갑을 분실한 고객과 같은 접수 창구와 같은 정비 창구를 이용한 고객의 고객번호들을 찾아 그 합을 출력하는 프로그램을 작성하라.

만약, 그런 고객이 없는 경우 -1을 출력한다.


[예시]

[Fig. 2]과 같이 접수 창구가 2개, 정비 창구가 2개가 있다고 하자. (N = 2, M = 2)
 
[Fig. 2]


접수 창구의 처리 시간 ai와 정비 창구의 처리 시간 bj는 [Table 1]과 같이 주어진다.

 
[Table 1]


지금까지 고객 6명이 이용했다. (K = 6)

고객 k의 도착 시간 tk는 [Table 2]와 같이 주어진다.

 
[Table 2]


지갑을 분실한 고객은 접수 창구 1과 정비 창구 2를 이용했다고 한다.

이 대리는 지갑을 분실한 고객과 같은 접수 창구 1과 정비 창구 2를 이용한 고객들의 고객번호를 알고 싶어 한다.

시간 별 고객들의 이동은 [Fig. 3]와 같다.

[Fig. 3]
 

접수 창구 1과 정비 창구 2를 이용한 고객의 고객번호는 1과 6이다.

따라서, 정답은 1 + 6 = 7이다.


[제약사항]

1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 3초

2. 접수 창구의 개수 N과 정비 창구의 개수 M은 1 이상 9 이하의 정수이다. (1 ≤ N, M ≤ 9)

3. 접수 창구 i에서 고장을 접수하는 처리 시간 ai는 1 이상 20 이하의 정수이다. (1 ≤ ai ≤ 20)

4. 정비 창구 j에서 차량을 정비하는 처리 시간 bj는 1 이상 20 이하의 정수이다. (1 ≤ bj ≤ 20)

5. 차량 정비소를 방문한 고객의 수 K는 2 이상 1,000 이하의 정수이다. (2 ≤ K ≤ 1,000)

6. 고객 k의 도착 시간 tk는 0 이상 1,000 이하의 정수이다. (0 ≤ tk ≤ 1,000)

7. 지갑을 두고 간 고객이 이용한 접수 창구번호 A는 1 이상 N 이하의 정수이다. (1 ≤ A ≤ N)

8. 지갑을 두고 간 고객이 이용한 정비 창구번호 B는 1 이상 M 이하의 정수이다. (1 ≤ B ≤ M)

9. 창구번호와 고객번호는 1부터 시작한다.


[입력]

입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 접수 창구의 개수 N, 정비 창구의 개수 M, 차량 정비소를 방문한 고객의 수 K, 지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B가 주어진다.

두 번째 줄에는 i번째 접수 창구가 고장을 접수하는 데 걸리는 시간 ai가 N개 주어진다.

세 번째 줄에는 j번째 정비 창구가 차량을 정비하는 데 걸리는 시간 bj가 M개 주어진다.

네 번째 줄에는 k번째 고객이 차량 정비소를 방문하는 시간 tk가 순서대로 K개 주어진다.


[출력]

테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.

각 줄은 "#x"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)

출력해야 할 정답은 지갑을 두고 간 고객과 같은 접수 창구 A와 같은 정비 창구 B를 이용한 고객들의 고객번호의 합이다. 만약 그런 고객이 없는 경우 정답으로 -1을 출력한다.
입력
10
1 1 2 1 1
5
7
7 10
2 2 6 1 2
3 2
4 2
0 0 1 2 3 4
… // 총 테스트 케이스 개수 T=10
// 첫 번째 테스트 케이스, N=1, M=1, K=2, A=1, B=1
// a1=5
// b1=7
// t1=7, t2=10
// 두 번째 테스트 케이스, N=2, M=2, K=6, A=1, B=2,본문예제
// a1=3, a2=2
// b1=4, b2=2
// t1=0, t2=0, t3=1, t4=2, t5=3, t6=4
// 나머지는 sample_input.txt 참조
sample_input.txt
출력
#1 3
#2 7
#3 2
#4 22
#5 18
#6 15
#7 -1
#8 259
#9 100
#10 164
sample_output.txt
*/

/*
1. 도착시간이 되면 pq에 넣어줌
2. 접수가 끝나면 q에 넣어줌
3. 정비가 끝나면 finish 처리해줌 -> 이때 a, b랑 비교
4. pq에 있는사람이 접수처에 들어갈 수 있는지
5. q에 있는사람이 정비에 들어갈 수 있는지

시뮬레이션 문제.. 이제 너무 풀었더니
단순 시뮬문제는 잘푸네.. ㅋㅋㅋ
*/
/*
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>
using namespace std;
struct customer {
	int arrive = 0;
	int rc = 0;
	int mt = 0;
};

int n, m, k, a, b, finish, t, result;//접수 창구N, 정비 창구M, 고객의 수 K, 지갑을 두고 간 고객이 이용한 접수 창구번호 A와 정비 창구번호 B
int recipt[10], maintenance[10]; // 접수 창구 걸리는 시간, 정비 걸리는 시간
pair<int, int> recipt_in[10], maintenance_in[10]; // (번호, 종료시간)
customer cu[1001];
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> q;

void arrive() {
	for(int i = 1; i <= k; ++i)
		if (cu[i].arrive == t) {
			pq.push(i);
		}
}

void stay() {
	for (int i = 0; i < n; ++i) {
		if (recipt_in[i].second == t) {
			q.push(recipt_in[i].first);
			recipt_in[i].first = 0;
		}
	}
}

void fin() {
	for (int i = 0; i < m; ++i) {
		if (maintenance_in[i].second == t) {
			int num = maintenance_in[i].first;
			if (cu[num].rc == a && cu[num].mt == b)
				result += num;
			maintenance_in[i].first = 0;
			++finish;
		}
	}
}

void go_recipt() {
	if (pq.empty())return;
	for (int i = 0; i < n; ++i) {
		if (recipt_in[i].first == 0) {
			recipt_in[i].first = pq.top();
			cu[pq.top()].rc = i + 1; 
			recipt_in[i].second = t + recipt[i];
			pq.pop();
			if (pq.empty())return;
		}
	}
}

void go_maintenance() {
	if (q.empty())return;
	for (int i = 0; i < m; ++i) {
		if (maintenance_in[i].first == 0) {
			maintenance_in[i].first = q.front();
			cu[q.front()].mt = i + 1;
			maintenance_in[i].second = t + maintenance[i];
			q.pop();
			if (q.empty())return;
		}
	}
}

void CarRepairShop() {
	while (finish < k) {
		arrive(); // 고객님 도착하면 pq에 넣어줌
		stay(); // 접수 끝났으면 기다리는 큐에 넣어줌!
		fin(); // 고갱님 정비 끝나셨어요 ^^
		go_recipt(); // 빈 접수 창구가 있으면 ㄱㄱㅆ
		go_maintenance(); // 빈 정비소 창구 있으면 gogo
		++t;
	}
}

void init() {
	result = 0;
	finish = 0;
	t = 0;
	for (int i = 0; i < 10; ++i) {
		recipt_in[i].first =  maintenance_in[i].first = 0;
		recipt_in[i].second = maintenance_in[i].second = -1; // 애네 0으로 하면 t가 0일때 큐에 넣어버림 ==
	}
	
	cin >> n >> m >> k >> a >> b;
	for (int i = 0; i < n; ++i)
		cin >> recipt[i];
	for (int i = 0; i < m; ++i)
		cin >> maintenance[i];
	for (int i = 1; i <= k; ++i)
		cin >> cu[i].arrive;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		init();
		CarRepairShop();
		if (result == 0)result = -1;
		cout << '#' << t << " " << result << '\n';
	}
	return 0;
}
*/