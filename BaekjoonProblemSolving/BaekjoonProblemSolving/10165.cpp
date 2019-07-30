/*
https://www.acmicpc.net/problem/10165

&Title
10165번 - 버스 노선

&Question
국경을 따라 순환 도로를 건설한 국가가 있다. 이 
순환 도로에는 N개의 위치에 버스 정류소가 있으며, 버스 정류소에는 
0부터 N-1까지 번호가 시계방향 순서로 지정되어 있다. 현재 여러 
개의 버스 노선들이 이 순환 도로에서 운행되고 있다. 각 
버스 노선은 [a,b]로 표시된다. 이 노선의 버스는 버스 정류소 
a부터 b까지를 시계방향으로, b부터 a까지는 반시계방향으로 운행한다. 순환 도로 
상의 모든 정류소를 포함하는 버스 노선은 존재하지 않는다. 국가 
교통행정부에서 비용 절감을 위해서 버스 노선 중 일부를 취소하려고 
한다. 취소되는 노선은 다른 노선에 포함되어 있는 노선이다. 예를 
들어, N=10일 때, 5개의 버스 노선이 다음과 같이 있다고 
하자. [0, 4], [2, 6], [5, 0], [7, 9], 
[9, 4]위 그림에서 버스 노선 ①은 ⑤에 포함되고, 버스 
노선 ④는 ③에 포함된다. 버스 노선 ②, ③, ⑤를 
포함하는 노선은 없다. 따라서 취소되는 버스 노선은 ①과 ④이다.버스 
노선에 대한 정보가 주어질 때, 취소되지 않고 계속 운행되는 
버스 노선을 모두 출력하는 프로그램을 작성하시오. 

&Input
첫 번째 줄에는 버스 정류소의 개수 N(3 ≤ 
N ≤ 1,000,000,000)이 주어지고 두 번째 줄에는 버스 노선의 
수 M(2 ≤ M ≤ 500,000)이 주어진다. 각 버스 
노선은 1부터 M까지의 번호로 구분된다. 그 다음 M개의 줄에는 
1번 노선부터 순서대로 각 버스 노선 [a,b]를 나타내는 두 
개의 정수 a와 b가 한 줄에 주어진다, 단, 0 
≤ a, b ≤ N-1이고 a≠b이며 동일한 버스 노선이 
두 번 이상 입력으로 주어지는 경우는 없다. 또한 순환 
도로 상의 모든 정류소를 포함하는 버스 노선은 존재하지 않는다. 


&Output
입력으로 주어진 버스 노선들 중에서 다른 노선에 포함되지 
않은 노선들의 번호를 번호가 작은 것부터 순서대로 빈칸을 사이에 
두고 출력한다. 

&Example
-input
10
5
0 4
2 6
5 0
7 9
9 4

-output
2 3 5


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N = 1e9 + 5;
const int MAX_M = 5e5 + 5;
const int INF = 1e9;

struct Event {
	int x, y, id, type; // 시작점, 종착점, id, type(0:시계방향, 1:반시계방향)

	Event(int x, int y, int id, int type) : x(x), y(y), id(id), type(type) {}

	bool operator < (const Event& rhs) const {
		if (x != rhs.x)return x < rhs.x;
		return y > rhs.y;
	}
};

int n, m;
vector<Event> events;
bool covered[MAX_M];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	events.reserve(MAX_M * 2); // 저장공간 예약 함수
	for (int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		// 원 기준 한바퀴를 벗어난 경우
		if (a > b) {
			events.emplace_back(a, n + b, i, 0); // a ~ n+b
			events.emplace_back(n + b, a, i, 1); // n+b ~ a 반시계반향(type 1) 일경우 x > y
			// emplace_back함수는 push_back보다 조금 더 유리하다.
			// 생성자 인자를 입력 받아 벡터내에서 직접 객체를 생성하여 삽입하므로
			// 임시 객체 생성 -> 복사 -> 파괴를 하지 않아도 된다.
		}
		// 원 정상 범위 안에 들어있는 경우
		else {
			events.emplace_back(a, b, i, 0); //  a ~ b type 0
			events.emplace_back(b, a, i, 1); // b ~ a type 1
			events.emplace_back(n + a, n + b, i, 0); // n+a ~ n+b type 0 범위를 2n으로 잡는듯?
			events.emplace_back(n + b, n + a, i, 1); // n+b ~ n+a type 1
		}
	}
	sort(events.begin(), events.end()); // operator에 따른 정렬
	multiset<int> s; // set과 다르게 중복된 key 값을 저장 할 수 있음
	for (Event& p : events) {
		if (p.type) { // 반시계방향인 경우 처리
			multiset<int>::iterator it = s.find(p.y);
			s.erase(it); // 시계방향때 삽입했던걸 지워줌..
			if (!s.empty() && *s.begin() <= p.y) { // s.begin()은 가장 오래된 원소 일것(순서대로 넣으니..)
				// 띵킹해보면.. 스택 비슷하게 응용.. 이전에 삽입 된것 중 자신보다 작은게 있는가? 라는 질의다.
				covered[p.id] = true; // 해당 id는 다른 선에 포함이 되는 경우이다.
			}
		}
		else { // 시계방향인 경우 처리
			s.insert(p.x);
		}
	}
	for (int i = 1; i <= m; ++i)
		if (!covered[i])
			cout << i << " ";
	cout << endl;
	return 0;
}
*/

/*
// 좀더 최적화 소스
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int num, s, e;
} b;

int n, m, x, y, idx, Max;
b B[1000001];
bool flag[500001];

bool cmp(b X, b Y) {
	if (X.s == Y.s) return X.e > Y.e;
	else return X.s < Y.s;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &B[i].s, &B[i].e);
		B[i].num = i + 1;

		if (B[i].s < B[i].e) {
			B[m + idx].s = B[i].s + n;
			B[m + idx].e = B[i].e + n;
			B[m + idx].num = B[i].num;
			++idx;
		}
		else B[i].e += n;
	}
	sort(B, B + m + idx, cmp);

	for (int i = 0; i < m + idx; ++i) {
		if (Max < B[i].e)Max = B[i].e;
		else flag[B[i].num] = true;
	}

	for (int i = 1; i <= m; ++i)
		if (!flag[i])printf("%d ", i);

	return 0;
}
*/