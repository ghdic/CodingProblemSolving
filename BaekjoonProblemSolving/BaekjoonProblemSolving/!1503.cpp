/*
https://www.acmicpc.net/problem/1503

&Title
1503번 - 세 수 고르기

&Question
M개의 자연수로 이루어진 집합 S와 자연수 N이 주어진다.S에 
속하지 않는 자연수 x, y, z를 골라서, |N - 
xyz|의 최솟값을 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 N(1 ≤ N ≤ 1,000)과 집합 
S의 크기 M(0 ≤ M ≤ 50)이 주어진다. 둘째 
줄에는 집합 S에 들어있는 수가 주어진다. 집합에 들어있는 수는 
1,000보다 작거나 같은 자연수이고, 공백으로 구분되어져 있다. 또, 중복되는 
수는 없다.집합의 크기가 0인 경우에는 둘째 줄은 없다. 

&Output
첫째 줄에 |N - xyz|의 최솟값을 출력한다. 

&Example
-input
4 2
2 4

-output
1

-input
10 1
1

-output
2

-input
10 2
1 2

-output
17


*/

/*
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, res = 2e9;
bool arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int a;
	while(m--) {
		cin >> a;
		arr[a] = true;
	}
	for (int i = 1; i <= 1000; ++i) {
		if (arr[i])continue;
		for (int j = i; j <= 1000; ++j) {
			if (arr[j])continue;
			if (n < i * j)break;
			for (int k = j; k <= 1000; ++k) {
				if (arr[k])continue;
				a = i * j * k;
				res = min(res, abs(n - a));
				if (n < a)break;
			}
		}
	}
	cout << res << endl;
	return 0;
}
*/