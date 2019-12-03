/*
https://www.acmicpc.net/problem/1629

&Title
1629번 - 곱셈

&Question
자연수 A를 B번 곱한 수를 알고 싶다. 단 
구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 
나머지를 구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 A, B, C가 빈 칸을 사이에 
두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 
자연수이다. 

&Output
첫째 줄에 A를 B번 곱한 수를 C로 나눈 
나머지를 출력한다. 

&Example
-input
10 11 12

-output
4

*/

/*
#include <iostream>
using namespace std;

long long a, b, c;

long long divide_conquer(int num) {
	if (num == 0)return 1;
	long long k = divide_conquer(num / 2);
	k = (k * k) % c;
	if (num & 1) {
		return (a * k) % c;
	}
	else {
		return k;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b >> c;
	cout << divide_conquer(b) << endl;
	return 0;
}
*/