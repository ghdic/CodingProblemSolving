/*
https://www.acmicpc.net/problem/2754

&Title
학점계산
&Question
어떤 사람의 C언어 성적이 주어졌을 때, 평점은 몇 점인지 출력하는 프로그램을 작성하시오.

A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7
&Input
첫째 줄에 C언어 성적이 주어진다. 성적은 문제에서 설명한 13가지 중 하나이다.
&Output
첫째 줄에 C언어 평점을 출력한다.
&Example
-input
A0
-output
4.0
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string N;
	cin >> N;
	cout.setf(ios::fixed);
	cout.precision(1);
	if (!N.compare("A+"))cout << 4.3 << endl;
	else if (!N.compare("A0"))cout << 4.0 << endl;
	else if (!N.compare("A-"))cout << 3.7 << endl;
	else if (!N.compare("B+"))cout << 3.3 << endl;
	else if (!N.compare("B0"))cout << 3.0 << endl;
	else if (!N.compare("B-"))cout << 2.7 << endl;
	else if (!N.compare("C+"))cout << 2.3 << endl;
	else if (!N.compare("C0"))cout << 2.0 << endl;
	else if (!N.compare("C-"))cout << 1.7 << endl;
	else if (!N.compare("D+"))cout << 1.3 << endl;
	else if (!N.compare("D0"))cout << 1.0 << endl;
	else if (!N.compare("D-"))cout << 0.7 << endl;
	else if (!N.compare("F"))cout << 0.0 << endl;
	
	return 0;
}
*/