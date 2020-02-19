/*
https://www.acmicpc.net/problem/2042

&Title
2042번 - 구간 합 구하기

&Question
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 
변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 
한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 
바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 
것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 
3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다. 

&Input
첫째 줄에 수의 개수 N(1 ≤ N ≤ 
1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K 
≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 회수이고, 
K는 구간의 합을 구하는 회수이다. 그리고 둘째 줄부터 N+1번째 
줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 
세 개의 정수 a, b, c가 주어지는데, a가 1인 
경우 b번째 수를 c로 바꾸고 a가 2인 경우에는 b번째 
수부터 c번째 수까지의 합을 구하여 출력하면 된다.a가 1인 경우 
c는 long long 범위를 넘지 않는다. 

&Output
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 
단, 정답은 long long 범위를 넘지 않는다. 

&Example
-input
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
-output
17
12

*/
/*
// 세그먼트 트리 이용
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int n, m, k; // 1~1,000,000 수의 개수 1~10,000 변경회수 1~10,000 구간합 구하는 회수
ll A[1000001];

class SegmentTree {
private:
	
	ll* A;
	ll* nodes;

	ll init(int index, int start, int end) {
		if (start == end)
			return nodes[index] = A[start]; // leaf 노드
		else
			return nodes[index] = init(2 * index, start, (start + end) / 2) + init(2 * index + 1, (start + end) / 2 + 1, end); // 왼쪽, 오른쪽 노드로 내려감
		
	}

public:
	SegmentTree(int N, ll* A) { // 초기화 선언
		int h = (int)ceil(log2(N)); // ceil 올림함수, 높이를 구함
		int node_size = 1 << (h + 1); // == 2^(h+1) 공간을 할당함
		nodes = new ll[node_size+1];

		this->A = A;
		init(1, 1, N);
	}
	~SegmentTree() {
		delete[] nodes;
	}

	ll getSum(int index, int start, int end, int left, int right) {
		// 구하려는 범위가 밖에 있는 경우
		if (left > end || right < start)return 0;
		if (left <= start && right >= end)return nodes[index];

		int mid = (start + end) / 2;
		return getSum(index * 2, start, mid, left, right) + getSum(index * 2 + 1, mid + 1, end, left, right);
	}

	void update(int changed_index, ll diff, int index, int start, int end) {
		if (changed_index < start || changed_index > end)return;
		nodes[index] += diff;
		if (start != end) {
			int mid = (start + end) / 2;
			update(changed_index, diff, index * 2, start, mid);
			update(changed_index, diff, index * 2 + 1, mid + 1, end);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	int c = m + k;

	SegmentTree st(n, A);

	while (c--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			ll c;
			cin >> c;
			ll diff = c - A[b];
			A[b] = c;
			st.update(b, diff, 1, 1, n);
		}
		else if (a == 2) {
			int c;
			cin >> c;
			cout << st.getSum(1 , 1, n, b, c) << "\n";
		}
	}
	return 0;
}
*/