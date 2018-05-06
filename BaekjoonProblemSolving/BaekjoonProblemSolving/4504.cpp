/*
https://www.acmicpc.net/problem/4504

&Title
4504번 - 배수 찾기

&Question
정수 n(0 < n < 1000)과 숫자 목록이 
주어졌을 때, 숫자 목록에 들어있는 숫자가 n의 배수인지 아닌지를 
구하는 프로그램을 작성하시오. 

&Input
첫째 줄에 n이 주어진다. 다음 줄부터 한 줄에 
한 개씩 숫자 목록에 들어있는 숫자가 주어진다. 이 숫자는 
0보다 크고, 10,000보다 작다. 숫자 목록은 0으로 끝난다. 

&Output
숫자 목록에 있는 숫자가 n의 배수일 경우 인지 
아닌지를 구한 뒤 예제 출력처럼 출력한다. 

&Example
-input
3
1
7
99
321
777
0

-output
1 is NOT a multiple of 3.
7 is NOT a multiple of 3.
99 is a multiple of 3.
321 is a multiple of 3.
777 is a multiple of 3.


*/

/*
#include <iostream>
using namespace std;

int main() {
	int N, a = -1;
	cin >> N;
	while (true) {
		cin >> a;
		if (a == 0)break;
		if (a%N == 0)cout << a << " is a multiple of " << N << "." << endl;
		else cout << a << " is NOT a multiple of " << N << "." << endl;
	}
	return 0;
}
*/