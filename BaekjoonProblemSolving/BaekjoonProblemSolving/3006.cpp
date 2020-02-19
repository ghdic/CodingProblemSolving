/*
https://www.acmicpc.net/problem/3006

&Title
3006번 - 터보소트

&Question
명우가 소트 알고리즘을 하나 발명했다. 이 알고리즘의 이름은 
터보소트이다. 터보소트는 1부터 N까지 총 N개의 수가 섞여있을 때만 
사용할 수 있으며, 다음과 같이 N단계로 이루어져 있다.첫 번째 
단계에서 숫자 1의 위치를 찾는다. 그 다음 바로 앞의 
숫자와 위치를 바꾸어가면서, 1이 제일 앞에 오게 바꾼다.두 번째 
단계에서는 숫자 N의 위치를 찾는다. 그 다음 바로 뒤의 
숫자와 위치를 바꾸어가면서, N이 제일 마지막에 오게 바꾼다.세 번째 
단계는 숫자 2의 위치를 찾은 후에, 바로 앞의 숫자와 
위치를 바꾸어가면서, 두 번째 위치에 오게 바꾼다.네 번째 단계는 
숫자 N-1의 위치를 찾은 다음에, 바로 뒤의 숫자와 위치를 
바꾸면서, 뒤에서 2번째 위치에 오게 바꾼다.다섯 번째 단계도 위와 
같은 식으로 하면 되고 이를 N번 반복하는 것이다.정리하면, 홀수번째 
단계이면, 아직까지 고르지 않은 숫자 중 제일 작은 수를 
고른 다음에, 그것을 인접한 숫자와 위치를 바꾸면서 올바른 위치로 
이동시키고, 짝수번째 단계일때는, 제일 큰 수를 고른 다음에 위치를 
이동시키는 것이다.명우는 이때, 각 단계에서 숫자의 위치를 몇 번 
바꾸는지 구하려고 한다.1부터 N까지 총 N개의 수로 이루어진 배열이 
주어졌을 때, 터보 소트의 각 단계에서, 숫자의 위치를 몇 
번씩 바꾸는지 출력하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 
100,000보다 작거나 같은 자연수이며, 배열의 크기이다.둘째 줄부터 N개의 줄에는 
1보다 크거나 같고, N보다 작거나 같은 수가 중복 없이 
주어진다. 이 숫자가 차례대로 배열에 포함되어 있는 수이다. 

&Output
각 단계에서 숫자의 위치를 몇 번 바꾸는지 출력한다. 
총 N줄을 출력해야 한다. 

&Example
-input
3
2
1
3

-output
1
0
0

-input
5
5
4
3
2
1

-output
4
3
2
1
0

-input
7
5
4
3
7
1
2
6

-output
4
2
3
0
2
1
0


*/

/*
n단계로 이루어진 터보소트라는게 있다.
1. 1의 위치를 찾고 바로 앞의 숫자와 위치를 바꾸어 가며 1이 제일 앞으로
2. n을 찾고 n이 제일 마지막에 오게 바꿈
3. 2의 위치를 찾고 ~~
4. n-1을 찾고 ~~~
...
n번까지 이렇게 반복
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100001;

struct info {
	int num, index;

	bool operator < (const info& a) const {
		return this->num < a.num;
	}
};

int n;
int tree[MAXN * 4];
info node[MAXN];

int init(int index, int start, int end) {
	if (start == end) {
		return tree[index] = 1;
	}
	else {
		int mid = (start + end) / 2;
		return tree[index] = init(index * 2, start, mid) +
			init(index * 2 + 1, mid + 1, end);
	}
}

int update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = value;
	else {
		int mid = (start + end) / 2;
		return tree[index] = update(index * 2, target, value, start, mid) +
			update(index * 2 + 1, target, value, mid + 1, end);
	}
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
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> node[i].num;
		node[i].index = i;
	}
	sort(&node[0], &node[n]);
	init(1, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		if (i &	1) {
			int idx = n - i / 2 - 1;
			cout << query(1, node[idx].index, n - 1, 0, n - 1) - 1 << '\n';
			update(1, node[idx].index, 0, 0, n - 1);
		}
		else {
			int idx = i / 2;
			cout << query(1, 0, node[idx].index, 0, n - 1) - 1 << '\n';
			update(1, node[idx].index, 0, 0, n-1);
		}
	}
	return 0;
}
*/