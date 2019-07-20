/*
https://www.acmicpc.net/problem/10868

&Title
10868번 - 최솟값

&Question
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, 
a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수를 찾는 
것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 
쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 
문제가 된다. 이 문제를 해결해 보자.여기서 a번째라는 것은 입력되는 
순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 
1번, 2번, 3번 정수 중에서 최솟값을 찾아야 한다. 각각의 
정수들은 1이상 1,000,000,000이하의 값을 갖는다. 

&Input
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 
N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 
주어진다. 

&Output
M개의 줄에 입력받은 순서대로 각 a, b에 대한 
답을 출력한다. 

&Example
-input
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10

-output
5
38
20
5


*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m; // 1~100000 정수개수 1~100000 (a,b)쌍의개수
ll A[100001];

class SegmentTree {
private:
	ll* A;
	ll* nodes;

	ll init(int index, int start, int end) {
		if (start == end)
			return nodes[index] = A[start];
		else
			return nodes[index] = min(init(2 * index, start, (start + end) / 2), init(2 * index + 1, (start + end) / 2 + 1, end));

	}

public:
	SegmentTree(int N, ll* A) {
		int h = (int)ceil(log2(N));
		int node_size = 1 << (h + 1);
		nodes = new ll[node_size];

		this->A = A;
		init(1, 1, N);
	}

	ll getMin(int index, int start, int end, int left, int right) {
		if (left > end || right < start)return 1000000001;
		if (left <= start && right >= end)return nodes[index];

		return min(getMin(index * 2, start, (start + end) / 2, left, right),getMin(index * 2 + 1, (start+end)/2+1, end, left, right));
	}

};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i < n + 1; ++i) {
		cin >> A[i];
	}
	SegmentTree st(n, A);
	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << st.getMin(1, 1, n, a, b) << "\n";
	}
	return 0;
}
*/