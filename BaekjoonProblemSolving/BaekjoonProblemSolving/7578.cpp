/*
https://www.acmicpc.net/problem/7578

&Title
7578번 - 공장

&Question
어떤 공장에는 2N개의 기계가 2열에 걸쳐 N개씩 배치되어 
있다. 이 2개의 열을 각각 A열과 B 열이라고 부른다. 
A열에 있는 N개의 기계는 각각이 B열에 있는 N개의 기계와 
하나씩 짝을 이루어 케이블로 연결되어 있다. 즉, A열의 임의의 
기계는 B열의 유일한 기계와 케이블로 연결되어 있고, B열의 임의의 
기계는 A열의 유일한 기계와 케이블로 연결되어 있다또한, 각 기계에는 
식별번호가 붙어있으며, 짝이 맺어진 기계끼리는 같은 식별번호가 붙어있다. 즉, 
각 열에 있는 N개의 기계끼리는 서로 다른 식별번호를 가지고 
있으며, 반대쪽 열에 있는 같은 식별번호를 가진 기계와 케이블로 
이어져 있다.공장 작업의 효율성을 위해 기계들은 짝을 맺은 순서대로 
배치되지 않으며, 필요에 따라 각 열의 기계들의 순서를 바꾼 
바람에 케이블은 마구 엉켜있는 상태이다. 이렇게 엉켜버린 케이블은 잦은 
고장의 원인이 되기 때문에, 기계의 위치를 바꾸지 않은 상태에서 
케이블을 두 기계를 잇는 직선의 형태로 만들기로 했다.예를 들어, 
위의 그림과 같이 N = 5이고, A열에 위치한 기계의 
식별번호가 순서대로 132, 392, 311, 351, 231이고 B열에 위치한 
기계의 식별번호가 순서대로 392, 351, 132, 311, 231이라면 케이블들의 
교차 횟수 혹은 서로 교차하는 케이블 쌍의 개수는 3이 
된다.정수 N과 A열에 위치한 기계, B열에 위치한 기계의 식별번호가 
각각 순서대로 주어질 때에 서로 교차하는 케이블 쌍의 개수를 
정확하게 세어 출력하는 프로그램을 작성하시오. 

&Input
입력은 세 줄로 이루어져 있다. 첫 줄에는 정수 
N이 주어지며, 두 번째 줄에는 A열에 위치한 N개 기계의 
서로 다른 식별번호가 순서대로 공백문자로 구분되어 주어진다. 세 번째 
줄에는 B열에 위치한 N개의 기계의 식별번호가 순서대로 공백문자로 구분되어 
주어진다.단, 1 ≤ N ≤ 500,000이며, 기계의 식별번호는 모두 
0 이상 1,000,000 이하의 정수로 주어진다 

&Output
여러분은 읽어 들인 2N개의 기계의 배치로부터 서로 교차하는 
케이블 쌍의 개수를 정수 형태로 한 줄에 출력해야 한다. 


&Example
-input
5
132 392 311 351 231
392 351 132 311 231

-output
3


*/

/*
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAXN = 500000;

int n;
unordered_map<int, int> um;
int node[MAXN + 1];
long long tree[MAXN * 4];

void update(int index, int target, int diff, int start, int end) {
	if (target < start || target > end)
		return;
	tree[index] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		update(index * 2, target, diff, start, mid);
		update(index * 2 + 1, target, diff, mid + 1, end);
	}
}

long long query(int index, int left, int right, int start, int end) {
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
	cin >> n;
	int m;
	for (int i = 1; i <= n; ++i) {
		cin >> m;
		um[m] = i;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> m;
		node[i] = um[m];
	}

	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		res += query(1, node[i] + 1, n, 1, n);
		update(1, node[i], 1, 1, n);
	}
	cout << res << endl;
	return 0;
}
*/