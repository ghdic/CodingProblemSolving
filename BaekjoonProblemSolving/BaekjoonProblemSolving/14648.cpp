/*
https://www.acmicpc.net/problem/14648

&Title
14648번 - 쿼리 맛보기

&Question
어떤 문제에 비슷한 형태의 질문이 여러 개 주어지는
문제를 쿼리 문제라고 부른다. 쿼리 문제는 쿼리가 주어진 순서대로
실행해서 해결할 수도 있지만, 그것이 불가능하거나 조건이 맞는 경우에는
쿼리의 순서를 임의로 바꿔서 더 편하게 해결할 수도 있다.
우리는 예선 문제에 쿼리에 대한 설명이 등장했기 때문에 본선
문제에 쿼리 문제가 나올 것이라는 예상을 쉽게 해볼 수
있다.이 문제에서는 길이 n의 수열과 q개의 쿼리가 주어진다. 주어지는
쿼리의 종류는 다음과 같다.1 a b : [a, b]
구간의 합을 구해서 출력하고, a번째 숫자와 b번째 숫자를 서로
스왑(swap) 한다.2 a b c d : [a, b]
구간의 합에서 [c, d] 구간의 합을 뺀 값을 출력한다.[a,
b] 구간의 합이란, 수열의 a~b번째 숫자를 모두 더한 값을
의미한다.

&Input
첫째 줄에 수열의 길이를 뜻하는 n(1≤n≤1,000)과 쿼리의 개수를
뜻하는 q(1≤q≤10,000)가 주어진다. 둘째 줄에 길이 n의 수열이 하나의
공백을 사이에 두고 주어진다. 수열의 각 숫자들은 모두 int형
범위 이내이다. 이후 셋째 줄 부터 q개의 줄에 걸쳐
쿼리가 주어진다. 쿼리의 형식은 “1 a b” 또는 “2
a b c d”이다. a, b, c, d는 n보다
작거나 같은 자연수이며, a≤b, c≤d임이 보장된다.

&Output
주어진 쿼리의 출력값을 q개의 줄에 걸쳐 출력한다.

&Example
-input
5 2
3 5 -2 3 -12
2 1 3 2 4
1 2 5

-output
0
-6

-input
7 3
12 5 -1 0 -4 3 -10
1 2 7
2 1 4 2 3
2 1 7 3 4

-output
-7
12
6


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segmentTree
{
	//배열의 길이
	int n;
	//각 구간의 부분합
	vector<long long> pSum;
	segmentTree(const vector<long long>& array)
	{
		n = array.size();
		pSum.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	//node 노드가 array[left...right] 배열을 표현
	//node를 루트로 하는 서브트리 초기화
	long long init(const vector<long long>& array, int left, int right, int node)
	{
		if (left == right)
			return pSum[node] = array[left];
		int mid = (left + right) / 2;
		long long leftSubTree = init(array, left, mid, node * 2);
		long long rightSubTree = init(array, mid + 1, right, node * 2 + 1);
		return pSum[node] = leftSubTree + rightSubTree;
	}
	//node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때
	//이 범위와 array[left...right]의 교집합
	long long query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		//두 구간이 겹치지 않으면 무시
		if (right < nodeLeft || nodeRight < left)
			return 0;
		//node가 표현하는 범위가 array[left..right]에 완전히 포함
		if (left <= nodeLeft && nodeRight <= right)
			return pSum[node];

		//양쪽 구간을 나눠서 풀고 결과를 합친다
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node * 2, nodeLeft, mid) + query(left, right, node * 2 + 1, mid + 1, nodeRight);
	}

	long long query(int left, int right)
	{
		return query(left - 1, right - 1, 1, 0, n - 1);
	}

	//array[index]=newValue로 바뀌었을 떄 node를 루트로 하는 구간트리 갱신
	long long update(int index, int newValue, int node, int nodeLeft, int nodeRight)
	{
		if (index < nodeLeft || nodeRight < index)
			return pSum[node];

		if (nodeLeft == nodeRight)
			return pSum[node] = newValue;

		int mid = (nodeLeft + nodeRight) / 2;
		return pSum[node] = update(index, newValue, node * 2, nodeLeft, mid) + update(index, newValue, node * 2 + 1, mid + 1, nodeRight);

	}
	long long update(int index, int newValue)
	{
		return update(index - 1, newValue, 1, 0, n - 1);
	}

};



int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 속도향상 위해
	int N, Q;
	cin >> N >> Q;

	vector<long long> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	segmentTree seg(v);

	for (int i = 0; i < Q; i++)
	{
		int op;
		cin >> op;

		if (op == 1)
		{

			int a, b;
			cin >> a >> b;
			cout << seg.query(a, b) << "\n";
			swap(v[a - 1], v[b - 1]);
			//update
			seg.update(a, v[a - 1]);
			seg.update(b, v[b - 1]);
		}
		else
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << seg.query(a, b) - seg.query(c, d) << "\n";
		}
	}
	return 0;
}
*/