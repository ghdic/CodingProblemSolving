/*
https://www.acmicpc.net/problem/2268

&Title
2268번 - 수들의 합

&Question
N개의 수 A[1], A[2], …, A[N] 이 주어졌을 
때, 함수 Sum(i, j)는 A[i]+A[i+1]+…+A[j]를 구하는 함수이다. (i>j일 경우에는 
A[j]+A[j+1]+...+A[i]) A가 주어졌을 때, Sum(i, j)를 구하는 것은 매우 
쉬운 문제이다. 이러한 (i, j)가 여러 개 주어졌을 때도 
별로 어려운 문제는 아니다.Sum함수와 더불어 Modify라는 함수를 정의하자. Modify(i, 
k)를 수행하면 A[i]=k가 되는 함수이다. Sum함수와 Modify 함수의 사용 
목록이 주어졌을 때, 이에 해당하는 연산을 하는 프로그램을 작성하시오. 
두 함수를 섞어서 사용할 수도 있다. 

&Input
첫째 줄에는 N(1≤N≤1,000,000), M(1≤M≤1,000,000)이 주어진다. M은 수행한 명령의 
개수이며 다음 M개의 줄에는 수행한 순서대로 함수의 목록이 주어진다. 
첫 번째 숫자는 어느 함수를 사용했는지를 나타내며, 0일 경우에는 
Sum 함수를, 1일 경우에는 Modify 함수를 나타낸다. 다음 두 
수는 각 함수의 인자 (i, j)나 (i, k)를 나타낸다. 
처음에는 A[1]=A[2]=…A[N]=0이다. Modify인 경우에 1 ≤ k ≤ 100,000 
이다. 

&Output
Sum 함수의 개수만큼 각 줄에 Sum 함수의 리턴값을 
출력한다. 

&Example
-input
3 5
0 1 3
1 1 2
1 2 3
0 2 3
0 1 3

-output
0
3
5


*/

/*
#include <iostream>
using namespace std;
const int MAX = 1000001;

int n, m;
long long tree[MAX * 4];
int node[MAX];

long long sum(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return sum(index * 2, left, right, start, mid) + sum(index * 2 + 1, left, right, mid + 1, end);
	}
}

void modify(int index, int target, int diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start == end) {
		node[target] += diff;
	}
	else{
		int mid = (start + end) / 2;
		modify(index * 2, target, diff, start, mid);
		modify(index * 2 + 1, target, diff, mid + 1, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int a, b, c;
	while (m--) {
		cin >> a >> b >> c;
		if (a == 0) {
			if(b > c)
				b ^= c ^= b ^= c;
			cout << sum(1, b, c, 1, n) << '\n';
		}
		else {
			int diff = c - node[b];
			modify(1, b, diff, 1, n);
		}
	}
	return 0;
}
*/