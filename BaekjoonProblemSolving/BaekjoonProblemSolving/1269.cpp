/*
https://www.acmicpc.net/problem/1269

&Title
1269번 - 대칭 차집합

&Question
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 
B가 있다. 이때, 두 집합의 대칭 차집합의 원소의 개수를 
출력하는 프로그램을 작성하시오. 두 집합 A와 B가 있을 때, 
(A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다. 예를 
들어, A = { 1, 2, 4 } 이고, 
B = { 2, 3, 4, 5, 6 } 
라고 할 때, A-B = { 1 } 이고, 
B-A = { 3, 5, 6 } 이므로, 대칭 
차집합의 원소의 개수는 1 + 3 = 4개이다. 

&Input
첫째 줄에 집합 A의 원소의 개수와 집합 B의 
원소의 개수가 빈 칸을 사이에 두고 주어진다. 둘째 줄에는 
집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 
원소가 빈 칸을 사이에 두고 각각 주어진다. 각 집합의 
원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 
넘지 않는다. 

&Output
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다. 

&Example
-input
3 5
1 2 4
2 3 4 5 6

-output
4

*/

/*
// 이거 왜 안됌? 교집합 구하고 한건데
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a, b, c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	c.resize(n < m ? m : n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	c.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin()), c.end());

	cout << n + m - c.size() * 2 << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> a;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int k;
	for (int i = 0; i < n; ++i) {
		cin >> k;
		a.insert(k);
	}
	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		cin >> k;
		if (a.count(k))++cnt;
	}
	cout << n + m - cnt * 2 << endl;
	return 0;
}
*/