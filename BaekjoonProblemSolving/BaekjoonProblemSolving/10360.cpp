/*
https://www.acmicpc.net/problem/10360

&Title
10360번 - The Mountain of Gold 

&Question
Ancient history and myth points to the Gunung 
Ledang (a.k.a. Ledang Mountain, as “gunung” is mountain in 
Malaysian) being the site of rich gold deposits, luring 
traders from as far as Greece and China. In 
the 14th Century, the Chinese seafarers plying the Straits 
of Melaka called it ‘Kim Sua’ meaning the ‘Golden 
Mountain’. The mountain was named ‘Gunung Ledang’, which means 
‘mount from afar’, during the period of the Majapahit 
empire. Legend has it, that before the death of 
Princess Gunung Ledang, she hid a huge amount of 
gold far back in time during the creation of 
earth in Ledang Mountain. It is(apparently, becoming “was”) a 
mystery as to how the princess was able to 
go so far back in time. However, the princess 
was known to possess mystical powers that could enchant 
any pool she bath in into a portal that 
could manipulate time and space. A Malaysian historian of 
this time have discovered many of these pools located 
near many mountains around the world and named them 
“Ledang Pools”. A Ledang Pool is a portal through 
space and time connecting two pools. Ledang Pools have 
a few peculiar properties:A Ledang Pool is a one 
way portal with two end points, i.e. it connects 
exactly two mountains.The time it takes to travel through 
a Ledang Pool is negligible.Each mountain might have multiple 
Ledang Pools’ end point in its area.For some unknown 
reasons, starting from Ledang Mountain in Malaysia, it is 
always possible to end up in any mountain (of 
course, which also has Ledang Pool end point)on earth 
by hopping a sequence of Ledang Pools.There are no 
Ledang Pools with both end points on the same 
mountain area.Each Ledang Pool has a fixed time difference 
(distortion) between their end points. For example, traveling through 
a certain Ledang Pool may cause that person to 
end up 42 years in the past at the 
other end point. It’s a space and time traveling!The 
Malaysian historian suspects that a large amount of gold 
is hidden in Ledang Mountain in the past because 
there’s no gold found in this mountain at this 
time (but then, where does the myth come from?). 
Starting from Ledang Mountain, the historian wants to reach 
the same mountain (Ledang Mountain) in the past. In 
order to this, he has to hop into two 
or more Ledang Pools, doing the space-and-time-travel things, and 
end up at Ledang Mountain in the past. Note 
that he does not care in which time in 
the past he will end up at Ledang Mountain 
as long as it is in the past. Your 
task is to help this historian to determine whether 
it is possible to reach Ledang Mountain in the 
past from Ledang Mountain in the present time by 
hopping a sequence of Ledang Pools. 

&Input
The input file starts with a line containing 
the number of cases T (1 ≤ T ≤ 
20). Each case starts with two numbers N and 
M in a line. These indicate the number of 
mountains which have Ledang Pool end point (1 ≤ 
N ≤ 1,000) and the number of Ledang Pools 
(0 ≤ M ≤ 2,000). The pools are numbered 
from 0 (Ledang Mountain in Malaysia) up to N-1. 
The next M lines each contains three integers A, 
B, C (0 ≤ A, B < N; A 
≠ B; -1,000 ≤ C ≤ 1,000) denoting the 
properties of one Ledang Pool, i.e. someone can do 
a space-time-travel from mountain A to mountain B and 
he will end up C year in the future/past. 
If C is positive, then it is in the 
future, otherwise it is in the past. 

&Output
For each case, output in a line "Case 
#X: Y" (without quotes) where X is the case 
number starting from 1, and Y is “possible” (without 
quotes) if it is indeed possible to reach Ledang 
Mountain in the past, otherwise output Y as “not 
possible” (without quotes). 

&Example
-input
2
2 2
0 1 15
1 0 -20
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

-output
Case #1: possible
Case #2: not possible


*/

/*
공주가 골드산을 숨기고 죽었다는데
과거나 미래로 가면서 다른 산으로 가는 Leadng Pool이라는 것을 통해 Ledang Mountain에서 출발하여
Leading Mountain 과거 어느순간이든 도달하면 성공!
벨만포드로 n번 돌려서 음수인지 확인!
해당 음수가 0번을 통해 갈 수 있는 경로를 통해 업데이트 된것인지 확인
왜냐! 0번산에서 갈 수 없는 산끼리 음수가중치 짝짝꿍해서 음수사이클이 생겨 0번 산이 음수로 업데이트 된거 일수도 있기 때문이다.
*/

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

struct vertex {
	int index, distance;
};

int n, m;
vector<vertex> adj[1001];
vector<int> rev[1001];
int dist[1001];
bool visited[1001];

// 0으로부터 갈 수 있는 곳 다 확인
void bfs() {
	queue<int> q;
	visited[0] = true;
	q.push(0);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int next : rev[cur])
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
	}
}

bool bellmanford() {
	dist[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dist[j] == INF)continue;
			for (vertex& v : adj[j]) {
				if (dist[j] + v.distance < dist[v.index]) {
					dist[v.index] = dist[j] + v.distance;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (vertex& v : adj[i]) {
			if (visited[v.index] && dist[i] + v.distance < dist[v.index])
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			rev[i].clear();
			dist[i] = INF;
			visited[i] = false;
		}
		int a, b, c;
		while(m--){
			cin >> a >> b >> c;
			adj[a].push_back({ b, c });
			rev[b].push_back(a);
		}
		bfs();
		cout << "Case #" << t << ": " << (bellmanford() ? "possible\n" : "not possible\n");
	}
	return 0;
}
*/