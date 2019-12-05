/*
https://www.acmicpc.net/problem/1725

&Title
1725번 - 히스토그램

&Question
히스토그램에 대해서 알고 있는가? 히스토그램은 아래와 같은 막대그래프를 
말한다.각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 위 
그림의 경우 높이가 각각 2 1 4 5 1 
3 3이다.이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 
한다. 아래 그림의 빗금 친 부분이 그 예이다. 이 
직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.주어진 히스토그램에 
대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오. 

&Input
첫 행에는 N (1 ≤ N ≤ 100,000) 
이 주어진다. N은 히스토그램의 가로 칸의 수이다. 다음 N 
행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다. 

&Output
첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 
값은 20억을 넘지 않는다. 

&Example
-input
7
2
1
4
5
1
3
3

-output
8

*/

/*
// 스택 풀이
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int arr[1000002];

// top보다 높이가 높으면 계속 스택에 쌓는다. 그러고 현재 값보다 작을때까지 스택을 비워주며 검사한다
int get_max_rect() {
	int res = 0;
	stack<int> st;
	st.push(0);

	// n + 1 까지 하는 이유는 0과 비교하여 스택을 비워주기 위해서이다.
	for (int i = 1; i <= n + 1; ++i) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int height = arr[st.top()];
			st.pop();
			int width = i - st.top() - 1;

			res = max(res, height * width);
		}
		st.push(i);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	cout << get_max_rect() << endl;
	return 0;
}
*/

/*
// divide_conquer
#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000002];

int divide_conquer(int l, int r) {
	if (l == r)return arr[l];

	int mid = (l + r) / 2;
	int res = max(divide_conquer(l, mid), divide_conquer(mid + 1, r));
	int s = mid, e = mid + 1;
	int h = min(arr[s], arr[e]);
	res = max(res, h * (e - s + 1));
	while (s > l || e < r) {
		if (e < r && (s == l || arr[s - 1] < arr[e + 1]))
			h = min(h, arr[++e]);
		else
			h = min(h, arr[--s]);
		res = max(res, h * (e - s + 1));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	cout << divide_conquer(1, n) << endl;
}
*/