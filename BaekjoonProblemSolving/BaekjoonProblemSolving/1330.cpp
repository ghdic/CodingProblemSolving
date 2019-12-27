/*
https://www.acmicpc.net/problem/1330

&Title
1330번 - 두 수 비교하기

&Question
두 정수 A와 B가 주어졌을 때, A와 B를 
비교하는 프로그램을 작성하시오. 

&Input
첫째 줄에 A와 B가 주어진다. A와 B는 공백 
한 칸으로 구분되어져 있다. 

&Output
첫째 줄에 다음 세 가지 중 하나를 출력한다.A가 
B보다 큰 경우에는 '>'를 출력한다.A가 B보다 작은 경우에는 '<'를 
출력한다.A와 B가 같은 경우에는 '=='를 출력한다. 

&Example
-input
1 2

-output
<

-input
10 2

-output
>

-input
5 5

-output
==


*/

/*
#include <iostream>
using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin >> a >> b;
	if (a > b)
		cout << '>' << endl;
	else if (a == b)
		cout << "==" << endl;
	else
		cout << '<' << endl;
	return 0;
}
*/