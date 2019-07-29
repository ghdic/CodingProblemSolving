/*
https://www.acmicpc.net/problem/5419

&Title
5419번 - 북서풍

&Question
강한 북서풍이 불고 있다. 이 뜻은 동쪽과 남쪽 
사이의 모든 방향으로 항해할 수 있다는 뜻이다. 북쪽이나 서쪽으로 
항해하는 것은 불가능하다.작은 섬이 여러 개 있는 바다가 있다. 
섬은 좌표 평면의 한 점으로 나타낼 수 있다. y 
좌표가 증가하는 방향은 북쪽, x좌표가 증가하는 방향은 동쪽이다. 북서풍을 
타고 항해할 수 있는 섬의 쌍의 수를 구하는 프로그램을 
작성하시오. 

&Input
첫째 줄에 테스트 케이스의 개수가 주어진다.각 테스트 케이스의 
첫째 줄에는 섬의 수 n (1 ≤ n ≤ 
75000)이 주어진다. 다음 n개 줄에는 각 섬의 좌표 xi, 
yi가 주어진다. 두 섬의 좌표가 같은 경우는 없다. (-109 
≤ xi, yi ≤ 109) 

&Output
각 테스트 케이스에 대해서, 북서풍을 타고 항해할 수 
있는 섬의 쌍의 수를 출력한다. 

&Example
-input
2
4
-10 -10
-10 10
10 -10
10 10
3
1 3
2 2
3 1

-output
5
3


*/

/*
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
const int SIZE = 1<<18;
typedef pair<int, int> P;
struct SegMentTree {
	int arr[SIZE];
	void init() {
		fill(arr, arr + SIZE, 0);
	}
	// a번째 리프 노드를 1 증가시킴
	void increase(int a) {
		a += SIZE / 2;
		while (a > 0) {
			++arr[a];
			a /= 2;
		}
	}
	// [s, e) 구간합
	int sum(int s, int e) {
		return sum(s, e, 1, 0, SIZE / 2);
	}
	int sum(int s, int e, int node, int ns, int ne) {
		if (e <= ns || ne <= s)return 0;
		if (s <= ns && ne <= e)return arr[node];
		int mid = (ns + ne) / 2;
		return sum(s, e, node * 2, ns, mid) + sum(s, e, node * 2 + 1, mid, ne);
	}
};

P p[75000];
int newY[75000];
SegMentTree st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		st.init();
		int n, range = 0;
		cin >> n;
		int x, y;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			p[i] = P(x, y);
		}

		// 점들을 y 좌표 순으로 정렬
		// 처음보는 문법... [] 쓰고 하는건 머지..?
		sort(p, p + n, [](P& a, P& b) {
			return a.second < b.second;
			});
		// 서로 구분되는 y좌표 개수를 세며 y좌표 재설정ㅈ
		
		for (int i = 0; i < n; ++i) {
			if (i > 0 && p[i].second != p[i - 1].second)++range;
			newY[i] = range;
		}
		for (int i = 0; i < n; ++i)
			p[i].second = newY[i];
		// 점들을 다시 x좌표 순으로, x좌표가 같다면 y좌표가 작아지는 순으로 정렬
		sort(p, p + n, [](P& a, P& b) {
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
			});

		// 점들을 차례로 훑으면서 이 점으로 항해 할 수 있는 점 개수 세기
		long long result = 0;
		for (int i = 0; i < n; ++i) {
			result += st.sum(p[i].second, SIZE / 2);
			st.increase(p[i].second);
		}
		cout<<result<<endl;
	}
}
*/