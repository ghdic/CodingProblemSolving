/*
https://www.acmicpc.net/problem/5676

&Title
5676번 - 음주 코딩

&Question
오늘은 ACM-ICPC 대회 전 날이다. 상근이는 긴장을 풀기 
위해서 팀원들과 근처 술집으로 갔다.상근이와 친구들은 다음 날 있을 
대회를 연습하기 위해서 작은 게임을 하기로 했다.먼저, 선영이는 상근이에게 
총 N개의 정수로 이루어진 수열 X1, X2, ... XN을 
적어준다. 게임은 총 K번 라운드로 이루어져있고, 매 라운드마다 선영이는 
상근이에게 명령을 하나씩 내린다. 명령은 아래와 같이 두 가지가 
있다.변경: 이 명령은 친구가 수열의 한 값을 바꾸고 싶을 
때 사용한다.곱셈: 선영이는 상근이에게 i와 j를 말한다. 상근이는 Xi 
× Xi+1 × ... × Xj-1 × Xj 의 
값이 양수인지, 음수인지, 0인지를 대답한다.곱셈 명령에서 상근이가 대답을 잘못했을 
때의 벌칙은 소주 한 잔이다. 상근이는 갑자기 대회가 걱정되기 
시작했다. 또, 상근이는 발머의 피크 이론을 증명하고 싶지 않다.다행히 
선영이는 상근이에게 노트북 사용을 허락했다. 상근이는 자신의 수학 실력보다 
코딩 실력을 더 믿는다.상근이를 돕는 프로그램을 작성하시오. 

&Input
입력은 여러 개의 테스트 케이스로 이루어져 있다.각 테스트 
케이스의 첫째 줄에는 수열의 크기 N과 게임의 라운드 수 
K가 주어진다. (1 ≤ N, K ≤ 105)둘째 줄에는 
총 N개의 숫자 Xi가 주어진다. (-100 ≤ Xi ≤ 
100)다음 K개 줄에는 선영이가 내린 명령이 주어진다. 명령은 C 
또는 P로 시작한다.C로 시작하는 명령은 변경 명령이고, 그 다음에 
i와 V가 주어진다. Xi를 V로 변경하는 명령이다. (1 ≤ 
i ≤ N, -100 ≤ V ≤ 100)P로 시작하는 
명령은 곱셈 명령이고, 그 다음에 i와 j가 주어진다. (1 
≤ i ≤ j ≤ N)각 테스트 케이스에 곱셈 
명령은 항상 한 번 이상있다. 

&Output
각 테스트 케이스마다 곱셈 명령의 결과를 한 줄에 
모두 출력하면 된다. 출력하는 i번째 문자는 i번째 곱셈 명령의 
결과이다. 양수인 경우에는 +, 음수인 경우에는 -, 영인 경우에는 
0을 출력한다. 

&Example
-input
4 6
-2 6 0 -1
C 1 10
P 1 4
C 3 7
P 2 2
C 4 -5
P 1 4
5 9
1 5 -2 4 3
P 1 2
P 1 5
C 4 -5
P 1 5
P 4 5
C 3 0
P 1 5
C 4 -5
C 4 -5

-output
0+-
+-+-0


*/

/*
#include <iostream>
using namespace std;
const int MAXN = 100001;

int n, m;
int tree[MAXN * 4], node[MAXN];

int init(int index, int start, int end) {
	if (start == end)
		return tree[index] = node[start];
	else {
		int mid = (start + end) >> 1;
		return tree[index] = init(index * 2, start, mid) *
			init(index * 2 + 1, mid + 1, end);
	}
}

int update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = value;
	else {
		int mid = (start + end) >> 1;
		return tree[index] = update(index * 2, target, value, start, mid) *
			update(index * 2 + 1, target, value, mid + 1, end);
	}
}

int query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) >> 1;
	return query(index * 2, left, right, start, mid) * query(index * 2 + 1, left, right, mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			cin >> node[i];
			if (node[i] > 0)
				node[i] = 1;
			else if (node[i] < 0)
				node[i] = -1;
		}
		init(1, 1, n);
		char c;
		int i, j;
		while (m--) {
			cin >> c >> i >> j;
			if (c == 'C') {
				if (j > 0)
					j = 1;
				else if (j < 0)
					j = -1;
				update(1, i, j, 1, n);
			}
			else {
				int res = query(1, i, j, 1, n);
				if (res == 0)
					cout << '0';
				else if (res == 1)
					cout << '+';
				else
					cout << '-';
			}
		}
		cout << '\n';
	}
	return 0;
}
*/