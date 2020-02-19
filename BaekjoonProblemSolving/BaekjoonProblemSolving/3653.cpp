/*
https://www.acmicpc.net/problem/3653

&Title
3653번 - 영화 수집

&Question
상근이는 영화 DVD 수집가이다. 상근이는 그의 DVD 콜렉션을 
쌓아 보관한다.보고 싶은 영화가 있을 때는, DVD의 위치를 찾은 
다음 쌓아놓은 콜렉션이 무너지지 않게 조심스럽게 DVD를 뺀다. 영화를 
다 본 이후에는 가장 위에 놓는다.상근이는 DVD가 매우 많기 
때문에, 영화의 위치를 찾는데 시간이 너무 오래 걸린다. 각 
DVD의 위치는, 찾으려는 DVD의 위에 있는 영화의 개수만 알면 
쉽게 구할 수 있다. 각 영화는 DVD 표지에 붙어있는 
숫자로 쉽게 구별할 수 있다.각 영화의 위치를 기록하는 프로그램을 
작성하시오. 상근이가 영화를 한 편 볼 때마다 그 DVD의 
위에 몇 개의 DVD가 있었는지를 구해야 한다. 

&Input
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 
개수는 100개를 넘지 않는다.각 테스트 케이스의 첫째 줄에는 상근이가 
가지고 있는 영화의 수 n과 보려고 하는 영화의 수 
m이 주어진다. (1 ≤ n, m ≤ 100,000) 둘째 
줄에는 보려고 하는 영화의 번호가 순서대로 주어진다.영화의 번호는 1부터 
n까지 이며, 가장 처음에 영화가 쌓여진 순서는 1부터 증가하는 
순서이다. 가장 위에 있는 영화의 번호는 1이다. 

&Output
각 테스트 케이스에 대해서 한 줄에 m개의 정수를 
출력해야 한다. i번째 출력하는 수는 i번째로 영화를 볼 때 
그 영화의 위에 있었던 DVD의 개수이다. 상근이는 매번 영화를 
볼 때마다 본 영화 DVD를 가장 위에 놓는다. 

&Example
-input
2
3 3
3 1 1
5 3
4 4 5

-output
2 1 0
3 0 4


*/

/*
세그합을 이용해서 푸는 문제

*/

/*
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100001;
int n, m;
int node[MAXN * 2], tree[MAXN * 8];

int update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = value;
	int mid = (start + end) / 2;
	return tree[index] = update(index * 2, target, value, start, mid) +
		update(index * 2 + 1, target, value, mid + 1, end);
}

int query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return query(index * 2, left, right, start, mid) +
			query(index * 2 + 1, left, right, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(tree, 0, sizeof(tree));
		cin >> n >> m;
		// m+1 ~ n+m의 값 1로 업데이트
		for (int i = m + 1; i <= n + m; ++i) {
			update(1, i, 1, 1, n + m);
			node[i - m] = i;
		}
		int k, count = m; // count는 쌓을 위치
		for (int i = 0; i < m; ++i) {
			cin >> k;
			// 1(맨위)~해당카드 위치바로 위까지 개수 쿼리합
			cout << query(1, 1, node[k] - 1, 1, n + m) << ' ';
			// 현재 위치 카드 빼주고(0), 맨위에 카드 쌓아줌(1)
			update(1, node[k], 0, 1, n + m);
			node[k] = count--;
			update(1, node[k], 1, 1, n + m);
		}
		cout << '\n';
	}
	return 0;
}
*/