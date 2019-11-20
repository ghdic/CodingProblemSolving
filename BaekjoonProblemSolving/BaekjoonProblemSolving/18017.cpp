/*
https://www.acmicpc.net/problem/18017

&Title
18017번 - 총알의 속도스페셜 저지

&Question
철수는 총과 함께 과녁을 향해 초속 A미터로 달리고 
있다. 달리는 도중에 철수는 (자신을 기준으로) 초속 B미터로 나가는 
총알을 과녁 방향으로 발사 했다.이 때, 총알은 과녁을 향해 
초속 몇 미터로 날아가고 있는가? 

&Input
첫째 줄에 두 실수 A, B가 공백으로 구분되어 
소숫점 둘째자리까지 주어진다. (0 < A, B ≤ 108) 


&Output
총알은 과녁을 향해 초속 몇 미터로 날아가고 있는지를 
출력하여라.출력과 정답과의 차이가 10-9이하일 경우, 정답으로 판단한다. 

&Example
-input
1.23 4.56

-output
5.79


*/

/*
#include <iostream>
#define c 299792458.0
using namespace std;

int main() {
	int N;
	setbuf(stdout, NULL);
	ios::sync_with_stdio(false);
	long double a, b;
	cin >> a >> b;
	cout << fixed;
	cout.precision(10);
	cout << (a+b)/(1+(a*b)/(c*c)) << endl;
	return 0;
}
*/