/*
https://www.acmicpc.net/problem/3052

&Title
나머지
&Question
두 자연수 A와 B가 있을 때, A%B는 A를 B로 나눈 나머지 이다. 예를 들어, 7, 14, 27, 38을 3으로 나눈 나머지는 1, 2, 0, 2이다.

수 10개를 입력받은 뒤, 이를 42로 나눈 나머지를 구한다. 그 다음 서로 다른 값이 몇 개 있는지 출력하는 프로그램을 작성하시오.
&Input
첫째 줄부터 열번째 줄 까지 숫자가 한 줄에 하나씩 주어진다. 이 숫자는 1,000보다 작거나 같고, 음이 아닌 정수이다.
&Output
첫째 줄에, 42로 나누었을 때, 서로 다른 나머지가 몇 개 있는지 출력한다.
&Example
-input
39
40
41
42
43
44
82
83
84
85
-output
6
*/

/*
#include <iostream>
using namespace std;

int main() {
	int N;
	bool check[42];
	for (int i = 0; i < 42; i++)
		check[i] = false;
	for (int i = 0; i < 10; i++) {
		cin >> N;
		check[N % 42] = true;
	}
	int cnt = 0;
	for (int i = 0; i < 42; i++)
		if (check[i] == true)cnt++;
	cout << cnt << endl;
	return 0;
}
*/