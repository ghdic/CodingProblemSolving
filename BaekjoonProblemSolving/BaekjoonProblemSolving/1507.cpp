/*
https://www.acmicpc.net/problem/1507

&Title
1507번 - 궁금한 민호

&Question
강호는 N개의 도시로 이루어진 나라에 살고 있다. 각 
도시는 M개의 도로로 연결되어 있으며, 각 도로를 지날 때 
필요한 시간이 존재한다. 도로는 잘 연결되어 있기 때문에, 도시 
A에서 B로 이동할 수 없는 경우는 존재하지 않는다.도시 A에서 
도시 B로 바로 갈 수 있는 도로가 있거나, 다른 
도시를 거쳐서 갈 수 있을 때, 도시 A에서 B를 
갈 수 있다고 한다.강호는 모든 쌍의 도시에 대해서 최소 
이동 시간을 구해놓았다. 민호는 이 표를 보고 원래 도로가 
몇 개 있는지를 구해보려고 한다.예를 들어, 예제의 경우에 모든 
도시 사이에 강호가 구한 값을 가지는 도로가 존재한다고 해도 
된다. 하지만, 이 도로의 개수는 최솟값이 아니다. 예를 들어, 
도시 1-2, 2-3, 1-4, 3-4, 4-5, 3-5를 연결하는 도로만 
있다고 가정해도, 강호가 구한 모든 쌍의 최솟값을 구할 수 
있다. 이 경우 도로의 개수는 6개이고, 모든 도로의 시간의 
합은 55이다.모든 쌍의 도시 사이의 최소 이동 시간이 주어졌을 
때, 이 나라에 존재할 수 있는 도로의 개수의 최솟값과 
그 때, 모든 도로의 시간의 합을 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 
20)이 주어진다. 둘째 줄부터 N개의 줄에 각각의 도시 사이에 
이동하는데 필요한 시간 (≤ 10,000)이 주어진다. A에서 B로 가는 
시간과 B에서 A로 가는 시간은 같다. 또, A와 B가 
같은 경우에는 필요한 시간은 0이다. 

&Output
첫째 줄에 도로 개수가 최소일 때, 모든 도로의 
시간의 합을 출력한다. 불가능한 경우에는 -1을 출력한다. 

&Example
-input
5
0 6 15 2 6
6 0 9 8 12
15 9 0 16 18
2 8 16 0 4
6 12 18 4 0

-output
55


*/

/*
#include <iostream>
using namespace std;

int n;
int graph[20][20];
bool check[20][20];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> graph[i][j];
	for (int by = 0; by < n; ++by) {
		for (int from = 0; from < n; ++from) {
			if (by == from)continue;
			for (int to = 0; to < n; ++to) {
				if (from == to || by == to)continue;
				
				if (graph[from][to] > graph[from][by] + graph[by][to]) {
					cout << -1 << endl;
					return 0;
				}
				if (graph[from][to] == graph[from][by] + graph[by][to]) {
					check[from][to] = true;
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			if(!check[i][j])
				res += graph[i][j];
	cout << res << endl;
	return 0;
}
*/