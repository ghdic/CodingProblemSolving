/*
https://www.acmicpc.net/problem/3009

&Title
네번째 점
&Question
세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.
&Input
세 점의 좌표가 한 줄에 하나씩 주어진다. 좌표는 1보다 크거나 같고, 1000보다 작거나 같은 정수이다.
&Output
직사각형의 네번째 점의 좌표를 출력한다.
&Example
-input
30 20
10 10
10 20
-output
30 10
*/

/*
#include <iostream>
using namespace std;

int main() {
	int	x[3], y[3], X, Y;

	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	if (x[0] == x[1])X = x[2];
	else if (x[0] == x[2])X = x[1];
	else if (x[1] == x[2])X = x[0];

	if (y[0] == y[1])Y = y[2];
	else if (y[0] == y[2])Y = y[1];
	else if (y[1] == y[2])Y = y[0];

	cout << X << " " << Y << endl;
	return 0;
}
*/