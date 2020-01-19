/*
https://www.acmicpc.net/problem/17353

&Title
17353번 - 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별

&Question
욱제의 은밀한 취미 중 하나는 매일 밤하늘을 감상하는 
것이다. 😓 욱제는 하늘의 별들이 다음과 같은 규칙들을 따르며 
떨어지는 걸 관찰했다.별이 떨어지는 위치는 N개의 점이다. 점은 순서대로 
1, 2, ..., N의 번호를 갖는다.매일 밤 별들은 1, 
2, ..., N의 연속한 부분 구간 [L, R]에 떨어진다.[L, 
R]에 별이 떨어지면, 각 점에는 순서대로 1, 2, ..., 
R-L+1개의 별이 떨어진다. 다시 말해, L에는 1개, L+1에는 2개, 
..., R에는 R-L+1개의 별이 떨어진다.욱제는 하늘에서 떨어지는 별들을 기록하다가 
잠이 들어버렸다!! 혹시나 했지만 역시나, 여러분은 욱제를 대신해 아래의 
쿼리를 수행해야 한다. (ㅎㅎ;; ㅈㅅ.. ㅋㅋ!!)1 L R: [L, 
R]에 별이 떨어진다. (1 ≤ L ≤ R ≤ 
N)2 X: 점 X에 떨어진 별의 개수의 합을 출력한다. 
(1 ≤ X ≤ N) 

&Input
첫째 줄에 별이 떨어지는 점의 개수 N이 주어진다. 
(1 ≤ N ≤ 105)둘째 줄에 욱제가 잠들기 전까지 
세어 놓은, 이미 떨어진 별들의 개수 A1, ..., AN이 
공백을 사이에 두고 주어진다. (0 ≤ A1, ..., AN 
≤ 106)셋째 줄에는 쿼리의 개수 Q가 주어진다. (1 ≤ 
Q ≤ 105)넷째 줄부터 Q개의 줄에는 쿼리가 한 줄에 
하나씩 주어진다. 

&Output
2번 쿼리에 대한 답을 한 줄에 하나씩 출력한다. 


&Example
-input
5
1 2 1 2 1
4
1 1 5
2 5
1 2 5
2 5

-output
6
10


*/

/*
#include <iostream>
using namespace std;

const int MAXN = 1e5;
struct info {
	long long val, cnt;
};
int n, m;
long long node[MAXN + 1];
info tree[MAXN * 4];

void init(int index, int start, int end) {
	if (start == end) {
		tree[index].val = node[start];
	}
	else {
		int mid = (start + end) / 2;
		init(index * 2, start, mid);
		init(index * 2 + 1, mid + 1, end);
	}
}

void update(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return;

	if (left <= start && end <= right) {
		tree[index].val += start - left + 1;
		tree[index].cnt++;
	}
	else {
		int mid = (start + end) / 2;
		update(index * 2, left, right, start, mid);
		update(index * 2 + 1, left, right, mid + 1, end);
	}
}

long long query(int index, int target, int start, int end) {
	if (target < start || target > end)
		return 0;
	
	if (start == end) {
		return tree[index].val;
	}
	else {
		int mid = (start + end) / 2;
		return query(index * 2, target, start, mid) +
			query(index * 2 + 1, target, mid + 1, end) +
			tree[index].val + tree[index].cnt * (target - start);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> node[i];
	init(1, 1, n);
	cin >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			update(1, b, c, 1, n);
		}
		else {
			cout << query(1, b, 1, n) << '\n';
		}
	}
	return 0;
}
*/