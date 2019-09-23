/*
https://www.acmicpc.net/problem/1822

&Title
1822번 - 차집합

&Question
몇 개의 자연수로 이루어진 두 집합 A와 B가 
있다. 집합 A에는 속하면서 집합 B에는 속하지 않는 모든 
원소를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에는 집합 A의 원소의 개수 n(A)와 집합 
B의 원소의 개수 n(B)가 빈 칸을 사이에 두고 주어진다. 
(1≤n(A), n(B)≤500,000)이 주어진다. 둘째 줄에는 집합 A의 원소가, 셋째 
줄에는 집합 B의 원소가 빈 칸을 사이에 두고 주어진다. 
하나의 집합의 원소는 2,147,483,647 이하의 자연수이며, 하나의 집합에 속하는 
모든 원소의 값은 다르다. 

&Output
첫째 줄에 집합 A에는 속하면서 집합 B에는 속하지 
않는 원소의 개수를 출력한다. 다음 줄에는 구체적인 원소를 빈 
칸을 사이에 두고 증가하는 순서로 출력한다. 집합 A에는 속하면서 
집합 B에는 속하지 않는 원소가 없다면 첫째 줄에 0만을 
출력하면 된다. 

&Example
-input
4 3
2 5 11 7
9 7 4
-output
3
2 5 11

*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> A, B, C;

int binarySearch(int target) {
	int st = 0, ed = m - 1;
	while (st <= ed) {
		int mid = (st + ed) / 2;
		if (B[mid] > target)
			ed = mid - 1;
		else if (B[mid] < target)
			st = mid + 1;
		else
			return B[mid];
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	A.resize(n); B.resize(m); C.resize(n);
	for (int i = 0; i < n; ++i)cin >> A[i];
	for (int i = 0; i < m; ++i)cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		if (!binarySearch(A[i])) {
			C[pos++] = A[i];
		}
	}
	if (pos == 0)
		cout << 0;
	else {
		cout << pos << '\n';
		cout << C[0];
		for (int i = 1; i < pos; ++i)
			cout << ' ' << C[i];
	}
	return 0;
}
*/