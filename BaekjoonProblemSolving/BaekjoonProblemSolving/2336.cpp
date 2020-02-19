/*
https://www.acmicpc.net/problem/2336

&Title
2336번 - 굉장한 학생

&Question
N명의 학생이 참여하여 세 번의 시험을 치렀다. N명의 
학생들은 세 번의 시험에 모두 응시하였다. 조교는 각각의 시험에서 
같은 등수의 학생이 한 명도 없도록 성적을 매겼다.A라는 학생이 
B라는 학생보다 세 번의 시험에서 모두 성적이 좋다면, A가 
B보다 '대단하다'고 한다. 또, C라는 학생보다 '대단한' 학생이 한 
명도 없으면, C를 '굉장하다'고 한다.세 번의 시험에서 각 학생의 
성적이 주어졌을 때, '굉장한' 학생의 수를 구하는 프로그램을 작성하시오. 


&Input
첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다. 
다음 세 개의 줄에는 각 시험에서 1등인 학생부터 N등인 
학생이 순서대로 주어진다. 학생의 번호는 1부터 N까지 매겨져 있다. 


&Output
첫째 줄에 '굉장한' 학생의 수를 출력한다. 

&Example
-input
10
2 5 3 8 10 7 1 6 9 4
1 2 3 4 5 6 7 8 9 10
3 8 7 10 5 4 1 2 6 9

-output
4


*/

/*
n명의 학생이 세번의 시험을 치름
같은 등수 없게 성적을 매김
A라는 학생이 B라는 학생보다 세 성적다 좋다면 "대단하다"
C학생보다 "대단하다"라는 학생이 1명도 없으면 "굉장하다"라고 한다.

유니온 파인드를 사용하면 어떨까?? -> 
집합이라고 하기에는 상하관계가 분명하구 O(n^2)임.. 50만 * 50만 = 2500억;;
-O(nlogn)인 세그먼트트리를 써야함

문제는 어떻게 적용할꺼냐는건데.. 세그트리는 각 구간에 연산인 최대, 최소, 합, 곱 등을 반환할텐데...
이런거로 굉장하다인 학생의 수는 얻을 수도 없을거구..

첫번째 원소는 정렬로 순위 정할 수 있고

세그트리로 학생들 순위대로 넣어준다? (K번째성적, K+1번째성적)해서 K번째 성적
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXN = 500001;
const int INF = 1e9;

int n;
vector<vector<int>> score;
int tree[MAXN * 4];

int update(int index, int target, int value, int start, int end) {
	if (target < start || target > end)
		return tree[index];
	if (start == end)
		return tree[index] = value;
	else {
		int mid = (start + end) / 2;
		return tree[index] = min(update(index * 2, target, value, start, mid),
			update(index * 2 + 1, target, value, mid + 1, end));
	}
}

int query(int index, int left, int right, int start, int end) {
	if (left > end || right < start)
		return INF;
	if (left <= start && end <= right)
		return tree[index];
	int mid = (start + end) / 2;
	return min(query(index * 2, left, right, start, mid),
		query(index * 2 + 1, left, right, mid + 1, end));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	score.resize(n+1);
	for (int i = 1; i <= n; ++i)
		score[i].resize(3);
	int t;
	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> t;
			score[t][i] = j; // 해당 학생의 등수 적어줌
		}
	}
	sort(score.begin(), score.end());
	fill(&tree[0], &tree[n * 4], INF);

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		// 첫번째 시험 순서대로 정렬했으니 순서대로 비교(뒤에 있으면 늦게 업데이트되므로 두번째, 세번째만 비교해주면됨)
		// 쿼리로 두번째 시험의 1~score[i][1]등의 최소 세번째 시험 등수를 받아옴
		if (query(1, 1, score[i][1], 1, n) > score[i][2])
			++res;
		// 두번째 시험 등수에 세번째 시험 등수를 업데이트해줌(1~score[i][1] 쿼리 던질꺼기 때문에)
		update(1, score[i][1], score[i][2], 1, n);
	}
	cout << res << endl;
	return 0;
}
*/