/*
https://www.acmicpc.net/problem/15422

&Title
15422번 - Bumped!

&Question
Peter returned from the recently held ACM ICPC 
World Finals only to find that his return flight 
was overbooked and he was bumped from the flight! 
Well, at least he wasn’t beat up by the 
airline and he’s received a voucher for one free 
flight between any two destinations he wishes.He is already 
planning next year’s trip. He plans to travel by 
car where necessary, but he may be using his 
free flight ticket for one leg of the trip. 
He asked for your help in his planning.He can 
provide you a network of cities connected by roads, 
the amount it costs to buy gas for traveling 
between pairs of cities, and a list of available 
flights between some of those cities. Help Peter by 
finding the minimum amount of money he needs to 
spend to get from his hometown to next year’s 
destination! 

&Input
The input consists of a single test case. 
The first line lists five space-separated integers n, m, 
f, s, and t, denoting the number of cities 
n (0 < n ≤ 50 000), the number 
of roads m (0 ≤ m ≤ 150 000), 
the number of flights f (0 ≤ f ≤ 
1 000), the number s (0 ≤ s < 
n) of the city in which Peter’s trip starts, 
and the number t (0 ≤ t < n) 
of the city Peter is trying to travel to. 
(Cities are numbered from 0 to n − 1.)The 
first line is followed by m lines, each describing 
one road. A road description contains three space separated 
integers i, j, and c (0 ≤ i, j 
< n, i ≠ j and 0 < c 
≤ 50 000), indicating there is a road connecting 
cities i and j that costs c cents to 
travel. Roads can be used in either direction for 
the same cost. All road descriptions are unique.Each of 
the following f lines contains a description of an 
available flight, which consists of two space separated integers 
u and v (0 ≤ u, v < n, 
u ≠ v) denoting that a flight from city 
u to city v is available (though not from 
v to u unless listed elsewhere). All flight descriptions 
are unique. 

&Output
Output the minimum number of cents Peter needs 
to spend to get from his home town to 
the competition, using at most one flight. You may 
assume that there is a route on which Peter 
can reach his destination. 

&Example
-input
8 11 1 0 5
0 1 10
0 2 10
1 2 10
2 6 40
6 7 10
5 6 10
3 5 15
3 6 40
3 4 20
1 4 20
1 3 20
4 7

-output
45

-input
8 11 1 0 5
0 1 10
0 2 10
1 2 10
2 6 40
6 7 10
5 6 10
3 5 15
3 6 40
3 4 20
1 4 20
1 3 30
4 7

-output
50


*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 50001;
const long long INF = 1e15;

struct node{
	int index;
	bool check;
};

struct vertex {
	long long distance;
	node info;
	bool operator < (const vertex& v) const {
		return this->distance > v.distance;
	}
};

int n, m, f, s, t;
vector<int> dfree[MAXN];
long long dist[MAXN][2];
vector<vertex> adj[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> f >> s >> t;
	int u, v, c;
	while (m--) {
		cin >> u >> v >> c;
		adj[u].push_back({ c, v, false });
		adj[v].push_back({ c, u, false });
	}
	while (f--) {
		cin >> u >> v;
		dfree[u].push_back(v);
	}
	fill(&dist[0][0], &dist[n][2], INF);
	priority_queue<vertex> pq;
	pq.push({ 0, s, false });
	dist[s][false] = 0;
	while (!pq.empty()) {
		vertex cur = pq.top();
		node& curN = cur.info;
		pq.pop();
		if (cur.distance > dist[curN.index][curN.check])continue;
		for (vertex& next : adj[curN.index]) {
			long long& nextValue = dist[next.info.index][curN.check];
			if (nextValue == INF || dist[curN.index][curN.check] + next.distance < nextValue) {
				nextValue = dist[curN.index][curN.check] + next.distance;
				pq.push({ nextValue, {next.info.index, curN.check} });
			}
		}

		if (curN.check)continue;
		for (int& next : dfree[curN.index]) {
			long long& nextValue = dist[next][true];
			if (nextValue == INF || dist[curN.index][curN.check] < nextValue) {
				nextValue = dist[curN.index][curN.check];
				pq.push({ nextValue, {next, true} });
			}
		}
	}
	cout << min(dist[t][false], dist[t][true]) << endl;
	return 0;
}
*/