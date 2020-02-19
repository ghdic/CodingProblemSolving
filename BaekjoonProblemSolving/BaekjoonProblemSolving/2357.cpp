/*
https://www.acmicpc.net/problem/2357

&Title
2357번 - 최솟값과 최댓값

&Question
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, 
a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수, 또는 
제일 큰 정수를 찾는 것은 어려운 일이 아니다. 하지만 
이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 
100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 
보자.여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 
a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 
최소, 최댓값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 
갖는다. 

&Input
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 
N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 
주어진다. 

&Output
M개의 줄에 입력받은 순서대로 각 a, b에 대한 
답을 최솟값, 최댓값 순서로 출력한다. 

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
5 100
38 100
20 81
5 81


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e9;

struct res {
	int Max, Min;
};
int n, m;
int minTree[400000], maxTree[400000];
int arr[100001];

void init(int index, int start, int end) {
	if (start == end)
		minTree[index] = maxTree[index] = arr[start];
	else {
		int mid = (start + end) / 2;
		init(index * 2, start, mid);
		init(index * 2 + 1, mid + 1, end);
		minTree[index] = min(minTree[2 * index], minTree[2 * index + 1]);
		maxTree[index] = max(maxTree[2 * index], maxTree[2 * index + 1]);
	}
}

res query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return { 0, MAX };
	if (left <= start && end <= right)
		return { maxTree[index], minTree[index] };
	else {
		int mid = (start + end) / 2;
		res l = query(index * 2, left, right, start, mid),
			r = query(index * 2 + 1, left, right, mid + 1, end);
		return { max(l.Max, r.Max), min(l.Min, r.Min) };
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	init(1, 1, n);
	int a, b;
	while (m--) {
		cin >> a >> b;
		res result = query(1, a, b, 1, n);
		cout << result.Min << ' ' << result.Max << '\n';
	}
	return 0;
}
*/