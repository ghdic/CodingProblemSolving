/*
https://www.acmicpc.net/problem/10775

&Title
10775번 - 공항

&Question
오늘은 신승원의 생일이다.박승원은 생일을 맞아 신승원에게 인천국제공항을 선물로 
줬다.공항에는 G개의 게이트가 있으며 각각은 1에서 G까지의 번호를 가지고 
있다.공항에는 P개의 비행기가 순서대로 도착할 예정이며, 당신은 i번째 비행기를 
1번부터 gi (1 ≤ gi ≤ G) 번째 게이트중 
하나에 영구적으로 도킹하려 한다. 비행기가 도킹된 게이트에는 다른 비행기가 
도착할 수 없다.이렇게 공항을 운영할 경우 간혹 비행기가 어떤 
곳에도 도킹하지 못하는 사고가 발생한다. 이러한 사고가 일어나면 공항의 
평판이 급속히 나빠져, 이후 어떤 비행기도 도착하지 않으려 할 
것이다.신승원은 가장 많은 비행기를 공항에 도킹시켜서 박승원을 행복하게 하고 
싶어한다. 승원이는 비행기를 최대 몇 대 도킹시킬 수 있는가? 


&Input
첫 번째 줄에는 게이트의 수 G (1 ≤ 
G ≤ 105)가 주어진다.두 번째 줄에는 비행기의 수 P 
(1 ≤ P ≤ 105)가 주어진다.이후 P개의 줄에 gi 
(1 ≤ gi ≤ G) 가 주어진다. 

&Output
승원이가 도킹시킬 수 있는 최대의 비행기 수를 출력한다. 


&Example
-input
4
3
4
1
1

-output
2

-input
4
6
2
2
3
3
4
4

-output
3


*/

/*
#include <iostream>
using namespace std;
const int MAXG = 1e5 + 1;

int g, p, parent[MAXG];

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	parent[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> g;
	cin >> p;
	int res = 0;
	for (int i = 1; i <= g; ++i)
		parent[i] = i;
	while (p--) {
		int a;
		cin >> a;
		int dock = find(a);
		if (dock != 0) {
			merge(dock, dock - 1);
			++res;
		}
		else break;
	}
	cout << res << endl;
	return 0;
}
*/