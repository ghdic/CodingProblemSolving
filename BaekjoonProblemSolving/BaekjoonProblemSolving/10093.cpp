/*
https://www.acmicpc.net/problem/10093

&Title
10093번 - 숫자

&Question
두 양의 정수가 주어졌을 때, 두 수 사이에 
있는 정수를 모두 출력하는 프로그램을 작성하시오. 

&Input
두 정수 A와 B가 주어진다. (1 ≤ A, 
B ≤ 1015, A와 B의 차이는 최대 100,000) 

&Output
첫째 줄에 두 수 사이에 있는 수의 개수를 
출력한다.둘째 줄에는 두 수 사이에 있는 수를 오름차순으로 출력한다. 


&Example
-input
8 14

-output
5
9 10 11 12 13


*/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b;
	cin >> a >> b;
	if (b < a)
		swap(a, b);
	if (a == b) {
		cout << 0;
	}
	else {
		cout << (b - a - 1) << '\n';
		for (long long i = a + 1; i < b; ++i)
			cout << i << ' ';
	}
	return 0;
}
*/