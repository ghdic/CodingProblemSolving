/*
https://www.acmicpc.net/problem/1717

&Title
1717번 - 집합의 표현스페셜 저지

&Question
초기에 {0}, {1}, {2}, ... {n} 이 각각 
n+1개의 집합을 이루고 있다. 여기에 합집합 연산과, 두 원소가 
같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.집합을 표현하는 
프로그램을 작성하시오. 

&Input
첫째 줄에 n(1≤n≤1,000,000), m(1≤m≤100,000)이 주어진다. m은 입력으로 주어지는 
연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 합집합은 
0 a b의 형태로 입력이 주어진다. 이는 a가 포함되어 
있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 두 
원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a 
b의 형태로 입력이 주어진다. 이는 a와 b가 같은 집합에 
포함되어 있는지를 확인하는 연산이다. a와 b는 n 이하의 자연수또는 
0이며 같을 수도 있다. 

&Output
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 
결과를 출력한다. (yes/no 를 출력해도 된다) 

&Example
-input
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

-output
NO
NO
YES


*/

/*
#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

int find(int num) {
	if (arr[num] == num)return num;
	return arr[num] = find(arr[num]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)return;

	if (u < v)
		arr[v] = u;
	else
		arr[u] = v;
}

bool isSameparent(int a, int b) {
	a = find(a);
	b = find(b);

	return a == b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; ++i)
		arr[i] = i;
	int c, a, b;
	for (int i = 0; i < m; ++i) {
		cin >> c >> a >> b;

		if (c == 0) {
			merge(a, b);
		}
		else {
			if (isSameparent(a, b))cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}
*/